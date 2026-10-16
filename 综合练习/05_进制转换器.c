/* ========================================================================
   05_进制转换器
   摘自 new day.c 第 2004-2200 行（已取消注释）
   ======================================================================== */

#include <stdio.h>

int main(void)
{
//综合题5
int ch;
int num = 0;//统计转换次数
int button = 0;//让除了第一轮以外都打印提示
int radixnum[15] = {2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};//记录各目标进制
int radixchange[15] = {0};//记录各目标进制分别转换多少次
printf("请输入十进制数和目标进制(1-16)(输入负数结束):\n");
//while((ch = getchar()) != EOF)这样会先打字符再输出提示
while(1)
{
int dicimal = 0;//十进制数
int radix = 0;//目标进制
int neg = 0;//判断十进制数是不是负数
int digit10 = 0;//十进制数不能过大,最大不能超过9位,记录十进制数的位数
int digit = 0;//判断数字转换数字的位数
int modulus[30] = {0};//要逆序输出的余数,30位封顶
if(button != 0)
{
printf("请输入十进制数和目标进制:\n");
}//第一次转换不用输出，之后的转换再循环
//提示输入完后再打字符
ch = getchar();
if(ch == EOF)
{
    break;//退出循环
}
while(ch == ' ' || ch == '\t')//允许一开始输入空格
{
    ch = getchar();
}
//判断输入的字符
if(ch == '+' || ch == '-')//如果输入+-号
{
    if(ch == '-')//是-先给neg赋1，之后十进制数输入的是整数再判断
    {
        neg = 1;
    }
ch = getchar();
}
//再判断
if(ch < '0' || ch > '9')//不是数字
{
    printf("错误,应输入十进制数!请重新输入\n");
    while(ch != '\n' && ch != EOF) ch = getchar();
    button++;
    continue;//清除缓冲区里的多余字符
}
else//是数字
{
    while(ch >= '0' && ch <= '9')//将输入的十进制数赋值给dicimal
    {
        if(digit10 >= 9)//位数过大,重新循环防止崩溃,等十进制数和目标进制确定完再判断
        {
        printf("十进制数过大,请重新输入\n");
        while(ch != EOF && ch != '\n') ch = getchar();
        goto next;
        }
        dicimal = dicimal * 10 + (ch - '0');
        digit10++;
        ch = getchar();
    }
}
/* ★★ 放在"检查空格"之前，任何负数都结束 ★★ */
if(neg)
{
    printf("结束输入\n");
    break;
}
//判断输入数字后面是什么,是空格还是其他的字符
if(ch == ' ' || ch == '\t')//是空格
{
    while(ch == ' ' || ch == '\t')//允许两个数中间输入多个空格
    {
    ch = getchar();
    }
}
else//非空格字符
{
    printf("错误,应输入十进制数!请重新输入\n");
    while(ch != '\n' && ch != EOF) ch = getchar();
    next:
    button++;
    continue;//清除缓冲区里的多余字符
}
//现在十进制数能确定下来了
//接下来到目标进制
if(ch < '0' || ch > '9')//目标进制非数字
{
    printf("错误,目标进制必须是2~16之间的整数,请重新输入\n");
    while(ch != '\n' && ch != EOF) ch = getchar();
    button++;
    continue;
}
else//目标进制是数字
{
    while(ch >= '0' && ch <= '9')//将输入的值赋给目标进制
    {
        radix = radix * 10 + (ch - '0');
        ch = getchar();
    }
}
//输入数字之后,判断数字后面是什么
//是字符,空格,还是换行符
if(ch != ' ' && ch != '\t' && ch != '\n')//字符
{   
    printf("错误,目标进制必须是2~16之间的整数,请重新输入\n");
    while(ch != '\n' && ch != EOF) ch = getchar();
    button++;
    continue;
}
else if(ch == ' ' || ch == '\t')//是空格,可大量输入,直到输入回车
{
    while(ch == ' ' || ch == '\t')
    {
        ch = getchar();
    }
}
//再对目标进制进一步判断
if(radix < 2 || radix > 16)//提示错误并重新输入
{
    printf("错误,目标进制必须是2~16之间的整数,请重新输入\n");
    button++;
    continue;
}
//现在十进制数和目标进制确定下来了
/*printf("十进制数%d\n",dicimal);
printf("目标进制%d\n",radix);*/
//成功打印了
//现在要输出转换进制了
int dicimal1 = dicimal;//十进制数的替身
//循环开始有int digit = 0;
if(dicimal > 0)
{
while(dicimal1 > 0)
{
    modulus[digit] = dicimal1 % radix;//取余数
    dicimal1 = dicimal1 / radix;//除
    digit++;
}
//10-A 11-B 12-C 13-D 14-E 15-F
//输出转换数字
printf("%d 的 %d 进制是: ",dicimal,radix);
for(int i = digit - 1;i >= 0;i--)
{
    switch(modulus[i])
    {
        case 15:
            printf("%c",'F');
            break;
        case 14:
            printf("%c",'E');
            break;
        case 13:
            printf("%c",'D');
            break;
        case 12:
            printf("%c",'C');
            break;
        case 11:
            printf("%c",'B');
            break;
        case 10:
            printf("%c",'A');
            break;
        default:
            printf("%d",modulus[i]);
            break;
    }
}
printf(", 共 %d 位\n",digit);
}
else//十进制数为0
{
    printf("%d 的 %d 进制是 %d,共 %d 位\n",dicimal,radix,0,1);
}
//转换数字打印完成
//记录各进制用了几次
for(int i = 0;i < 15;i++)
{
    if(radixnum[i] == radix)
    {
        radixchange[i]++;
    }
}
button++;//确保循环结束到下一轮仍可以打印提示
num++;//每次循环记录一次转换次数
}
printf("共转换 %d 次:",num);
for(int i = 0;i < 15;i++)
{
    if(radixchange[i] != 0)
    {
        printf(" %d 进制 %d 次,",radixnum[i],radixchange[i]);
    }
}
printf("\n");
printf("再见~~");
    return 0;
}
