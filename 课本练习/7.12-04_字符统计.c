/* ========================================================================
   7.12-04_字符统计
   摘自 new day.c 第 752-784 行（已取消注释）
   ======================================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

int main(void)
{
/* 7.12 4 6题 */
int c;
int num1 = 0;
int num2 = 0;
int num3 = 0;
int pre = 0;
printf("请输入(输入#退出):");
while((c = getchar()) != EOF && c != '#')
{
    if(c == '.')
    {
        num1 += 1;
        putchar('!');
    }
    else if(c == '!')
    {
        num2 += 1;
        putchar('!');
        putchar('!');
    }
    else if(pre == 'e' && c == 'i')
    {
        num3 += 1;
        putchar(c);
    }
    else
    {
    putchar(c);
    }
    pre = c;
}
printf("\n");
printf("交替了%d次,ei出现了%d次",num1 + num2,num3);
    return 0;
}
