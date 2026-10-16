/* ========================================================================
   6.16-03_字母大小写判断
   摘自 new day.c 第 286-326 行（已取消注释）
   ======================================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

int main(void)
{
/* 6.16 3题 */
char arr;
printf("请输入一个字母：");
int a = scanf("%c", &arr);
int num = (int)arr;
//a97 z122 A65 Z90
int gin = 97;
int gin1 = 65;
if(a == 0)
{
    printf("输入错误\n");
}

else if(num >= 97 && num <= 122)
{
    int b = num;
    for(num;num >= 97;num--)
    {
        for(int i = b;i >= num;i--)
        {
            printf("%c", i);
        }
        printf("\n");
    }
}
else if(num >= 65 && num <= 90)
{
    int c = num;
   for(num;num >= 65;num--)
    {
        for(int i = c;i >= num;i--)
        {
            printf("%c", i);
        }
        printf("\n");
    }
}
else
{
    printf("不是字母\n");
}
    return 0;
}
