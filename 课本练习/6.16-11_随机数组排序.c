/* ========================================================================
   6.16-11_随机数组排序
   摘自 new day.c 第 380-403 行（已取消注释）
   ======================================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

int main(void)
{
//6.16 11题
srand((unsigned)time(NULL));
int num[8];
for(int i = 0;i < 8;i++)
{
    num[i] = rand() % (100 - 1 + 1);
}
int max = num[0];
for(int i = 0;i < 8;i++)
{
    for(int j =i + 1;j < 8;j++)
    {
        if(num[j] >= num[i])
        {
            max = num[j];
            num[j] = num[i];
            num[i] = max;
        }
    }
}
for(int i = 0;i < 8;i++)
{
   printf("%d ",num[i]);
}
    return 0;
}
