/* ========================================================================
   02_图案打印机_goto版
   摘自 new day.c 第 1083-1229 行（已取消注释）
   ======================================================================== */

#include <stdio.h>

int main(void)
{
/* 综合题2 */
int button = 0;
int ch;
int h;
int num1 = 0;
int num2 = 0;
start:
printf("************************************************************************************************\n");
printf("输出示例\n");
printf("1) 直角三角形        2) 等腰三角形\n*                     *\n**                   ***\n***                 *****\n****               *******                      ← 等腰三角形共 4 行，第 n 行有 2n-1 个 *\n");
printf("3) 菱形（h=2 时共 3 行）      4) 数字金字塔（h=4）\n  *                             1\n ***                           121\n  *                           12321\n                             1234321\n");
printf("5) 退出\n");
printf("************************************************************************************************\n");
start1:
printf("请选择:");

if((scanf("%d",&button)) != 1 || button <= 0 || button == 5 || button >5)
{
    if(button == 5)
    {
        goto end;
    }
    while((ch = getchar()) != '\n' && ch != EOF)
    {
    continue;
    }
    printf("无效选项，请重新选择:\n");
    goto start;
}
else
{
    printf("请输入高度h(1-15):");
    start2:
    if((scanf("%d",&h)) != 1 || h <= 0 || h > 15)
    {
        printf("高度必须在 1-15 之间，请重新输入:");
        while((ch = getchar()) != '\n' && ch != EOF)
        {
        continue;
        }
        goto start2;
    }
    else
    {
        while((ch = getchar()) != '\n' && ch != EOF)
        {
        continue;
        }
        switch(button)
        {
        case 1:
            for(int i = 1;i <= h;i++)
            {
                for(int j = 1;j <= i;j++)
                {
                    printf("*");
                }
                printf("\n");
            }
            num1++;
            num2 += h;
            break;
        case 2:
            for(int i = 1;i <= h;i++)
            {
                for(int k = i;k <= h - 1;k++)
                {
                    printf(" ");
                }
                for(int j = 1;j <= 2 * i - 1;j++)
                {
                    printf("*");
                }
                printf("\n");
            }
            num1++;
            num2 += h;
            break;
        case 3:
            for(int i = 1;i <= (h / 2) + 1;i++)
            {
                for(int m = i;m <= (h / 2) + 1;m++)
                {
                    printf(" ");
                }
                for(int j = 1;j <= 2 * i - 1;j++)
                {
                    printf("*");
                }
                printf("\n");
            }
            for(int l = (h / 2);l >= 1;l--)
            {
                for(int n = l;n <= (h / 2) + 1;n++)
                {
                    printf(" ");
                }
                for(int k = 2 * l - 1;k >= 1;k--)
                {
                    printf("*");
                }
                printf("\n");
            }
            num1++;
            if(h % 2 == 0)
            {
                num2 += h + 1;
            }
            else
            {
            num2 += h;
            }
            break;
        case 4:
            for(int i = 1;i <= h;i++)
            {
                for(int k = i;k <= h - 1;k++)
                {
                    printf(" ");
                }
                for(int j = 1;j <= i;j++)
                {
                    printf("%d",j);
                }
                for(int m = i - 1;m >= 1;m--)
                {
                        printf("%d",m);
                }
                printf("\n");
            }
            num1++;
            num2 += h;
            break;
        }
    } 
}
goto start1;
end:
if(num1 == 0)
{
printf("本次共打印 0 个图案，合计 0 行。再见~~\n");
}
else
{
printf("本次共打印 %d 个图案，合计 %d 行。再见~~\n",num1,num2);
}
    return 0;
}
