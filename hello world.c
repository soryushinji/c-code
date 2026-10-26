
    // int age;
    // printf("please enter your age:");
    // scanf("%d",&age);
    // int days = age * 365;
    // printf("You have been alive for %d days.\n",days);

    // int ch;                              /* ⚠ 必须 int，不能 char */
    // int count = 0;
 
    // printf("随便输入点什么，按 Ctrl+Z 再回车结束（Linux/macOS 按 Ctrl+D）：\n");
 
    // while ((ch = getchar()) != EOF) {    /* 一直读到「文件结尾」 */
    //     putchar(ch);                     /* 原样输出（回显） */
    //     count++;
    // }
    // printf("\n共读了 %d 个字符。\n", count);
    // int num = 0;
    // scanf("%d",&num);
    // if(num == 1)
    // {
    //     printf("num为一");
    // }
    // else  if(num < 2)
    // {
    //     printf("num为一但也小于二");
    // }
    // int ch;
    // ch = getchar();
    // while(ch != EOF)
    // {
    //     if(ch == ' ')
    //     {
    //         continue;
    //     }
    // }
#define _CRT_SECURE_NO_WARNINGS
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <inttypes.h>

#define RECORD_COUNT 1000
#define RECORD_FILE  "records.bin"

/* flags 位语义：bit0=有效，bit1=告警，其余保留 */
#define FLAG_VALID 0x01u
#define FLAG_WARN  0x02u

/*
 * 端序说明：
 * 本程序按本机字节序直接落盘。在小端机（x86/x64）上，
 * uint32_t 0x12345678 写入文件的低地址到高地址字节为：
 *   78 56 34 12
 * 因此 records.bin 只保证在同端序机器上直接可读；
 * 若需跨端序，应逐字段手动序列化/反序列化。
 *
 * 位域说明：
 * 本题不使用 C 语言位域，而用 uint8_t flags + 位掩码模拟位域语义，
 * 因为 C 位域的位序、布局、填充依赖编译器实现。
 * 这里约定：bit0 = 有效，bit1 = 告警。
 *
 * 记录必须定长，且不能包含指针字段，因此可以整块 fwrite/fread。
 * CRC8 覆盖 sizeof(Record) 个字节（包含填充字节）。
 */
typedef struct Record {
    uint16_t id;
    uint32_t ts;
    int16_t  value;
    uint8_t  flags;
} Record;

_Static_assert(sizeof(Record) == 12, "sizeof(Record) must be 12");

/* CRC8：多项式 0x07，初值 0x00，不反射，xorout 0x00 */
static uint8_t crc8(const uint8_t *data, size_t len)
{
    uint8_t crc = 0x00;
    size_t i;
    int bit;

    for (i = 0; i < len; ++i) {
        crc ^= data[i];
        for (bit = 0; bit < 8; ++bit) {
            if (crc & 0x80u) {
                crc = (uint8_t)((crc << 1) ^ 0x07u);
            } else {
                crc = (uint8_t)(crc << 1);
            }
        }
    }
    return crc;
}

static void die(const char *msg)
{
    perror(msg);
    exit(EXIT_FAILURE);
}

/* 写 1000 条记录，同时把原始记录的 CRC8 保存到 expected_crc[] */
static void write_records(const char *path, uint8_t expected_crc[RECORD_COUNT])
{
    FILE *fp = fopen(path, "wb");
    int i;

    if (!fp) {
        die("fopen records.bin for write");
    }

    srand(42);

    for (i = 0; i < RECORD_COUNT; ++i) {
        Record r;
        uint8_t flags = 0;

        /* 清零使填充字节确定，保证 CRC 覆盖整条记录时稳定 */
        memset(&r, 0, sizeof r);

        r.id    = (uint16_t)(i + 1);
        r.ts    = (uint32_t)i;
        r.value = (int16_t)(rand() % 1001 - 500); /* -500 ~ 500 */

        if (rand() & 1) {
            flags |= FLAG_VALID;
        }
        if (rand() & 1) {
            flags |= FLAG_WARN;
        }
        r.flags = flags;

        expected_crc[i] = crc8((const uint8_t *)&r, sizeof r);

        if (fwrite(&r, sizeof r, 1, fp) != 1) {
            fclose(fp);
            die("fwrite");
        }
    }

    if (fclose(fp) != 0) {
        die("fclose after write");
    }
}

/* 把第 record_no 条（1-based）记录中的一个字节改掉 */
static void corrupt_record(const char *path, int record_no)
{
    FILE *fp = fopen(path, "r+b");
    long off;
    Record r;
    unsigned char *p;

    if (!fp) {
        die("fopen records.bin for corrupt");
    }

    off = (long)(record_no - 1) * (long)sizeof(Record);

    if (fseek(fp, off, SEEK_SET) != 0) {
        fclose(fp);
        die("fseek to corrupt record");
    }

    if (fread(&r, sizeof r, 1, fp) != 1) {
        fclose(fp);
        die("fread for corrupt");
    }

    /* 修改 value 字段的第一个字节，确保内容变化且 CRC 改变 */
    p = (unsigned char *)&r;
    p[offsetof(Record, value)] ^= 0x5Au;

    if (fseek(fp, off, SEEK_SET) != 0) {
        fclose(fp);
        die("fseek back to corrupt record");
    }

    if (fwrite(&r, sizeof r, 1, fp) != 1) {
        fclose(fp);
        die("fwrite corrupt record");
    }

    if (fclose(fp) != 0) {
        die("fclose after corrupt");
    }
}

/* 逐条读回、CRC 校验、损坏定位并跳过、统计首末条 */
static void read_records(const char *path,
                         const uint8_t expected_crc[RECORD_COUNT])
{
    FILE *fp = fopen(path, "rb");
    Record r;
    Record first, last;
    int total = 0;
    int ok = 0;
    int bad = 0;
    int bad_indices[RECORD_COUNT];
    int bad_count = 0;
    int have_first = 0;
    int have_prev_ts = 0;
    uint32_t prev_ts = 0;
    int ts_bad = 0;

    if (!fp) {
        die("fopen records.bin for read");
    }

    while (fread(&r, sizeof r, 1, fp) == 1) {
        int idx0 = total; /* 0-based 下标 */
        uint8_t got_crc;

        total++;

        if (!have_first) {
            first = r;
            have_first = 1;
        }
        last = r;

        /* 拓展：ts 非递增检查 */
        if (have_prev_ts && r.ts <= prev_ts) {
            ts_bad++;
            printf("时间戳非递增: #%d (ts=%" PRIu32 " <= prev_ts=%" PRIu32 ")\n",
                   total, r.ts, prev_ts);
        }
        prev_ts = r.ts;
        have_prev_ts = 1;

        /* CRC8 覆盖整条记录，包括填充字节 */
        got_crc = crc8((const uint8_t *)&r, sizeof r);

        if (idx0 < RECORD_COUNT && got_crc == expected_crc[idx0]) {
            ok++;
        } else {
            bad++;
            if (bad_count < RECORD_COUNT) {
                bad_indices[bad_count++] = idx0 + 1; /* 1-based 下标 */
            }
            /* 跳过该条，继续 fread 后续记录 */
            continue;
        }
    }

    if (!feof(fp)) {
        fclose(fp);
        die("fread loop");
    }

    if (fclose(fp) != 0) {
        die("fclose after read");
    }

    printf("读回: 总数 %d，CRC 通过 %d，损坏 %d\n", total, ok, bad);

    if (have_first) {
        printf("首条: id=%u ts=%" PRIu32 " value=%d flags=0x%02X\n",
               (unsigned)first.id,
               first.ts,
               (int)first.value,
               (unsigned)first.flags);
    }

    if (total > 0) {
        printf("末条: id=%u ts=%" PRIu32 " value=%d flags=0x%02X\n",
               (unsigned)last.id,
               last.ts,
               (int)last.value,
               (unsigned)last.flags);
    }

    if (bad_count > 0) {
        int i;
        printf("损坏记录下标:");
        for (i = 0; i < bad_count; ++i) {
            printf(" #%d", bad_indices[i]);
        }
        printf("\n");

        for (i = 0; i < bad_count; ++i) {
            printf("损坏记录: #%d（已跳过，继续读后续）\n", bad_indices[i]);
        }
    } else {
        printf("损坏记录下标: 无\n");
    }

    printf("时间戳非递增计数: %d\n", ts_bad);
}

int main(void)
{
    uint8_t expected_crc[RECORD_COUNT];

    printf("写 %d 条 -> %s (%zu 字节)\n",
           RECORD_COUNT,
           RECORD_FILE,
           (size_t)RECORD_COUNT * sizeof(Record));

    write_records(RECORD_FILE, expected_crc);

    printf("\n正常读回（未损坏）:\n");
    read_records(RECORD_FILE, expected_crc);

    printf("\n注入损坏: 第 500 条\n");
    corrupt_record(RECORD_FILE, 500);

    printf("\n损坏后读回:\n");
    read_records(RECORD_FILE, expected_crc);

    printf("\nsizeof(struct Record) = %zu（_Static_assert 通过）\n",
           sizeof(Record));

    return 0;
}