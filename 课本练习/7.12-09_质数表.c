/* ========================================================================
   7.12-09_质数表
   摘自 new day.c 第 499-523 行（已取消注释）
   ======================================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

int main(void)
{
/* 7.12 9题 */
printf("请输入一个正整数：");
int num;
scanf("%d",&num);
int i = 2;
while(i <= num)
{
    int k = 0;
    int j = 2;
    while(j * j <= i)
    {
        if(i % j == 0 && j != i)
        {
            k++;
        }
        j++;
    }
    if(k == 0)
    {
        printf("%d ",i);
    }
    i++;
const double yangji = 2.05;
const double tiancai = 1.15;
const double huluobo = 1.09;
    return 0;
}
