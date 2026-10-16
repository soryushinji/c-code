/* ========================================================================
   6.16-05_字母金字塔
   摘自 new day.c 第 358-379 行（已取消注释）
   ======================================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

int main(void)
{
/* 6.16 5题 */
printf("请输入一个大写字母：");
char arr;
scanf("%c", &arr);
int num = (int)arr - 65;
int mon = num * 2 + 1;
for(int i = 0;i <= num;i++)
{
    for(int j = i;j <num;j++)
    {
        printf(" ");
    }
    for(int k = 0;k <= i;k++)
    {
        printf("%c", 65 + k);
    }
    for(int l = i - 1;l >= 0;l--)
    {
        printf("%c", 65 + l);
    }
    printf("\n");
}
    return 0;
}
