/* ========================================================================
   6.16-12_调和级数
   摘自 new day.c 第 404-419 行（已取消注释）
   ======================================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

int main(void)
{
/* 6.16 12题 */
int num;
printf("计算至第(次):");
scanf("%d",&num);
double mount = 1.0;
for(int i = 1;2 * i <= num;i++)
{
    double le = -(1.0 / (2 * i));
    mount += le;
}
for(int j = 1;2 * j + 1 <= num;j++)
{
    double ri = (1.0 / (2 * j + 1));
    mount += ri;
}
printf("%d项时的总和为:%lf",num,mount);
    return 0;
}
