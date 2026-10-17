/* ========================================================================
   01_数位分析器
   摘自 new day.c 第 980-1052 行（已取消注释）
   ======================================================================== */

#include <stdio.h>

int main(void)
{
/* 综合题1 */
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
    return 0;
}
