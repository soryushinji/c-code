/* ========================================================================
   补充_购物车_while版
   摘自 new day.c 第 562-687 行（已取消注释）
   ======================================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

int main(void)
{
//方法二：用while语句
char key;
double ynum = 0;
double tnum = 0;
double hnum = 0;
double amount;
do
{
printf("请问您要买(a:洋蓟)(b:甜菜)(c:胡萝卜)(q:退出):");
scanf(" %c",&key);
switch(key)
    {
    case 'a':
        {
            printf("请输入洋蓟的磅数：");
            scanf("%lf",&amount);
            ynum += amount;
            break;
        }
    case 'b':
        {
            printf("请输入甜菜的磅数：");
            scanf("%lf",&amount);
            tnum += amount;
            break;
        }
    case 'c':
        {
            printf("请输入胡萝卜的磅数：");
            scanf("%lf",&amount);
            hnum += amount;
            break;
        }
    case 'q':
        {
            printf("购买结束,即将打印小票\n");
            break;
        }
        default:
        {
            printf("请输入正确的字母！\n");
            break;
        }
    }
}
while(key != 'q');



double total = ynum * yangji + tnum *tiancai + hnum * huluobo;
double total_cai =total;
double zhekou = 0;
if(total >= 100)
{
    zhekou = total * 0.05;
    total *= 0.95;
}
double total_dingdan = total;
double num = ynum + tnum + hnum;
double yab = 0;
if(num <= 5)
{
    total += 6.5;
    yab = 6.5;
}
else if(num > 5 && num <= 20)
{
    total += 14;
    yab =14;
}
else
{
    yab = 14 + (num - 20) * 0.5;
    total += yab;
}
printf("***********************************************************************************\n");
printf("物品售价:洋蓟2.05美元/磅,甜菜1.15美元/磅,胡萝卜1.09美元/磅\n");
printf("订购的重量(单位:磅):洋蓟(%.2lf),甜菜(%.2lf),胡萝卜(%.2lf)\n",ynum,tnum,hnum);
printf("订购的蔬菜费用:%.2lf$\n",total_cai);
printf("订单的总费用:%.2lf$\n",total_dingdan);
printf("折扣:%.2lf$\n",zhekou);
printf("运费和包装费:%.2lf$\n",yab);
printf("总费用:%.2lf$\n",total);
printf("***********************************************************************************");

 int c;

    while ((c = getchar()) != EOF || (c = getchar()) != '\n') 
    {
        putchar(c);
    }
printf("请随意输入(除中文):");
int c;
int alpha = 0;
int digit = 0;
int space = 0;
int enter = 0;
int punct = 0;
while((c = getchar()) != '#')
{
    if(isalpha(c))
    {
        alpha += 1;
    }
    else if(isdigit(c))
    {
        digit += 1;
    }
    else if(ispunct(c))
    {
        punct += 1;
    }
    else if(c == '\n')
    {
        enter += 1;
    }
    else if(c == ' ')
    {
        space += 1;
    }
}
printf("您输入的话中有字母%d个,数字%d个,标点符号%d个,空格%d个,换行符%d个",alpha,digit,punct,space,enter);

int ch;
    int count = 0;
    return 0;
}
