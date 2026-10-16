/* ========================================================================
   6.16-04_两个字母排序
   摘自 new day.c 第 327-357 行（已取消注释）
   ======================================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

int main(void)
{
/* 6.16 4题 */
char arr[2];
printf("请输入两个字母(大小写相同):");
scanf("%c %c", &arr[0], &arr[1]);
int num1 = (int)arr[0];
int num2 = (int)arr[1];
char temp = arr[0];
if(num1 > num2)
{
    arr[0] = arr[1];
    arr[1] = temp;
}
int i = (int)arr[0];
int j = (int)arr[1];
int l = 1;
while(1)
{
    int k = 1;
    for(int k = 1;k <=l;k++)
    {
        printf("%c", i);
        i++;
        if(i > j)
        {
            goto end;
        }
    }
    printf("\n");
    l++;
}
end:
    return 0;
}
