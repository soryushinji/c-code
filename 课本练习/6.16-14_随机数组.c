/* ========================================================================
   6.16-14_随机数组
   摘自 new day.c 第 430-471 行（已取消注释）
   ======================================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

int main(void)
{
/* 6.16 14题 */
srand((unsigned)time(NULL));
int num;
printf("你想要多长的数组：");
scanf("%d",&num);
int arr1[num];
int arr2[num];
for(int i = 0;i < num;i++)
{
    arr1[i] = rand() %(100 -1 + 1);
}
int min = arr1[0];
for(int i = 0;i < num;i++)
{
    for(int j = i + 1;j < num;j++)
    {
        if(arr1[j] < arr1[i])
        {
            min = arr1[j];
            arr1[j] = arr1[i];
            arr1[i] = min;
        }
    }
}
for(int i = 0;i < num;i++)
{
    int zero = 0;
    for(int j = 0;j <= i;j++)
    {
        zero += arr1[j];
    }
    arr2[i] = zero;
}
for(int i = 0;i < num;i++)
{
    printf("%d ",arr1[i]);
}
printf("\n");
for(int i = 0;i < num;i++)
{
    printf("%d ",arr2[i]);
}
    return 0;
}
