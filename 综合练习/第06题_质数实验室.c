/* 第06题_质数实验室
   自测册第 6 题
   来源：D:\code\.vscode\new day.c（原为 main() 内的一段，提取时补了头文件和 main 外壳）
*/

#include <stdio.h>

int main(void)
{
int ch;
int need = 0;//用来触发循环中的提示
do//最外层循环 EOF结束
{
    int neg = 0;//判断是否是负数
    int n = 0;//最终输入的整数n,每次循环清零
printf("请输入一个正整数(2-100000):");
ch = getchar();
while(ch == ' ' || ch == '\t')//允许一开始输入多个空格
{
    ch = getchar();
}
//如果输入EOF,直接退出
if(ch == EOF)
{
    break;
}
//先判断有无+-号
if(ch == '+' || ch == '-')
{
    if(ch == '-')
    {
        neg = 1;
    }
    ch = getchar();
}
//再判断+-号之后是啥：数字，其他字符
if(ch < '0' || ch > '9')//非数字
{
    printf("错误,应输入一个正整数\n");
    //清理缓冲区，如输入a 缓冲区中为: a  \n 再次循环时会将\n赋给ch,导致错误提示输出两次
    while(ch != EOF && ch != '\n') ch = getchar();
    continue;
}
else
{
    while(ch >= '0' && ch <= '9')//输入数字时
    {
        n = n * 10 + (ch - '0');
        ch = getchar();
    }
}
//输入数字之后，后面是什么:空格，换行符，还是其他字符
//允许输入数字之后再输入任意空格
while(ch == ' ' || ch == '\t')
{
    ch = getchar();
}
//在判断是不是其他字符
if((ch < '0' || ch > '9') && ch != '\n')//非换行符字符
{
    printf("错误,应输入一个正整数\n");
    //清理缓冲区，如输入11a 缓冲区中为: a  \n 再次循环时会将\n赋给ch,导致错误提示输出两次
    while(ch != EOF && ch != '\n') ch = getchar();
    continue;
}
//整数n的值确定下来了
//如果是负数
if(neg)
{
    printf("错误,请输入一个2-100000之间的整数\n");
    continue;
    //不需要清理缓冲区
    //输入-12 后无论之后输入空格还是换行符，都会从缓冲区里被拿走，不会对下轮循环造成影响
}
else if(n < 2)
{
    printf("错误,请输入一个2-100000之间的整数\n");
    continue;
    //同样不需要清理缓冲区
}
else if(n > 100000)//过大
{
    printf("错误,请输入一个2-100000之间的整数\n");
    continue;
    //同样
}
//现在开始对n做判断
int posdivisor[200] = {0};//存放正因数的数组
//判断n是不是质数
int i = 2;
int note = 1;//给正因数数组里存放正因数，n是不是指数的判断标准
int num = 0;//算1-n之间的质数数量
int pridivisor[10000] = {0};//记录质因数
int m = n;//n的影武者
posdivisor[0] = 1;//第一个正因数一定是1
while(i * i <= n)
{
    if(n % i == 0)//i是正因数
    {
        posdivisor[note] = i;//将正因数放数组中
        note++;//注意最后note比数组实际长度大1
    }
    i++;
}
//判断是不是质数
if(note == 1)//是质数
{
    printf("%d 是质数\n",n);
    //再打印所有正因数,质数只有1和它本身
    printf("所有正因数: %d %d\n",posdivisor[0],n);
    //质因数分解
    printf("质因数分解: %d = %d\n",n,n);
    //算1-n之间的质数
    for(int j = 2;j <= n;j++)
    {
        int i2 = 2;
        int log = 0;//判断1-n之间的数是不是质数的标志
        while(i2 * i2 <= j)
        {
            if(j % i2 == 0)
            {
                log++;//log非零说明不是质数
            }
            i2++;
        }
        if(log == 0)//是质数
        {
            num++;
        }
    }
    printf("%d 到 %d 之间共有 %d 个质数\n",1,n,num);
}
else//不是质数
{
    printf("%d 不是质数\n",n);
    //再打印最小质因数
    /*for(int j = 1;j < note - 1;j++)
    {
        int i1 = 2;//判断最小质因数用的
        while(i1 * i1 <= posdivisor[j])
        {
            if(posdivisor[j] % i1 == 0)
            {
                i1++;
            }
        }
        if(i1 == 2)//找到最小质因数的标记
        {
            printf("最小质因数: %d\n",posdivisor[j]);
            break;//找到后跳出这个for循环
        }
    } */ //不合格 如果(除了1和它本身)因数<= 2时,note = 2,会直接跳过循环,导致最小质因数不打印
      //且如果note >= 3时除1的最小因数为5时,会在while里卡死
    if (note >= 2)
    {
    printf("最小质因数: %d\n", posdivisor[1]);
    }
    //再打印所有正因数
    printf("所有正因数:");
    for(int j = 0;j <= note - 1;j++)//只能打印前一半正因数
    {
        printf(" %d",posdivisor[j]);
    }
    //防止平方数的特殊情况
    //j = note -1时,平方数的平方根会打印两次
    //j = note -2时,非平方数又会少打印一个数
    int last = note - 1;//判断n是不是平方数
    if(posdivisor[last] * posdivisor[last] == n)
    {
        last--;//是平方数时令j = note - 2;不是平方数时令j = note - 1
    }
    for(int j = last;j >= 0;j--)//打印后半部分正因数
    {
        printf(" %d",n / posdivisor[j]);
    }
    printf("\n");
    //打印质因数分解
    printf("质因数分解: %d =",n);
    for(int j = 2;j <= n;j++)//先记录n的质因数
    {
        int log = 0;//判断1-n之间的数是不是质数的标志
        int i2 = 2;
        while(i2 * i2 <= j)
        {
            if(j % i2 == 0)
            {
                log++;//log非零说明不是质数
            }
            i2++;
        }
        if(log == 0)//是质数
        {
            pridivisor[num] = j;
            num++;
        }
    }
//现在pridivisor里面就存放了1-n之间的质因数
    for(int j = 0;j <= num - 1;j++)
    {
        int exponent = 0;//计算质因数分解时各项的指数
        while(m % pridivisor[j] == 0)
        {
            m /= pridivisor[j];
            exponent++;
        }
        if(exponent != 0)//可分解的质因数
        {
            printf(" %d",pridivisor[j]);
            if(exponent == 1)
            {
                printf(" *");
            }
            else
            {
                printf("^%d *",exponent);
            }
        }
    }
    printf("\b ");
    printf("\n%d 到 %d 之间共有 %d 个质数\n",1,n,num);
}

printf("\n");
}while(ch != EOF);


return 0;
}
