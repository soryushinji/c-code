/* ========================================================================
   6.16-18_朋友数翻倍
   摘自 new day.c 第 420-429 行（已取消注释）
   ======================================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

int main(void)
{
/* 6.16 18题 */
int num = 5;
int i = 1;
while(num < 150)
{
    num -= i;
    num *= 2;
    printf("第%d周有%d位朋友\n",i,num);
    i++;
}
    return 0;
}
