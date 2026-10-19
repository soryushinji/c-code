#include <stdio.h>
#include "calc.h"
int main(void)
{
    printf("%d\n", sub(5, 3));   /* ← 声明有了，编译过了，链接时找不到 */
    return 0;
}
