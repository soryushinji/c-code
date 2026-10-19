#include <stdio.h>
/* ✗ 忘了 #include "calc.h" */
int main(void)
{
    printf("%d\n", add(1, 2));   /* ← 编译器不知道 add 是什么 */
    return 0;
}
