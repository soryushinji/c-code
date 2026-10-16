/* ========================================================================
   7.12-07_工资计算
   摘自 new day.c 第 472-498 行（已取消注释）
   ======================================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

int main(void)
{
/* 7.12 7题 */
int hour;
printf("请输入每周工作的小时数：");
scanf("%d",&hour);
double total = 0;
if(hour <= 40)
{
    total = hour * 10;
}
else
{
    total = hour * 1.5 * 10;
}
double paper = 0;
if(total <= 300)
{
    paper = total * 0.85;
}
else if(total > 300 && total <= 450)
{
    paper = 300 * 0.85 + (total - 300) * 0.8;
}
else
{
    paper = 300 * 0.85 + 150 * 0.8 + (total - 450) * 0.75;
}
printf("您一周的工资总额,税金,净收入分别为:%.2lf$,%.2lf$,%.2lf$",total,total-paper,paper);
    return 0;
}
