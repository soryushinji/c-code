/* ============================================================================
   第 3 题　安全计算器　—— 你的原文 vs 修正版
   --------------------------------------------------------------------------
   上半部分 = 你原来写的（用 #if 0 包住，不参与编译，可随意对照）
   下半部分 = 修正后的版本（可直接编译运行）

   编译：gcc -Wall -Wextra -o q3 第3题_修改对照.c
   --------------------------------------------------------------------------
题目要求：反复读入「数 运算符 数」，支持 + - * / % 五种运算；
             % 只允许两个整数；除数为 0 要提示且不能崩；输入 q 退出；
             退出时输出成功次数和每种运算各用了几次。
   你那版的得分：约 9.5 / 10（逻辑已全对，21/21 通过）
   修正要点：只做代码整洁化，逻辑一行没改
     · o → firstIsFloat（变量名要能看懂）
     · continue; } 拆成两行
     · switch 补 default 兜底
     · 补关键注释
   ============================================================================ */

#if 0
/* #################### 你原来的代码 #################### */
/* ==================== 你原来的代码开始 ==================== */
/* 第 3 题（你的原文，照抄；这一版实测 21/21 全通过） */
int quit = 0;
int ch;
int num = 0;
int add = 0;
int subtract = 0;
int multiply = 0;
int divide = 0;
int modulo = 0;
while(!quit)
{
    double first = 0;
    char operator;
    double second = 0;
    int neg = 0;
    int digits = 0;
    int decimals = 0;//计算小数部分的位数
    int o = 0;//记录first是不是浮点数
    printf("请输入表达式（如 12.5 * 3,输入 q 退出)\n(支持 +、-、*、/、%% 五种运算):");
//允许一开始有空格
    do
    {
        ch = getchar();
    } while (ch == ' ' || ch == '\t');

    if(ch == EOF)
    {
        quit = 1;
        continue;
    }
    else if(ch == 'q' || ch == 'Q')
    {
        quit = 1;
        continue;
    }
    else//非q非EOF
    {
        /*带+-号的部分*/
        if(ch == '+' || ch == '-')
        {
            neg = (ch == '-');
            ch = getchar();
        }
        /*整数部分*/
        while(ch >= '0' && ch <= '9')
        {
            first = first * 10 + (ch - '0');
            digits++;//计算位数
            ch = getchar();
        }
        /*小数部分*/
        if(ch == '.')
        {
            ch = getchar();
            while(ch >= '0' && ch <= '9')
            {
                first = first * 10 + (ch - '0');
                digits++;
                decimals++;
                ch = getchar();
            } 
        }
    }//条件1结束
//计算first的值
for(int i = 1;i <= decimals;i++)
{
    first /= 10;
}
//加+-号
if(neg)
{
    first = -first;
}
//判断是否输入有效的数字
if(digits == 0)
{
    printf("错误：第一个数格式不正确。\n");
    while (ch != '\n' && ch != EOF) ch = getchar();
    continue;  
}
else
{
    //第一个数字之后
    //如果输入完第一个数字之后输入abc或者,.之类非空格字符 12.3+也不行，必须至少空一格
    if(ch != ' ')
    {
        printf("错误：数字和运算符之间需要一个空格。\n");
        while (ch != '\n' && ch != EOF) ch = getchar();
        continue; 
    }
    do
    {
        ch = getchar();
    } while (ch == ' ' || ch == '\t');//允许空格存在
}
//接下来读运算符
//如果输入第一个数字+空格之后输入其他符号
if(ch != '+' && ch != '-' && ch != '*' && ch != '/' && ch != '%')
{
    printf("错误：未知运算符，请输入 + - * / %%\n");
    while (ch != '\n' && ch != EOF) ch = getchar();
    continue; }
else if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%')
{
    operator = (char)ch;
}
//也同样允许有空格
do
{
    ch = getchar();
} while (ch == ' ' || ch == '\t');
//输入第二个数
neg = 0;
digits = 0;
if(decimals != 0)
{
    o++;
}
decimals = 0;
//从这一行到1588行与第一个数类似**************************************************************************************
    if(ch == EOF)
    {
        quit = 1;
        continue;
    }
    else if(ch == 'q' || ch == 'Q')
    {
        quit = 1;
        continue;
    }
    else//非q非EOF
    {
        /*带+-号的部分*/
        if(ch == '+' || ch == '-')
        {
            neg = (ch == '-');
            ch = getchar();
        }
        /*整数部分*/
        while(ch >= '0' && ch <= '9')
        {
            second = second * 10 + (ch - '0');
            digits++;//计算位数
            ch = getchar();
        }
        /*小数部分*/
        if(ch == '.')
        {
            ch = getchar();
            while(ch >= '0' && ch <= '9')
            {
                second = second * 10 + (ch - '0');
                digits++;
                decimals++;
                ch = getchar();
            } 
        }
    }//条件2结束
//计算second的值
for(int i = 1;i <= decimals;i++)
{
    second /= 10;
}
//加+-号
if(neg)
{
    second = -second;
}
//判断是否输入有效的数字
if(digits == 0)
{
        printf("错误：第二个数格式不正确。\n");
        while (ch != '\n' && ch != EOF) ch = getchar();
        continue;  
}
//从1532行到这一行与第一个数类似**************************************************************************************
else
{
    //第二个数字之后
    //如果输入完第二个数字之后输入除了enter之外的任何内容
    while (ch == ' ' || ch == '\t')//允许输入空格
    ch = getchar();
    if (ch != '\n' && ch != EOF)      /* ← 还有别的东西 = 垃圾 */
    {
        printf("错误：表达式末尾有多余内容。\n");
        while (ch != '\n' && ch != EOF) ch = getchar();
        continue;    
    }
}
if(operator == '/' && second == 0)
{
        printf("错误：除数不能为 0。\n");             /* ★ 专门的文案 */
        continue;                                   /* 没有垃圾要清 */
}
else if(operator == '%' && (second == 0 || o == 1 || decimals != 0))
{
        printf("错误：%% 只支持两个整数，且除数不能为 0。\n");   /* ★ */
        continue;
}
    switch(operator)
    {
        case '+':
            printf("= %f\n",first + second);
            add++;
            break;
        case '-':
            printf("= %f\n",first - second);
            subtract++;
            break;
        case '*':
            printf("= %f\n",first * second);
            multiply++;
            break;
        case '/':
            printf("= %f\n",first / second);
            divide++;
            break;
        case '%':
            printf("= %d\n",(int)first % (int)second);
            modulo++;
            break;

    }
num++;
}
printf("本次共成功计算 %d 次:\n+ : %d 次    - : %d 次    * : %d 次    / : %d 次    %% : %d 次\n再见~~",num,add,subtract,multiply,divide,modulo);
/* ==================== 你原来的代码结束 ==================== */
/* #################### 你原来的代码 结束 #################### */
#endif

/* #################### 修正后的版本 #################### */
/* ==================== 修正版开始 ====================
   说明：你的这一版**逻辑已经全对**（实测 21/21 全通过，5 条验收标准全过）。
        所以下面只做"代码整洁化"，逻辑一行没改：
          ① o  → firstIsFloat （变量名要能看懂）
          ② continue; }        → 拆成两行
          ③ switch 补 default: （好习惯，以后逻辑改了能立刻发现）
          ④ 补了几处关键注释
   ==================================================== */
#include <stdio.h>

int main(void)
{
    /* ── 统计计数器：跨轮累加，所以放在循环【外面】 ── */
    int quit       = 0;
    int num        = 0;   /* 成功计算总次数 */
    int add        = 0;
    int subtract   = 0;
    int multiply   = 0;
    int divide     = 0;
    int modulo     = 0;

    int ch;

    while (!quit)
    {
        /* ── 每轮都要重置的变量：放在循环【里面】 ── */
        double first  = 0;
        double second = 0;
        char   op     = 0;
        int    neg    = 0;   /* 当前这个数是不是负数 */
        int    digits = 0;   /* 读到了几位数字（0 表示一个都没读到） */
        int    decimals = 0; /* 小数部分有几位 */
        int    firstIsFloat = 0;  /* 原 o：记下"第一个数是不是小数" */

        printf("请输入表达式（如 12.5 * 3，输入 q 退出）\n"
               "(支持 + - * / %% 五种运算):");

        /* ── ① 跳过前导空白（条件是 ch，绝不在这里再调 getchar）── */
        do
        {
            ch = getchar();
        } while (ch == ' ' || ch == '\t');

        if (ch == EOF)
        {
            quit = 1;
            continue;                 /* ★ 立刻跳出本轮，别再往下跑 */
        }
        if (ch == 'q' || ch == 'Q')
        {
            quit = 1;
            continue;                 /* ★ 同上 */
        }

        /* ── ② 读第一个数 ── */
        if (ch == '+' || ch == '-')
        {
            neg = (ch == '-');
            ch = getchar();
        }
        while (ch >= '0' && ch <= '9')          /* 整数部分 */
        {
            first = first * 10 + (ch - '0');
            digits++;
            ch = getchar();
        }
        if (ch == '.')                          /* 小数部分 */
        {
            ch = getchar();
            while (ch >= '0' && ch <= '9')
            {
                first = first * 10 + (ch - '0');  /* 先当整数累积 */
                digits++;
                decimals++;
                ch = getchar();
            }
        }
        for (int k = 1; k <= decimals; k++)      /* 再统一缩小 */
            first /= 10;
        if (neg)
            first = -first;

        /* ── ③ 校验第一个数 ── */
        if (digits == 0)
        {
            printf("错误：第一个数格式不正确。\n");
            while (ch != '\n' && ch != EOF) ch = getchar();
            continue;
        }
        if (ch != ' ')                    /* 这一版要求数后必须跟一个空格 */
        {
            printf("错误：数字和运算符之间需要一个空格。\n");
            while (ch != '\n' && ch != EOF) ch = getchar();
            continue;
        }
        do
        {
            ch = getchar();
        } while (ch == ' ' || ch == '\t');

        /* ── ④ 读运算符 ── */
        if (ch != '+' && ch != '-' && ch != '*' && ch != '/' && ch != '%')
        {
            printf("错误：未知运算符，请输入 + - * / %%\n");
            while (ch != '\n' && ch != EOF) ch = getchar();
            continue;
        }
        op = (char)ch;

        /* ── ⑤ 读第二个数（和第一个数完全一样的逻辑）── */
        do
        {
            ch = getchar();
        } while (ch == ' ' || ch == '\t');

        neg    = 0;
        digits = 0;
        if (decimals != 0)
            firstIsFloat = 1;             /* 第一个数是小数 → % 不能用 */
        decimals = 0;

        if (ch == EOF)
        {
            quit = 1;
            continue;
        }
        if (ch == 'q' || ch == 'Q')
        {
            quit = 1;
            continue;
        }

        if (ch == '+' || ch == '-')
        {
            neg = (ch == '-');
            ch = getchar();
        }
        while (ch >= '0' && ch <= '9')
        {
            second = second * 10 + (ch - '0');
            digits++;
            ch = getchar();
        }
        if (ch == '.')
        {
            ch = getchar();
            while (ch >= '0' && ch <= '9')
            {
                second = second * 10 + (ch - '0');
                digits++;
                decimals++;
                ch = getchar();
            }
        }
        for (int k = 1; k <= decimals; k++)
            second /= 10;
        if (neg)
            second = -second;

        /* ── ⑥ 校验第二个数 ── */
        if (digits == 0)
        {
            printf("错误：第二个数格式不正确。\n");
            while (ch != '\n' && ch != EOF) ch = getchar();
            continue;
        }
        while (ch == ' ' || ch == '\t')
            ch = getchar();
        if (ch != '\n' && ch != EOF)      /* 行尾还有别的东西 = 垃圾 */
        {
            printf("错误：表达式末尾有多余内容。\n");
            while (ch != '\n' && ch != EOF) ch = getchar();
            continue;
        }

        /* ── ⑦ 除零 / 取模的额外校验 ── */
        if (op == '/' && second == 0)
        {
            printf("错误：除数不能为 0。\n");
            continue;                     /* 没有垃圾要清 */
        }
        if (op == '%' && (second == 0 || firstIsFloat || decimals != 0))
        {
            printf("错误：%% 只支持两个整数，且除数不能为 0。\n");
            continue;
        }

        /* ── ⑧ 计算并输出 ── */
        switch (op)
        {
            case '+': printf("= %f\n", first + second); add++;      break;
            case '-': printf("= %f\n", first - second); subtract++; break;
            case '*': printf("= %f\n", first * second); multiply++; break;
            case '/': printf("= %f\n", first / second); divide++;   break;
            case '%': printf("= %d\n", (int)first % (int)second); modulo++; break;
            default:                                            /* ★ 兜底 */
                printf("内部错误：未知运算符\n");
                continue;                 /* 不认识就不计入成功次数 */
        }
        num++;
    }

    printf("本次共成功计算 %d 次:\n"
           "+ : %d 次    - : %d 次    * : %d 次    / : %d 次    %% : %d 次\n再见~~",
           num, add, subtract, multiply, divide, modulo);

    return 0;
}
/* ==================== 修正版结束 ==================== */
