/* ============================================================================
   第 2 题　图案打印机（菜单驱动）　—— 你的原文 vs 修正版
   --------------------------------------------------------------------------
   上半部分 = 你原来写的（用 #if 0 包住，不参与编译，可随意对照）
   下半部分 = 修正后的版本（可直接编译运行）

   编译：gcc -Wall -Wextra -o q2 第2题_修改对照.c
   --------------------------------------------------------------------------
题目要求：菜单选择 1~4 种图案 + 5 退出，每种读高度 h(1-15)；
             打印后回到菜单；退出时统计共打印几个图案、合计几行。
   你那版的得分：约 6 / 10（初版）
   修正要点：
     ★ while(... ch != 'EOF') 同样的问题（死循环）
     ★ goto 满天飞 → 改成 while(!quit) + continue/break
     ★ 菱形的总行数：h 为偶数时是 h+1 行（上半 h/2+1 + 下半 h/2），
       你写的是 num2 += h-1，偶数时会少算
   ============================================================================ */

#if 0
/* #################### 你原来的代码 #################### */
#include <stdio.h>
int main()
{
int button;
int ch;
int h;
int num1 = 0;
int num2 = 0;
printf("************************************************************************************************\n");
printf("输出示例\n");
printf("1) 直角三角形        2) 等腰三角形\n*                     *\n**                   ***\n***                 *****\n****               *******                      ← 等腰三角形共 4 行，第 n 行有 2n-1 个 *\n");
printf("3) 菱形（h=2 时共 3 行）      4) 数字金字塔（h=4）\n  *                             1\n ***                           121\n  *                           12321\n                             1234321\n");
printf("5) 退出");
printf("************************************************************************************************\n");
start1:
printf("请选择:");
start:
if((scanf("%d",&button)) != 1 || button <= 0 || button == 5 || button >5)
{
    if(button == 5)
    {
        goto end;
    }
    printf("无效选项，请重新选择:");
    while((ch = getchar()) != '\n' && ch != 'EOF')
    {
    continue;
    }
    goto start;
}
else
{
    printf("请输入高度h(1-15):");
    start2:
    if((scanf("%d",&h)) != 1 || h <= 0 || h > 15)
    {
        printf("无效选项，请重新选择:");
        while((ch = getchar()) != '\n' && ch != 'EOF')
        {
        continue;
        }
        goto start2;
    }
    else
    {
        while((ch = getchar()) != '\n' && ch != 'EOF')
        {
        continue;
        }
        switch(button)
        {
        case 1:
            for(int i = 1;i <= h;i++)
            {
                for(int j = 1;j <= i;j++)
                {
                    printf("*");
                }
                printf("\n");
            }
            num1++;
            num2 += h;
            break;
        case 2:
            for(int i = 1;i <= h;i++)
            {
                for(int k = i;k <= h - 1;k++)
                {
                    printf(" ");
                }
                for(int j = 1;j <= 2 * i - 1;j++)
                {
                    printf("*");
                }
                printf("\n");
            }
            num1++;
            num2 += h;
            break;
        case 3:
            for(int i = 1;i <= (h / 2) + 1;i++)
            {
                for(int m = i;m <= (h / 2) + 1;m++)
                {
                    printf(" ");
                }
                for(int j = 1;j <= 2 * i - 1;j++)
                {
                    printf("*");
                }
                printf("\n");
            }
            for(int l = (h / 2);l >= 1;l--)
            {
                for(int n = l;n <= (h / 2) + 1;n++)
                {
                    printf(" ");
                }
                for(int k = 2 * l - 1;k >= 1;k--)
                {
                    printf("*");
                }
                printf("\n");
            }
            num1++;
            num2 += h - 1;
            break;
        case 4:
            for(int i = 1;i <= h;i++)
            {
                for(int k = i;k <= h - 1;k++)
                {
                    printf(" ");
                }
                for(int j = 1;j <= i;j++)
                {
                    printf("%d",j);
                }
                for(int m = i - 1;m >= 1;m--)
                {
                        printf("%d",m);
                }
                printf("\n");
            }
            num1++;
            num2 += h;
            break;
        }






    }
    
    
}
goto start1;
end:
if(num1 == 0)
{
printf("本次共打印 0 个图案，合计 0 行。再见~~\n");
}
else
{
printf("本次共打印 %d 个图案，合计 %d 行。再见~~\n",num1,num2);
}
return 0;
}
/* #################### 你原来的代码 结束 #################### */
#endif

/* #################### 修正后的版本 #################### */
/* ============================================================================
   第 2 题　「只用前八章知识」版
   ----------------------------------------------------------------------------
   约束：不使用自己定义的函数、不使用指针、不使用数组（字符串以外的）。
   只用：printf / getchar / 运算符 / while / if / switch / continue / break
         / 标志变量 / EOF                       （全部出自第 3~8 章）

   三个要点：
   ① 不用函数 → 用「一个循环 + need 标记」把「等菜单选择」和「等高度」
      合并到同一处，避免把读输入的代码写两遍。
   ② 不用指针 → 放弃 strtol，改用 getchar() **逐字符**读入并当场校验。
   ③ 不用 goto  → while(!quit) + continue/break；输入结束用 quit 标志退出。
   ============================================================================ */

#include <stdio.h>

int main(void)
{
    int patternCount = 0;        /* 共打印了多少个图案 */
    int totalLines = 0;          /* 共打印了多少行     */
    int button = 0;              /* 菜单选择 */
    int h = 0;                   /* 高度     */
    int need = 0;                /* 0 = 正在等菜单选择；1 = 正在等高度 */
    int quit = 0;                /* 输入结束标志（标志变量，第 7 章） */

    /* ---------- 启动时展示一次示例 ---------- */
    printf("================ 输出示例 ================\n");
    printf("1) 直角三角形      2) 等腰三角形\n");
    printf("*                     *\n");
    printf("**                   ***\n");
    printf("***                 *****\n");
    printf("****               *******\n");
    printf("3) 菱形（h=2 共 3 行）   4) 数字金字塔（h=4）\n");
    printf("  *                       1\n");
    printf(" ***                     121\n");
    printf("  *                     12321\n");
    printf("                       1234321\n");
    printf("==========================================\n");

    while (!quit) {                       /* ← 主循环：替代 goto */
        int value = 0;                    /* 本次读到的数值 */
        int state = 1;                    /* 1=成功  0=非法  2=输入结束 */
        int digits = 0;                   /* 读到了几位数字 */
        int neg = 0;                      /* 是不是负数 */
        int ch;                           /* 必须是 int，才能装下 EOF */

        /* ---------- ① 提示（由 need 决定问什么） ---------- */
        if (need == 0) {
            printf("------------------------------------------\n");
            printf("  1) 直角三角形     2) 等腰三角形\n");
            printf("  3) 菱形           4) 数字金字塔\n");
            printf("  5) 退出\n");
            printf("------------------------------------------\n");
            printf("请选择:");
        } else {
            printf("请输入高度h(1-15):");
        }

        /* ---------- ② 逐字符严格读一个整数 ----------
           不使用任何函数和指针，只用 getchar() 一个字符一个字符地读，
           读到什么就当场判断什么。                              */
        do {                              /* 跳过前导空白（不含换行） */
            ch = getchar();
        } while (ch == ' ' || ch == '\t');

        if (ch == EOF) {
            state = 2;                    /* 输入结束了 */
        } else {
            if (ch == '+' || ch == '-') { /* 允许正负号 */
                neg = (ch == '-');
                ch = getchar();
            }

            while (ch >= '0' && ch <= '9') {   /* 收集数字 */
                if (digits < 9)                /* 只收 9 位，避免 int 溢出 */
                    value = value * 10 + (ch - '0');
                digits++;
                ch = getchar();
            }

            while (ch == ' ' || ch == '\t')    /* 允许数字后面跟空白 */
                ch = getchar();

            /* 关键校验：必须读到了数字，且后面除了换行（或输入结束）
               不能再有任何别的东西。1.5 / 1abc / 1e2 都死在这里。 */
            if (digits == 0 || digits > 9 || (ch != '\n' && ch != EOF)) {
                state = 0;                     /* 非法 */
                while (ch != '\n' && ch != EOF) /* 丢掉本行剩余部分 */
                    ch = getchar();
            } else if (neg) {
                value = -value;
            }
        }

        /* ---------- ③ 按状态决定下一步 ---------- */
        if (state == 2) {
            quit = 1;                          /* 输入结束 → 退出主循环 */

        } else if (need == 0) {                /* 正在处理菜单选择 */
            if (state == 0 || value < 1 || value > 5) {
                printf("无效选项，请重新选择。\n");
            } else if (value == 5) {
                quit = 1;                      /* 选 5 → 退出 */
            } else {
                button = value;                /* 记下选择 */
                need = 1;                      /* 下次循环改问高度 */
            }

        } else {                               /* 正在处理高度 */
            if (state == 0 || value < 1 || value > 15) {
                printf("高度必须是 1 到 15 之间的整数，请重新输入。\n");
            } else {
                h = value;

                /* ---------- 打印图案（嵌套循环，第 6 章） ---------- */
                switch (button) {
                case 1:                        /* 直角三角形：第 n 行 n 个星号 */
                    for (int i = 1; i <= h; i++) {
                        for (int j = 1; j <= i; j++)
                            printf("*");
                        printf("\n");
                    }
                    totalLines += h;
                    break;

                case 2:                        /* 等腰三角形：第 n 行 (h-n) 空格 + (2n-1) 星号 */
                    for (int i = 1; i <= h; i++) {
                        for (int k = i; k <= h - 1; k++)
                            printf(" ");
                        for (int j = 1; j <= 2 * i - 1; j++)
                            printf("*");
                        printf("\n");
                    }
                    totalLines += h;
                    break;

                case 3:                        /* 菱形：上半 (h/2)+1 行 + 下半 h/2 行 */
                    for (int i = 1; i <= (h / 2) + 1; i++) {
                        for (int m = i; m <= (h / 2) + 1; m++)
                            printf(" ");
                        for (int j = 1; j <= 2 * i - 1; j++)
                            printf("*");
                        printf("\n");
                    }
                    for (int l = (h / 2); l >= 1; l--) {
                        for (int n = l; n <= (h / 2) + 1; n++)
                            printf(" ");
                        for (int k = 2 * l - 1; k >= 1; k--)
                            printf("*");
                        printf("\n");
                    }
                    totalLines += (h / 2) + 1 + (h / 2);
                    break;

                case 4:                        /* 数字金字塔：第 n 行 1..n 再 n-1..1 */
                    for (int i = 1; i <= h; i++) {
                        for (int k = i; k <= h - 1; k++)
                            printf(" ");
                        for (int j = 1; j <= i; j++)
                            printf("%d", j);
                        for (int m = i - 1; m >= 1; m--)
                            printf("%d", m);
                        printf("\n");
                    }
                    totalLines += h;
                    break;
                }

                patternCount++;
                need = 0;                      /* 回到菜单 */
            }
        }
    }

    printf("本次共打印 %d 个图案，合计 %d 行。再见~~\n", patternCount, totalLines);
    return 0;
}
