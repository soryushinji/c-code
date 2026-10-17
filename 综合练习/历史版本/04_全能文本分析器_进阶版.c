/* ============================================================================
   第 4 题　全能文本分析器　【进阶版】
   ----------------------------------------------------------------------------
   和基础版的区别只有一个：

     基础版：  while ((ch = getchar()) != EOF && ch != '#')   ← # 或 EOF 都能结束
     进阶版：  while ((ch = getchar()) != EOF)                ← 只认 EOF

   为什么"只认 EOF"反而是进阶？
     因为它能配合【命令行重定向】从文件读数据：

        程序名 < test.txt

     从文件读时，文件末尾自动就是 EOF，不用手打 Ctrl+Z —— 这才是
     EOF 最自然的用法。从键盘读时才需要手动制造 EOF（Ctrl+Z 回车）。

   编译：
       gcc -Wall -Wextra -o q4 04_全能文本分析器_进阶版.c

   运行（三种方式都行）：
       q4                              ← 键盘输入，末尾按 Ctrl+Z 再回车
       q4 < test.txt                   ← 从文件读（cmd 里这样写）
       Get-Content test.txt | .\q4     ← PowerShell 里这样写（见下方说明）
   ============================================================================ */
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int totalnum    = 0;
    int digits      = 0;
    int blank       = 0;
    int punctuation = 0;
    int others      = 0;
    int dalpha      = 0;
    int xalpha      = 0;
    int yalpha      = 0;

    int count[128] = {0};       /* 计数数组：下标就是 ASCII 码 */
    int ch;

    printf("请输入文本:  ");     /* 从文件读时这行也照常打到屏幕上 */

    /* ────────────────────────────────────────────────────────────────────
       ★ 进阶版的核心：只认 EOF
          getchar() 只管从"标准输入"读一个字节，
          它【完全不知道】标准输入是键盘还是文件 —— 这正是重定向能生效的原因。
       ──────────────────────────────────────────────────────────────────── */
    while ((ch = getchar()) != EOF)
    {
        totalnum++;

        if (isalpha(ch))
        {
            if (isupper(ch))
            {
                dalpha++;
                if (ch == 'A' || ch == 'E' || ch == 'I' ||
                    ch == 'O' || ch == 'U')
                    yalpha++;
            }
            else
            {
                xalpha++;
                if (ch == 'a' || ch == 'e' || ch == 'i' ||
                    ch == 'o' || ch == 'u')
                    yalpha++;
            }
        }
        else if (isdigit(ch))  digits++;
        else if (isspace(ch))  blank++;
        else if (ispunct(ch))  punctuation++;
        else                   others++;

        if (ch >= 33 && ch <= 126)
            count[ch]++;
    }

    double alphacent = 0.0, digitscent = 0.0, blankcent = 0.0;
    double punctuationcent = 0.0, otherscent = 0.0;
    if (totalnum > 0)
    {
        alphacent       = (double)(dalpha + xalpha) / totalnum * 100;
        digitscent      = (double)digits            / totalnum * 100;
        blankcent       = (double)blank             / totalnum * 100;
        punctuationcent = (double)punctuation       / totalnum * 100;
        otherscent      = (double)others            / totalnum * 100;
    }

    printf("\n总字符数: %d 个\n", totalnum);
    printf("字母: %d 个(%.1f%%)\n", dalpha + xalpha, alphacent);
    printf("数字: %d 个(%.1f%%)\n", digits, digitscent);
    printf("空白: %d 个(%.1f%%)\n", blank, blankcent);
    printf("标点: %d 个(%.1f%%)\n", punctuation, punctuationcent);
    printf("其他: %d 个(%.1f%%)\n", others, otherscent);
    printf("\n");
    printf("大写字母: %d 个    小写字母: %d 个\n", dalpha, xalpha);
    printf("元音字母: %d 个\n", yalpha);

    int maxCount = 0, maxChar = 0;
    for (int c = 33; c <= 126; c++)
    {
        if (count[c] > maxCount)
        {
            maxCount = count[c];
            maxChar  = c;
        }
    }
    if (maxCount == 0)
        printf("出现最多的字符：没有可打印字符\n");
    else
    {
        printf("出现最多的字符：'%c'（%d 次）\n", maxChar, maxCount);
        printf("（规则：只统计 ASCII 33~126，并列时取 ASCII 码最小的）\n");
    }

    const char *label[5] = {"字母", "数字", "空白", "标点", "其他"};
    double cent[5] = {alphacent, digitscent, blankcent,
                      punctuationcent, otherscent};
    int idx[5] = {0, 1, 2, 3, 4};

    for (int j = 0; j < 5; j++)
    {
        int m = j;
        for (int k = j + 1; k < 5; k++)
            if (cent[k] > cent[m]) m = k;
        if (m != j)
        {
            double t = cent[j]; cent[j] = cent[m]; cent[m] = t;
            int    u = idx[j];  idx[j]  = idx[m];  idx[m]  = u;
        }
    }

    printf("\n占比柱状图（每 2%% 一格）：\n");
    int maxLen = (int)(cent[0] / 2);
    for (int j = 0; j < 5; j++)
    {
        int barLen = (int)(cent[j] / 2);
        printf("%s  |", label[idx[j]]);
        for (int k = 0; k < barLen;  k++) printf("#");
        for (int k = barLen; k < maxLen; k++) printf(" ");
        printf("  %.1f%%\n", cent[j]);
    }

    return 0;
}
