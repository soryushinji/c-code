/* 第10题_数字分析工具箱
   自测册第 10 题
   来源：D:\code\.vscode\new day.c（原为 main() 内的一段，提取时补了头文件和 main 外壳）
*/

#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<windows.h>
#include<ctype.h>
int main()
{
int ch;
int data[100] = {0};
int num = 0;
int input = 0;
int count = 0;
int order = 0;
int search = 0;
int dudup = 0;
int histogram = 0;
int reverse = 0;
int output = 0;
printf("================= 数字分析工具箱 =================\n");
printf("\n");
printf("1) 录入数据      2) 显示统计      3) 升序排序\n");
printf("4) 查找数值      5) 去重显示      6) 显示直方图\n");
printf("7) 反转显示      8) 显示全部数据  9) 退出\n");
printf("\n");
printf("==================================================\n");
while(1)
{
int button = 0;
printf("请选择 > ");
ch = getchar();
printf("\n");
while(ch == ' ' || ch == '\t')
{
    ch = getchar();
}
if(ch == EOF)
{
    break;
}
if(ch < '1' || ch > '9')
{
    printf("错误,请输入主菜单提供的选项!\n");
    printf("\n");
    while(ch != '\n' && ch != EOF) ch = getchar();
    continue;
}
else
{
    while(ch >= '1' && ch <= '9')
    {
        button = button * 10 + (ch - '0');
        ch = getchar();
    }
}
while(ch == ' ' || ch == '\t')
{
    ch = getchar();
}
if(ch != '\n')
{
    printf("错误,请输入主菜单提供的选项!\n");
    printf("\n");
    while(ch != '\n' && ch != EOF) ch = getchar();
    continue;
}
if(button > 9)
{
    printf("错误,请输入主菜单显示的选项!\n");
    printf("\n");
    continue;
}
if((button >= 2 && button <= 8) && num == 0)
{
    printf("[提示] 还没有数据，请先使用选项 1 录入数据。\n");
    printf("\n");
    continue;
}
switch(button)
{
case 1:
{
    int pin = 0;
    printf("请输入整数(输入 -1 结束,最多 100 个):\n");
    while(1)
    {
        int neg = 0;
        int digit = 0;
        if(pin != 0)
        {
            printf("请输入整数:\n");
        }
        pin = 0;
        ch = getchar();
        if(ch == EOF)
        {
            break;
        }
        while(ch == ' ' || ch == '\t')
        {
            ch = getchar();
        }
        while(ch == '\n')
        {
            ch = getchar();
        }
        if(ch == '+' || ch == '-')
        {
            if(ch == '-')
            {
                neg = 1;
            }
            ch = getchar();
        }
        if(ch < '0' || ch > '9')
        {
            printf("错误,请输入整数!\n");
            printf("请从错误的地方开始输入数据\n");
            pin++;
            while(ch != '\n' && ch != EOF) ch = getchar();
            continue;
        }
        while(ch >= '0' && ch <= '9')
        {
            digit = digit * 10 + (ch - '0');
            ch = getchar();
        }
        if((ch < '0' || ch > '9') && ch != ' ' && ch != '\t' && ch != '\n')
        {
            printf("错误,请输入整数!\n");
            printf("请从错误的地方开始输入数据\n");
            pin++;
            while(ch != '\n' && ch != EOF) ch = getchar();
            continue;
        }
        if(neg)
        {
            digit = -digit;
        }
        if(digit == -1)
        {
            break;
        }
        if(digit > 2147483647)
        {
            printf("数据超过最大值,请重新输入\n");
            printf("请从超值的地方开始输入数据\n");
            continue;
        }
        if(digit < -2147483648)
        {
            printf("数据超出最小值,请重新输入\n");
            printf("请从超值的地方开始输入数据\n");
            continue;
        }
        if(num >=100)
        {
            printf("[提示]已满100个\n");
            break;
        }
        data[num] = digit;
        num++;
    }
    printf("已录入 %d 个数据\n",num);
    input++;
    break;
}
case 2:
{
    printf("=== 统计信息 ===\n");
    printf("个数: %d\n",num);
    int total = 0;
    for(int i = 0;i < num;i++)
    {
        total += data[i];
    }
    printf("总和: %d\n",total);
    double ave = (double)total / (double)num;
    printf("平均: %.2f\n",ave);
    int data2[100] = {0};
    for(int i = 0;i < num;i++)
    {
        data2[i] = data[i];
    }
    int max = 0;
    for(int i = 0;i < num;i++)
    {
        for(int j = i + 1;j < num;j++)
        {
            if(data2[i] <= data2[j])
            {
                max = data2[j];
                data2[j] = data2[i];
                data2[i] = max;
            }
        }
    }
    printf("最大值: %d\n",data2[0]);
    printf("最小值: %d\n",data2[num - 1]);
    count++;
    break;
}
case 3:
{
    printf("升序后的数据显示为:\n");
    int data3[100] = {0};
    for(int i = 0;i < num;i++)
    {
        data3[i] = data[i];
    }
    int min = 0;
    for(int i = 0;i < num;i++)
    {
        for(int j = i + 1;j < num;j++)
        {
            if(data3[i] >= data3[j])
            {
                min = data3[j];
                data3[j] = data3[i];
                data3[i] = min;
            }
        }
        printf("%d ",data3[i]);
        if((i + 1) % 10 == 0)
        {
            printf("\n");
        }
    }
    printf("\n");
    order++;
    break;
}
case 4:
{
    int cancel  = 0;
    int pin4 = 0;
    int digit4 = 0;
    printf("请输入您要查找的值: ");
    while(1)
    {
        digit4 = 0;
        int neg4 = 0;
        if(pin4 != 0)
        {
            printf("请输入您要查找的值:");
        }
        pin4 = 0;
        ch = getchar();
        if(ch == EOF)
        {
            cancel = 1;
            break;
        }
        while(ch == ' ' || ch == '\t')
        {
            int find = 0;
            ch = getchar();
        }
        if(ch == '+' || ch == '-')
        {
            if(ch == '-')
            {
                neg4 = 1;
            }
            ch = getchar();
        }
        if(ch < '0' || ch > '9')
        {
            printf("错误,请重新输入!\n");
            pin4++;
            while(ch != '\n' && ch != EOF) ch = getchar();
            continue;
        }
        while(ch >= '0' && ch <= '9')
        {
            digit4 = digit4 * 10 + (ch - '0');
            ch = getchar();
        }
        while(ch == ' ' || ch == '\t')
        {
            ch = getchar();
        }
        if((ch < '0' || ch > '9') && ch != '\n')
        {
            printf("错误,请重新输入!\n");
            pin4++;
            while(ch != '\n' && ch != EOF) ch = getchar();
            continue;
        }
        if(neg4)
        {
            digit4 = -digit4;
        }
        if(digit4 > 2147483647)
        {
            printf("数据超过最大值,请重新输入\n");
            continue;
        }
        if(digit4 < -2147483648)
        {
            printf("数据超出最小值,请重新输入\n");
            continue;
        }
        break;
    }
    int count4 = 0;
    int i4[100] = {0};
    int j4 = 0;
    for(int i = 0;i < num;i++)
    {
        if(digit4 == data[i])
        {
            count4++;
            i4[j4] = i;
            j4++;
        }
    }
    if(count4 == 0)
    {
        printf("您要查找的值在录入的数据中不存在\n");
    }
    else
    {
        printf("找到了 %d 处 ,位置分别是",count4);
        for(int i = 0;i < count4;i++)
        {
            if(i == count4 - 1)
            {
                if(count4 > 1)
                {
                    printf("和");
                }
                printf("第 %d 个",i4[i] + 1);
            }
            else if(i == count4 - 2)
            {
                printf("第 %d 个",i4[i] + 1);
            }
            else
            {
                printf("第 %d 个,",i4[i] + 1);
            }
        }
    }
    printf("\n");
    if(cancel == 1)
    {
        search++;
        break;
    }
    search++;
    break;
}
case 5:
{
    printf("去重后(保持原有顺序):\n");
    int data5[100] = {0};
    for(int i = 0;i < num;i++)
    {
        data5[i] = data[i];
    }
    for(int i = 0;i < num;i++)
    {
        for(int j = i + 1;j < num;j++)
        {
            if(data5[i] == data5[j])
            {
                data5[j] = -1;
            }
        }
    }
    for(int i = 0;i < num;i++)
    {
        if(data5[i] != -1)
        {
            printf("%d ",data5[i]);
        }
        if((i + 1) % 10 == 0)
        {
            printf("\n");
        }
    }
    printf("\n");
    dudup++;
    break;
}
case 6:
{
    int binum = 0;
    int data6[100] = {0};
    for(int i = 0;i < num;i++)
    {
        data6[i] = data[i];
    }
    int max6 = 0;
    for(int i = 0;i < num;i++)
    {
        for(int j = i + 1;j < num;j++)
        {
            if(data6[i] <= data6[j])
            {
                max6 = data6[j];
                data6[j] = data6[i];
                data6[i] = max6;
            }
        }
    }
    max6 = data6[0];
    int min6 = data6[num - 1];
    if((max6 - min6 + 1) < 10)
    {
        binum = max6 - min6 + 1;
    }
    else
    {
        binum = 10;
    }
    int binwidth = (max6 - min6 + binum) / binum;
    int bin[10] = {0};
    for(int i = 0;i < binum;i++)
    {
        int note = 0;
        for(int j = 0;j < num;j++)
        {
            if(data[j] >= (min6 + i * binwidth) && data[j] <= (min6 + (i + 1) * binwidth - 1))
            {
                note++;
            }
        }
        bin[i] = note;
    }
    printf("直方图(按数值范围分 %d 档，档宽 %d):\n",binum,binwidth);
    for(int i = 0;i < binum;i++)
    {
        printf("%-10d-%10d | ",min6 + i * binwidth,min6 + (i + 1) * binwidth - 1);
        for(int j = 0;j < bin[i];j++)
        {
            printf("#");
        }
        for(int k = 0;k < num - bin[i];k++)
        {
            printf(" ");
        }
        printf("%d 个\n",bin[i]);
    }
    histogram++;
    break;
}
case 7:
{
    printf("反转显示:\n");
    int i7 = 1;
    for(int i = num - 1;i >= 0;i--)
    {
        printf("%d ",data[i]);
        if(i7 % 10 == 0)
        {
            printf("\n");
        }
        i7++;
    }
    printf("\n");
    reverse++;
    break;
}
case 8:
{
    printf("当前数组(按录入顺序):\n");
    for(int i = 0;i < num;i++)
    {
        printf("%d ",data[i]);
    }
    printf("\n");
    output++;
    break;
}
}
if(button == 9)
{
    break;
}
}
printf("本次会话使用情况:\n");
printf("录入 %d 次,统计 %d 次,排序 %d 次,查找 %d 次,\n",input,count,order,search);
printf("去重 %d 次,直方图 %d 次,反转 %d 次,显示 %d 次。\n",dudup,histogram,reverse,output);
printf("再见~~\n");
     return 0;
}
