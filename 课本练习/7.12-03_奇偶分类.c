/* ========================================================================
   7.12-03_奇偶分类
   摘自 new day.c 第 702-751 行（已取消注释）
   ======================================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

int main(void)
{
/* 7.12 3题 */
int num[1024];
int num1[1024];
printf("请输入整数(按零结束):\n");
int i = 0;
int j = 0;
int input;
while(scanf("%d",&input) == 1 && input != 0)
{
    if(input % 2 == 0)
    {
        num[i] = input;
        i++;
    }
    else
    {
        num1[j] = input;
        j++;
    }
}
double total = 0.0;
double total1 = 0.0;
printf("输入的偶数为:\n");
for(int k = 0;k < i;k++)
{
    printf("%-4d ",num[k]);
    total += num[k];
    if((k + 1) % 8 == 0)
    {
        printf("\n");
    }
}
printf("\n");
printf("输入的奇数为:\n");
for(int k = 0;k < j;k++)
{
    printf("%-4d ",num1[k]);
    total1 += num1[k];
    if((k + 1) % 8 == 0)
    {
        printf("\n");
    }
}
double ave = (i > 0)? total / (double)i : 0.0;
double ave1 = (j > 0)? total1 / (double)j: 0.0;
printf("\n");
printf("****************************************************************\n");
printf("偶数的个数为：%d,平均值为:%.2lf\n",i,ave);
printf("奇数的个数为：%d,平均值为:%.2lf\n",j,ave1);
printf("****************************************************************\n");
    return 0;
}
