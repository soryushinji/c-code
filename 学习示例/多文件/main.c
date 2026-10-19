/* ============================================================
   main.c  ——  主程序，include 头文件就能调用别的文件里的函数
   ============================================================ */

#include <stdio.h>
#include "calc.h"           /* ← 双引号：先找当前目录；尖括号：只找系统目录 */

int main(void)
{
    int a = 12, b = 4;

    printf("=== 多文件示例 ===\n");
    printf("%d + %d = %d\n", a, b, add(a, b));
    printf("%d - %d = %d\n", a, b, sub(a, b));
    printf("%d * %d = %d\n", a, b, mul(a, b));
    printf("%d / %d = %d\n", a, b, divide(a, b));
    printf("\n一共调用了 %d 次计算函数\n", g_count);
    printf("MAX_A = %d\n", MAX_A);

    return 0;
}
