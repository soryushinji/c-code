/* 第08题_成绩统计与排序
   自测册第 8 题
   来源：D:\code\.vscode\new day.c（原为 main() 内的一段，提取时补了头文件和 main 外壳）
*/

#include <stdio.h>

int main(void)
{
int ch;
int score[50] = {0};//记录成绩的数组
double passrate = 0;//记录最终及格率
double ave = 0;//记录最终平均分
int num = 0;//记录输入的成绩数量
double median = 0;//记录最终中位数
double variance = 0;//记录方差
int scoreband[5] = {0};//记录分数段
int loop = 0;//记录是否输入错误的标志,每轮循环归零
printf("请输入成绩(0-100,输入 -1 结束,最多 50 个):\n");
//开始输入成绩
while(ch != EOF)//输入记录成绩的大循环
{
    int neg = 0;//记录输入数字是否是负数的标志,每轮循环归零
    int n = 0;//记录输入成绩,每次循环清零
    //如果输入错误,再次输入时要提示,正常输入时不用提示
if(loop != 0)
{
    printf("请输入成绩:\n");
}
    loop = 0;//记录是否输入错误的标志,每轮循环归零
    ch = getchar();
//如果第一次输入EOF
if(ch == EOF)
{
    break;//跳出循环,防止运行循环后面的代码
}
//允许一开始输入多个空格,如果成绩之间输入很多空格也能跳过
while(ch == ' ' || ch == '\t')
{
    ch = getchar();
}
//允许输入+-号
if(ch == '+' || ch == '-')
{
    if(ch == '-')
    {
        neg = 1;
    }
    ch = getchar();
}
//如果输入非数字字符
if(ch < '0' || ch > '9')
{
    printf("错误,请输入1-100之间的整数!\n");
    printf("请从错误的地方开始输入成绩!\n");
    printf("\n");
    loop++;
    //清除缓冲区
    while(ch != '\n' && ch != EOF) ch = getchar();
    continue;//重新循环
}
//输入数字
else
{
    while(ch >= '0' && ch <= '9')//记录输入的数字
    {
        n = n * 10 + (ch - '0');
        ch = getchar();
    }
}
//输入数字之后
//1：允许再次输入空格
// //1)允许输入多个空格,最后还是决定启用这版,在改：应该是输入空格之后重新循环,不存在输入多个空格的
// while(ch == ' ' || ch == '\t')
// {
//     ch = getchar();
// }
//2输入的是非空格数字换行符
if((ch < '0' || ch > '9') && ch != '\n'&& ch != ' ' && ch != '\t')
{
    printf("错误,请正确输入!\n");
    printf("请从错误的地方开始输入成绩!\n");
    printf("\n");
    loop++;
    //清除缓冲区
    while(ch != '\n' && ch != EOF) ch = getchar();
    continue;//重新循环
}
//验证输入的数字
if(neg)//输入的是负数
{
    if(n == 1)//该结束输入了
    {
        break;
    }
    else//输入非-1的负数
    {
        printf("错误,请输入1-100之间的正整数!\n");
        printf("请从错误的地方开始输入成绩!\n");
        printf("\n");
        loop++;
        continue;
    }
}
if(n > 100)//数字过大
{
    printf("错误,请输入1-100之间的整数!\n");
    printf("请从错误的地方开始输入成绩!\n");
    printf("\n");
    loop++;
    continue;
}
//到这说明输入的是正确的数字
//如果数组满了
if(num >= 50)
{
    printf("[提示]已满50个\n");
    break;
}
//将数赋给数组
score[num] = n;
num++;//下一轮时score数字记录下一个
//2)只允许输入一个空格,应该用这版,应该放到验证数字的后面
if(ch == ' ' || ch == '\t')
{
    continue;//数字后输入空格后重新循环
}

}//跳出大循环
//验证成绩是否成功录入
// printf("\n共录入 %d 个\n", num);
// printf("数据: ");
// for(int i = 0; i < num; i++)
// {
//     printf("%d ", score[i]);
// }
//开始输出结果
printf("共 %d 个成绩\n",num);
//如果什么也没输入
if (num == 0)
{
    printf("[提示] 没有录入任何成绩，无法统计。\n");
    return 0;                 /* 后面全跳过 */
}
//打印平均数
for(int i = 0;i < num;i++)
{
    ave += score[i];
}
ave /= (double)num;
printf("平均分: %.2f\n",ave);
//找最高分和最低分,顺便降序排列
int max = score[0];
for(int i = 0;i < num;i++)
{
    for(int j = i + 1;j < num;j++)
    {
        if(score[i] < score[j])
        {
            max = score[j];
            score[j] = score[i];
            score[i] = max;
        }
    }
}
//打印最高分最低分
printf("最高分: %d    最低分: %d\n",score[0],score[num - 1]);
//统计及格率>= 60
int pass = 0;//记录及格人数,顺带记录各分数段人数
for(int i = 0;i < num;i++)
{
    int j = 0;//给各分数段做标记
    if(score[i] >= 90 && score[i] <= 100)//分数段1
    {
        scoreband[j]++;
        pass++;
    }
    else if(score[i] >= 80 && score[i] <= 89)//分数段2
    {
        j = 1;
        scoreband[j]++;
        pass++;
    }
    else if(score[i] >= 70 && score[i] <= 79)//分数段3
    {
        j = 2;
        scoreband[j]++;
        pass++;
    }
    else if(score[i] >= 60 && score[i] <= 69)//分数段3
    {
        j = 3;
        scoreband[j]++;
        pass++;
    }
    else//分数段4
    {
        j = 4;
        scoreband[j]++;
    }
}
passrate = (double)pass / (double)num * 100;
printf("及格率: %.1f%%\n",passrate);
//打印柱状图,题目没说要求,就默认是和之前一样每2%一个#...补充:50人最多,就是一个人一个#,好吧
printf("分数段分布:\n");
for(int k = 0;k <= 4;k++)
{
switch(k)
{
    case 0:
        printf("%d-%d | ",90,100);
        break;
    case 1:
        printf("%d-%d  | ",80,89);
        break;
    case 2:
        printf("%d-%d  | ",70,79);
        break;
    case 3:
        printf("%d-%d  | ",60,69);
        break;
    case 4:
        printf("%d-%d   | ",0,59);
        break;
}
for(int j = 0;j < scoreband[k];j++)
{
    printf("#");
}
for(int j = scoreband[k];j < num;j++)
{
    printf(" ");
}
printf("     %d 人\n",scoreband[k]);
}
printf("\n");
//打印降序排列
printf("降序排列: ");
for(int i = 0;i < num;i++)
{
    printf("%d ",score[i]);
}
printf("\n");
//打印中位数
printf("中位数: ");
if(num % 2 == 0)//有偶数个
{
    median = ((double)(score[num / 2 - 1] + score[num / 2]) /2.0);//注意数组是从0开始的
    printf("%.2f\n",median);
}
else//有奇数个
{
    median = (double)score[num / 2];
    printf("%.2f\n",median);
}
//打印方差variance
for(int i = 0;i < num;i++)
{
    variance += ((double)score[i] - ave) * ((double)score[i] - ave);
}
variance /= num;
printf("方差: %.2f",variance);


return 0;
}
