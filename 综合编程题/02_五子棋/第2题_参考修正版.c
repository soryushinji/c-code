/* 第 2 题 参考修正版：在你的修改版基础上只补「EOF 兜底」+ 命名 + 注释 */
#include <stdio.h>

int main(void)
{
    /* 变量名改成看得出用途的：图案个数 / 总行数 */
    int patternCount = 0;      /* 本次共打印了多少个图案 */
    int totalLines = 0;        /* 本次共打印了多少行   */
    int button = 0;            /* 菜单选择，给初值避免未定义行为 */
    int h = 0;                 /* 高度 */
    int ret;                   /* 专门接 scanf 的返回值 */
    int ch;                    /* 专门接 getchar 的返回值（必须是 int，才能装下 EOF） */

start:
    printf("************************************************************************************************\n");
    printf("输出示例\n");
    printf("1) 直角三角形        2) 等腰三角形\n*                     *\n**                   ***\n***                 *****\n****               *******\n");
    printf("3) 菱形（h=2 时共 3 行）      4) 数字金字塔（h=4）\n  *                             1\n ***                           121\n  *                           12321\n                             1234321\n");
    printf("5) 退出\n");
    printf("************************************************************************************************\n");

start1:
    printf("请选择:");

    /* ── 关键补充①：scanf 返回 EOF 说明「输入真的结束了」，必须退出 ── */
    ret = scanf("%d", &button);
    if (ret == EOF) {
        printf("\n输入结束，程序退出。\n");
        goto end;
    }

    if (ret != 1 || button < 1 || button > 5) {   /* 非法选项 */
        while ((ch = getchar()) != '\n' && ch != EOF) {
            continue;
        }
        printf("无效选项，请重新选择:\n");
        goto start;
    }
    if (button == 5) {                            /* 选 5 退出（必须在合法性判断之后） */
        goto end;
    }

    printf("请输入高度h(1-15):");
start2:
    /* ── 关键补充②：高度这里同样要处理 EOF ── */
    ret = scanf("%d", &h);
    if (ret == EOF) {
        printf("\n输入结束，程序退出。\n");
        goto end;
    }
    if (ret != 1 || h <= 0 || h > 15) {
        printf("高度必须在 1-15 之间，请重新输入:");
        while ((ch = getchar()) != '\n' && ch != EOF) {
            continue;
        }
        goto start2;
    }

    while ((ch = getchar()) != '\n' && ch != EOF) {
        continue;
    }

    switch (button) {
    case 1:                                  /* 直角三角形：第 n 行 n 个星号 */
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= i; j++) {
                printf("*");
            }
            printf("\n");
        }
        patternCount++;
        totalLines += h;
        break;

    case 2:                                  /* 等腰三角形：第 n 行 (h-n) 空格 + (2n-1) 星号 */
        for (int i = 1; i <= h; i++) {
            for (int k = i; k <= h - 1; k++) {
                printf(" ");
            }
            for (int j = 1; j <= 2 * i - 1; j++) {
                printf("*");
            }
            printf("\n");
        }
        patternCount++;
        totalLines += h;
        break;

    case 3:                                  /* 菱形：上半 (h/2)+1 行 + 下半 h/2 行 */
        for (int i = 1; i <= (h / 2) + 1; i++) {
            for (int m = i; m <= (h / 2) + 1; m++) {
                printf(" ");
            }
            for (int j = 1; j <= 2 * i - 1; j++) {
                printf("*");
            }
            printf("\n");
        }
        for (int l = (h / 2); l >= 1; l--) {
            for (int n = l; n <= (h / 2) + 1; n++) {
                printf(" ");
            }
            for (int k = 2 * l - 1; k >= 1; k--) {
                printf("*");
            }
            printf("\n");
        }
        patternCount++;
        /* 实际行数 = (h/2)+1 + h/2，比用奇偶分支判断更直接 */
        totalLines += (h / 2) + 1 + (h / 2);
        break;

    case 4:                                  /* 数字金字塔：第 n 行 1..n 再 n-1..1，共 2n-1 个数字 */
        for (int i = 1; i <= h; i++) {
            for (int k = i; k <= h - 1; k++) {
                printf(" ");
            }
            for (int j = 1; j <= i; j++) {
                printf("%d", j);
            }
            for (int m = i - 1; m >= 1; m--) {
                printf("%d", m);
            }
            printf("\n");
        }
        patternCount++;
        totalLines += h;
        break;

    default:                                 /* 理论上到不了，但写上是好习惯 */
        printf("内部错误：未知选项。\n");
        break;
    }

    goto start1;

end:
    if (patternCount == 0) {
        printf("本次共打印 0 个图案，合计 0 行。再见~~\n");
    } else {
        printf("本次共打印 %d 个图案，合计 %d 行。再见~~\n",
               patternCount, totalLines);
    }
    return 0;
}
