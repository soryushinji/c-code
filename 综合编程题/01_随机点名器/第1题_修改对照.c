/* ============================================================================
   第 1 题　数位分析器　—— 你的原文 vs 修正版
   --------------------------------------------------------------------------
   上半部分 = 你原来写的（用 #if 0 包住，不参与编译，可随意对照）
   下半部分 = 修正后的版本（可直接编译运行）

   编译：gcc -Wall -Wextra -o q1 第1题_修改对照.c
   --------------------------------------------------------------------------
题目要求：
     ① 位数（0 的处理要写明约定）  ② 各位数字之和  ③ 各位数字之积
     ④ 逆序后的新数（丢掉前导零）  ⑤ 最大位 / 最小位  ⑥ 是否回文
     硬性要求：用 % 和 / 逐位处理，不许转成字符串/字符数组；
               输入负数或非数字要重新输入，不消耗任何"机会"。
   你那版的得分：约 7 / 10
   修正要点：
     ★ 致命：while(... ch != 'EOF') 里 'EOF' 是【多字符常量】(4542278)，
       永远不等于 ch → 读到输入末尾时死循环。
       正确的是 EOF（不带引号）。
     · 0 的约定写进注释（位数算 1 位、之积是 0、最大最小位都是 0）
     · 拆位时用副本 temp，别把 num 本身改掉（回文判断还要用）
   ============================================================================ */

#if 0
/* #################### 你原来的代码 #################### */
/* ==================== 你原来的代码开始 ==================== */
/* 第 1 题（你的原文，照抄） */
printf("请输入一个非负整数:");
long long int num;
int i = 0;
int j = 0;
int max = 0;
int min  = 9;
int he = 0;
int ch;
long long int ji = 1;
long long int num1 = 0;
long long int num2 = 0;
long long int num3 = 0;
start:
if((scanf(" %lld",&num)) != 1 || num < 0)
{
    printf("请输入一个非负整数:");
    while((ch = getchar()) != '\n' && ch != 'EOF')
        continue;
    if (ch == EOF)
    {                        /* 输入真的结束了 */
        printf("\n输入结束,程序退出。\n");
        return 0;
    }
    goto start;
}
else if(num > 0)
{
num3 = num;
num1 = num;
while(num1 >= 1)
{
    num1 /= 10;
    j++;
}
while(num >= 1)
{
    i = num % 10;
    he += i;
    ji *= i;
    if(i <= min)
    {
        min = i;
    }
    if (i >= max)
    {
        max = i;
    }
    num2 += i;
    num2 *= 10;;
    num /= 10;
}
}
else
{
    j = 1;
    ji = 0;
    min = 0;
}
num2 /= 10;
printf("位数:%d\n",j);
printf("各个位数之和:%d\n",he);
printf("各个位数之积:%lld\n",ji);
printf("把这个数逆序后得到的新数:%lld\n",num2);
printf("最大位:%d    最小位:%d\n",max,min);
if(num2 == num3)
{
    printf("是否回文：是");
}
else
{
    printf("是否回文：否");
}
/* ==================== 你原来的代码结束 ==================== */
/* #################### 你原来的代码 结束 #################### */
#endif

/* #################### 修正后的版本 #################### */
/* ==================== 修正版开始 ==================== */
#include <stdio.h>

int main(void)
{
    long long num = 0;
    int ch;

    /* ── ① 输入非负整数：非法就重输，不消耗任何"机会" ── */
    for (;;)
    {
        printf("请输入一个非负整数:");

        if (scanf("%lld", &num) != 1 || num < 0)
        {
            printf("  输入不合法（必须是非负整数），请重新输入。\n");

            /* ★ 关键修正：EOF 是宏，不是 'EOF'（单引号多字符常量）
                 你原来写 ch != 'EOF' —— 'EOF' 的值是 4542278，
                 永远不等于 ch，所以读到输入末尾时这个循环出不来。   */
            while ((ch = getchar()) != '\n' && ch != EOF)
                continue;

            if (ch == EOF)
            {
                printf("\n输入结束，程序退出。\n");
                return 0;
            }
            continue;
        }

        /* 正常读到一个数，把这一行剩下的吃掉（含换行） */
        while ((ch = getchar()) != '\n' && ch != EOF)
            continue;
        break;
    }

    /* ── ② 逐位处理：只用 % 和 /，不转字符串 ── */
    long long temp   = num;      /* num 要留着最后判断回文，用副本拆位 */
    long long rev    = 0;        /* 逆序数 */
    long long product = 1;       /* 各位之积 */
    int digits   = 0;            /* 位数 */
    int sum      = 0;            /* 各位之和 */
    int maxDigit = 0;
    int minDigit = 9;

    if (num == 0)
    {
        /* ★ 约定（题目要求写明）：0 视为 1 位数；
           各位之和 0、各位之积 0、最大位与最小位都是 0；
           逆序仍是 0；0 是回文数。 */
        digits   = 1;
        sum      = 0;
        product  = 0;
        maxDigit = 0;
        minDigit = 0;
        rev      = 0;
    }
    else
    {
        while (temp > 0)
        {
            int d = (int)(temp % 10);   /* 取出末位 */
            sum     += d;
            product *= d;
            if (d > maxDigit) maxDigit = d;
            if (d < minDigit) minDigit = d;
            rev = rev * 10 + d;         /* ★ 逆序：前导 0 自动消失（120 → 21） */
            digits++;
            temp /= 10;                 /* 去掉末位 */
        }
    }

    /* ⚠ 关于 %lld 的警告（不影响运行，输出完全正确）
       MinGW（你用的 gcc）的 printf 不识别 %l，会报
           warning: unknown conversion type character 'l' in format
           warning: too many arguments for format
       这只是编译器的格式串检查器不认识，实际输出【完全正确】。
         · 标准写法是 %lld —— Linux / macOS 下必须用它
         · 想做到 Windows 下零警告，可以把下面两处 %lld 改成 %I64d
       （我实测：%lld 有警告但输出对；%I64d 零警告且输出一样）       */
    printf("位数:%d\n", digits);
    printf("各个位数之和:%d\n", sum);
    printf("各个位数之积:%lld\n", product);   /* 注：位数很多时之积可能超出范围 */
    printf("把这个数逆序后得到的新数:%lld\n", rev);
    printf("最大位:%d    最小位:%d\n", maxDigit, minDigit);

    if (rev == num)
        printf("是否回文：是\n");
    else
        printf("是否回文：否\n");

    return 0;
}
/* ==================== 修正版结束 ==================== */
