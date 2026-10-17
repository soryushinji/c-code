/* 第09题_猜数字游戏
   自测册第 9 题
   来源：D:\code\.vscode\new day.c（原为 main() 内的一段，提取时补了头文件和 main 外壳）
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
int round = 0;//总共玩了几局
int yround = 0;//赢得局数
printf("=== 猜数字游戏(1-100,最多猜 7 次)===\n");
srand((unsigned)time(NULL));//设置随机数种子  是以秒数作为种子,循环太快会导致每次循环随机数不变
while(1)//大循环,看循环的条件是什么(或者就用1)
{
    int times = 7;//每局猜数字的次数
    int i = 1;//提示第几次猜测
    int secret = rand() % (100 - 1 + 1) + 1;//获取随机数
    int chosen = 0;//是否再来一局的选项y/n
    char yn;//是否再来一局的选项y/n
    int ch;
    if(round > 0)//第一局之后打印
    {
        printf("=== 第 %d 局 ===\n",round + 1);
    }
    //每一局猜数字游戏单独一个小循环
while(times >= 0)//次数耗尽或猜中结束循环
{
    int neg = 0;//输入负数时的信号
    int num = 0;//每次猜的数字,重新猜时要清零
    printf("第 %d 次猜测:",i);
    //输入数字
    ch = getchar();
    //防止EOF卡死
    if (ch == EOF)                   /* ★ 输入结束 → 退出程序 */
    {
    printf("\n输入结束,再见!\n");
    round = round ? round : 1;   /* 避免胜率除零 */
    break;
    }
    //允许开头输入空格
    while(ch == ' ' || ch == '\t')
    {
        ch = getchar();
    }
    //输入+-号的情况
    if(ch == '+' || ch == '-')
    {
        if(ch == '-')
        {
            neg++;
        }
        ch = getchar();
    }
    //接下来看输入的是数字还是其他符号
    if(ch < '0' || ch > '9')//非数字情况
    {
        printf("错误:请输入 1 到 100 之间的整数(本次不计入次数)\n");
        //清除缓冲区的所有字符
        while(ch != '\n' && ch != EOF) ch = getchar();
        continue;
    }
    else//数字情况
    {
        //将输入的数字赋值给num
        while(ch >= '0' && ch <= '9')
        {
            num = num * 10 + (ch - '0');
            ch = getchar();
        }
    }
    //输入数字之后
    //1是空格,可以
    while(ch == ' ' || ch == '\t')
    {
        ch = getchar();
    }
    //2是其他非数字空格换行符字符,如12abc
    if((ch < '0' || ch > '9') && ch != '\n')
    {
        printf("错误:请输入 1 到 100 之间的整数(本次不计入次数)\n");
        //清除缓冲区的所有字符
        while(ch != '\n' && ch != EOF) ch = getchar();
        continue;
    }
    //3是换行符——数字确定下来了
    //再对数字做出判断
    //是负数
    if(neg)
    {
        printf("错误:请输入 1 到 100 之间的整数(本次不计入次数)\n");
        continue;
    }
    if(num < 1 || num > 100)//范围之外的数字
    {
        printf("错误:请输入 1 到 100 之间的整数(本次不计入次数)\n");
        //不用清除缓冲区
        continue;
    }
    else//在范围内
    {
        //与随机数比较,并给出答复
        //times = 7猜的次数  i = 1第几次猜
        //应该是小循环,好吧不是
        if(num > secret && times > 1)//猜大了
        {
            times--;//剩余次数-1
            printf("太大了!还有 %d 次机会。\n",times);
            i++;//下次提醒还有+1次机会
        }
        else if(num < secret && times > 1)//猜小了
        {
            times--;
            printf("太小了!还有 %d 次机会。\n",times);
            i++;
        }
        else if(num != secret && times == 1)//第七次也没猜中,第七次猜测时times为1,第七次猜后变为零
        {
            printf("很遗憾,机会耗尽!答案是: %d。\n",secret);
            round++;//局数+1,但胜利局数不变
            break;
        }
        else if(num == secret && times > 1)//第七次之前猜中了,
        {
            times--;
            printf("恭喜!你用了 %d 次猜中,答案就是 %d。\n",i,secret);
            round++;//一局玩完,总玩次数+1
            yround++;//胜利局数+1
            break;//跳出猜数字循环
        }
        else if(num == secret && times == 1)//第七次猜中
        {
            printf("恭喜!你用了 %d 次猜中,答案就是 %d。\n",i,secret);
            round++;//一局玩完,局数+1
            yround++;
            break;//跳出猜数字循环
        }

    }
}//猜数字小循环结束
printf("\n");
//提问是否继续
while(chosen == 0)
{
printf("再来一局?(y/n)");
//scanf("%c",&yn);//好怀念,这几个题都没见你  好吧还是用不到你
//输入y/n
ch = getchar();
//允许开头输入空格
//解决EOF问题
if (ch == EOF)                  /* ★ 加这一段 */
{
    printf("\n输入结束,再见!\n");
    yn = 'n';                   /* 当成回答了 n */
    chosen = 1;
    break;
}
while(ch == ' ' || ch == '\t')
{
    ch = getchar();
}
//输入字符
if(ch != 'y' && ch != 'n')//输入非y/n
{
    printf("错误!\n");
    //清除缓冲区的多余字符
    while(ch != '\n' && ch != EOF) ch = getchar();
}
else//输入y/n
{
    yn = ch;
    ch = getchar();
    //如果y/n之后输入空格,允许
    while(ch == ' ' || ch == '\t')
    {
        ch = getchar();
    }
    //如果再输入其他非换行字符,重新输入
    if(ch != '\n')
    {
        printf("错误!\n");
        //清空缓冲区
        while(ch != '\n' && ch != EOF) ch = getchar();
    }
    else//输入\n
    {
    chosen = 1;//跳出小循环
    }
}
}//小循环结束
if(yn == 'n')
{
    break;
    //跳出大循环
}
printf("\n");
}//大循环结束
printf("\n");
//打印结果
double ycent =(double)yround / (double)round * 100;
printf("本次共玩 %d 局,赢 %d 局，胜率 %.1f%%。再见~~",round,yround,ycent);


return 0;
}
