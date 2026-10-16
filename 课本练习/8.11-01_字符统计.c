/* ========================================================================
   8.11-01_字符统计
   摘自 new day.c 第 785-979 行（已取消注释）
   ======================================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

int main(void)
{
/* 8.11 1题 */
int num1 = 0;
int num2 = 0;
int c;
while((c = getchar()) != EOF && c != '#')
{
    num1++;
    if(isdigit(c))
    {
        num2 += 1;
    }
    putchar(c);
}
printf("\n");
printf("在文件结尾之前读到的字符数为%d,数字为%d",num1,num2);

printf("请随意打印:");
/* 重复声明已删: int c; */
int num = 0;
int i = 0;
int j = 0;
while((c = getchar()) != EOF)
{
    if(c == '\n')
    {
        putchar('\\');
        putchar('n');
        j = (int)'\n';
        printf(" %d",j);
        printf("\n");
        i++;
    }
    else if(c == '\t')
    {
        putchar('\\');
        putchar('t');
        j = (int)'\t';
        printf(" %d",j);
        printf("   ");
        i++;
    }
    else
    {
        num = (int)c;
        putchar(c);
        printf(" %d",num);
        printf("   ");
        i++;
    }
if(i % 10 == 0 && c != '\n')
{
    printf("\n");
}
}
//8.11 8题(不完善)
start:
printf("请输入您的选择:\na.加        s.减\nm.乘        d.除\nq.退出\n");
/* 重复声明已删: int c; */
int ch;
double first;
double second;
while((c = getchar()) != EOF && c != 'q')
{
    switch(c)
    {
        case'a':
        {
            printf("请输入第一个数字:");
            while((scanf(" %lf",&first)) != 1)
            {
                while((ch = getchar()) != '\n')
                {
                    putchar(ch);
                }
                printf("不是数字");
                printf("请输入一个数字,如2.5,-1.78E8或3:");
            }
            printf("请输入第二个数字:");
            while((scanf(" %lf",&second)) != 1)
            {
                while((ch = getchar()) != '\n')
                {
                    putchar(ch);
                }
                printf("不是数字");
                printf("请输入一个数字,如2.5,-1.78E8或3:");
            }
            printf("%.2f + %.2f = %.2f\n",first,second,first + second);
            while (getchar() != '\n')
            continue;
            goto start;
        }
        case's':
        {
            printf("请输入第一个数字:");
            while((scanf(" %lf",&first)) != 1)
            {
                while((ch = getchar()) != '\n')
                {
                    putchar(ch);
                }
                printf("不是数字");
                printf("请输入一个数字,如2.5,-1.78E8或3:");
            }
            printf("请输入第二个数字:");
            while((scanf(" %lf",&second)) != 1)
            {
                while((ch = getchar()) != '\n')
                {
                    putchar(ch);
                }
                printf("不是数字");
                printf("请输入一个数字,如2.5,-1.78E8或3:");
            }
            printf("%.2f - %.2f = %.2f\n",first,second,first - second);
            while (getchar() != '\n')
            continue;
            goto start;
        }
        case'm':
        {
                        printf("请输入第一个数字:");
            while((scanf(" %lf",&first)) != 1)
            {
                while((ch = getchar()) != '\n')
                {
                    putchar(ch);
                }
                printf("不是数字");
                printf("请输入一个数字,如2.5,-1.78E8或3:");
            }
            printf("请输入第二个数字:");
            while((scanf(" %lf",&second)) != 1)
            {
                while((ch = getchar()) != '\n')
                {
                    putchar(ch);
                }
                printf("不是数字");
                printf("请输入一个数字,如2.5,-1.78E8或3:");
            }
            printf("%.2f * %.2f = %.2f\n",first,second,first * second);
            while (getchar() != '\n')
            continue;
            goto start;
        }
        case'd':
        {
            printf("请输入第一个数字:");
            while((scanf(" %lf",&first)) != 1)
            {
                while((ch = getchar()) != '\n')
                {
                    putchar(ch);
                }
                printf("不是数字");
                printf("请输入一个数字,如2.5,-1.78E8或3:");
            }
            printf("请输入第二个数字:");
            while((scanf(" %lf",&second)) != 1 )
            {
                while((ch = getchar()) != '\n')
                {
                    putchar(ch);
                }
                printf("不是数字");
                printf("请输入一个数字,如2.5,-1.78E8或3:");
            }
            while(second == 0)
            {
                printf("请输入非零数字");
                while (scanf("%lf", &second) != 1)
                {
                    while ((ch = getchar()) != '\n')
                        putchar(ch);
                    printf("不是数字");
                    printf("请输入一个数字，如 2.5, -1.78E8 或 3: ");
    }
            }
            printf("%.2f / %.2f = %.2f\n",first,second,first / second);
            while (getchar() != '\n')
            continue;
            goto start;
        }
        default:
        {
            printf("输入失败,请重新输入\n");
            while (getchar() != '\n')
            continue;
            break;
        }

    }
}
printf("再见");
    return 0;
}
