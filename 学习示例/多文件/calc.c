/* ============================================================
   calc.c  ——  【定义】放在 .c 文件
   写函数体（真正干活的代码）
   ============================================================ */

#include "calc.h"           /* ← 包含自己的头文件，保证声明和定义一致 */

/* ---- 全局变量【定义】：不带 extern，并且给了初值 ---- */
int g_count = 0;

/* ---- 函数【定义】：带函数体 ---- */
int add(int a, int b)
{
    g_count++;
    return a + b;
}

int sub(int a, int b)
{
    g_count++;
    return a - b;
}

int mul(int a, int b)
{
    g_count++;
    return a * b;
}

int divide(int a, int b)
{
    g_count++;
    if (b == 0)
    {
        return 0;               /* 简单处理：除零返回 0 */
    }
    return a / b;
}
