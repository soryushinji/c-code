#include<stdio.h>
int main()
{
    // int age;
    // printf("please enter your age:");
    // scanf("%d",&age);
    // int days = age * 365;
    // printf("You have been alive for %d days.\n",days);

    // int ch;                              /* ⚠ 必须 int，不能 char */
    // int count = 0;
 
    // printf("随便输入点什么，按 Ctrl+Z 再回车结束（Linux/macOS 按 Ctrl+D）：\n");
 
    // while ((ch = getchar()) != EOF) {    /* 一直读到「文件结尾」 */
    //     putchar(ch);                     /* 原样输出（回显） */
    //     count++;
    // }
    // printf("\n共读了 %d 个字符。\n", count);
    // int num = 0;
    // scanf("%d",&num);
    // if(num == 1)
    // {
    //     printf("num为一");
    // }
    // else  if(num < 2)
    // {
    //     printf("num为一但也小于二");
    // }
    // int ch;
    // ch = getchar();
    // while(ch != EOF)
    // {
    //     if(ch == ' ')
    //     {
    //         continue;
    //     }
    // }
    // printf("%*d",97,-14);


int ch;
int data[100] = {0};//录入的数据存放在这个数组中
int num = 0;//记录输入数据的数量
int input = 0;//记录录入数据次数
int count = 0;//记录显示统计次数
int order = 0;//记录升序排序次数
int search = 0;//记录查找数值次数
int dudup = 0;//记录去重显示次数
int histogram = 0;//记录显示直方图次数
int reverse = 0;//记录反转显示次数
int output = 0;//记录输出录入数据次数
printf("================= 数字分析工具箱 =================\n");
printf("\n");
printf("1) 录入数据      2) 显示统计      3) 升序排序\n");
printf("4) 查找数值      5) 去重显示      6) 显示直方图\n");
printf("7) 反转显示      8) 显示全部数据  9) 退出\n");
printf("\n");
printf("==================================================\n");
while(1)//最外层大循环
{
int button = 0;//记录每轮选择的数字,每轮开始清零
printf("请选择 > ");//每一轮选择数字
ch = getchar();//开始输入选择的数字
printf("\n");
//允许一开始输入多个空格
while(ch == ' ' || ch == '\t')
{
    ch = getchar();
}
//如果输入EOF
if(ch == EOF)
{
    break;//直接跳出循环
}
//不允许输入任何非数字字符,直接输入\n也不行,输入0也不行,01这种也不行
if(ch < '1' || ch > '9')
{
    printf("错误,请输入主菜单提供的选项!\n");
    printf("\n");
    //清空缓冲区
    while(ch != '\n' && ch != EOF) ch = getchar();
    continue;
}
else//输入1-9
{
    while(ch >= '1' && ch <= '9')
    {
        button = button * 10 + (ch - '0');//记录输入的数字
        ch = getchar();
    }
}
//如果输入1-9之后输入其他
//1)输入空格,允许
while(ch == ' ' || ch == '\t')
{
    ch = getchar();
}
//2)输入非空格非换行符字符,如1abc
if(ch != '\n')
{
    printf("错误,请输入主菜单提供的选项!\n");
    printf("\n");
    //清空缓冲区
    while(ch != '\n' && ch != EOF) ch = getchar();
    continue;
}
//3)输入换行符,输入结束
//看输入的选项
//1)选项>9
if(button > 9)
{
    printf("错误,请输入主菜单显示的选项!\n");
    printf("\n");
    continue;//重新开始选项,不用清理缓冲区
}
if((button >= 2 && button <= 8) && num == 0)//没录入数据就选择2-8
{
    printf("[提示] 还没有数据，请先使用选项 1 录入数据。\n");
    printf("\n");
    continue;//重新循环
}
//选1录入数据或录入数据后选2-8
switch(button)//switch小循环
{
case 1:
{
    int pin = 0;//输入错误重新输入时出现提示的记号
    printf("请输入整数(输入 -1 结束,最多 100 个):\n");
    //开始录入数字
    while(1)//录数字循环,条件暂定为1
    { 
        int num1 = 0;//记录位数,位数过大,报错
        int neg = 0;//记录输入+-的情况
        int digit = 0;//用于记录每次输入的数字
        if(pin != 0)
        {
            printf("请输入整数:\n");
        }
        pin = 0;//每轮在输入这段话之后清零,防止对后面造成影响
        ch = getchar();
        //经典每轮都要清理EOF,这个不能忘
        if(ch == EOF)
        {
            break;//直接跳出循环
        }
        //允许输入多个空格
        while(ch == ' ' || ch == '\t')
        {
            ch = getchar();
        }
        //如果一开始输入\n或是输入数字+\n,将\n从缓冲区里清除
        while(ch == '\n')//不需要清除,这样在输入整数时可随意空格,换行,直到输入-1或是非整数
        {
            ch = getchar();
        }//如果清除换行的放在清空格的前面,当输入数字+空格+换行时,读完数字下轮循环时因为是空格在前就会跳过
         //清除换行的代码,清除了空格之后还剩换行被当作非数字字符（虽然它也确实是）报错
        //输入+-号的情况
        if(ch == '+' || ch == '-')
        {
            if(ch == '-')
            {
                neg = 1;
            }
            ch = getchar();
        }
        //输入非数字字符的情况
        if(ch < '0' || ch > '9')
        {
            printf("错误,请输入整数!\n");
            printf("请从错误的地方开始输入数据\n");
            pin++;
            //清理缓冲区
            while(ch != '\n' && ch != EOF) ch = getchar();
            continue;
        }
        //输入数字
        while(ch >= '0' && ch <= '9')
        {
            digit = digit * 10 + (ch - '0');
            num1++;//确定位数
            ch = getchar();
        }
        //输入数字之后
        //因为是类似:12 23 23 32 42这样输入数字+空格+数字...的形式
        //所以数字之后读到空格就重新开始循环
        //如果数字后面是非空非换行格字符
        if((ch < '0' || ch > '9') && ch != ' ' && ch != '\t' && ch != '\n')
        {
            printf("错误,请输入整数!\n");
            printf("请从错误的地方开始输入数据\n");
            pin++;
            //清空缓冲区
            while(ch != '\n' && ch != EOF) ch = getchar();
            continue;
        }
        //如果输入空格
        //重新循环,是要重新循环,但要先把后面的运行一遍
        // if(ch == ' ' || ch == '\t')//这样会导致数据的丢失
        // {
        //     continue;
        // }
        //如果输入\n
        //所有输入的东西到了缓冲区里,在循环里运行
        //现在所有的问题均排场,到这说明成功输入了数字
        //如果是负数,要给digit转负
        if(neg)
        {
            digit = -digit;
        }
        //如果是-1,退出
        if(digit == -1)
        {
            break;
        }
        //如果超过int的范围
        if(num1 > 9)
        {
            printf("数据超出范围,请重新输入\n");
            printf("请从超值的地方开始输入数据\n");
            //清空缓冲区
            while(ch != '\n' && ch != EOF) ch = getchar();
            continue;
        }
        //如果超过数组范围
        if(num >=100)
        {
            printf("[提示]已满100个\n");
            break;//跳出循环
        }
        data[num] = digit;//将输入的数字录给数组,先看超没超,再给数组赋值
        num++;//能运行到这说明成功录入了一个数据,数组的下标+1
    }//录数字循环结束
    printf("已录入 %d 个数据\n",num);
    //检查数据是否录入
    // for(int i = 0;i < num;i++)
    // {
    //     printf("%d ",data[i]);
    // }//成功录入
    input++;
    break;
}
case 2://显示统计信息（个数、总和、平均分、最大值、最小值）
{
    printf("=== 统计信息 ===\n");
    printf("个数: %d\n",num);
    //计算输入数据的总和
    int total = 0;
    for(int i = 0;i < num;i++)
    {
        total += data[i];
    }
    printf("总和: %d\n",total);
    //打印平均数
    double ave = (double)total / (double)num;
    printf("平均: %.2f\n",ave);
    //打印最大值,最小值
    //先排序,必须输出的是当前的状态,且不能改变原数列的状态
    int data2[100] = {0};//设置一个替代数组
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
case 3://升序排序并显示(每十个一组显示)
{
    printf("升序后的数据显示为:\n");
    int data3[100] = {0};//设置一个替代数组
    for(int i = 0;i < num;i++)
    {
        data3[i] = data[i];
    }
    //先升序
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
        //再打印
        //数组位数不一,怎么打印的一致整齐,算了
        printf("%d ",data3[i]);
        if((i + 1) % 10 == 0)//每打印10个换行
        {
            printf("\n");
        }
    }
    if(num % 10 != 0)//★ 只有最后一行没满 10 个才补换行，否则会多一个空行
    {
        printf("\n");
    }
    order++;
    break;
}
case 4://查找某个值
{
    int cancel  = 0;
    int pin4 = 0;
    int digit4 = 0;
    int num4 = 0;//★ 数位数，用来判断有没有超出 int 范围
    printf("请输入您要查找的值: ");
    //输入查找的数据,又要考虑那一堆
    while(1)//还是要循环。。。
    {
        digit4 = 0;
        num4 = 0;//★ 每轮清零
        int neg4 = 0;//+-号,你懂的
        if(pin4 != 0)
        {
            printf("请输入您要查找的值:");
        }
        pin4 = 0;
        ch = getchar();
        //EOF,不多说了
        if(ch == EOF)
        {
            cancel = 1;
            break;//直接结束
        }
        //允许一开始输入多个空格
        while(ch == ' ' || ch == '\t')
        {
            ch = getchar();
        }
        //输入+-号
        if(ch == '+' || ch == '-')
        {
            if(ch == '-')
            {
                neg4 = 1;
            }
            ch = getchar();
        }
        //如果输入非数字
        if(ch < '0' || ch > '9')
        {
            printf("错误,请重新输入!\n");
            pin4++;
            //清空缓冲区
            while(ch != '\n' && ch != EOF) ch = getchar();
            continue;
        }
        //输入数字
        while(ch >= '0' && ch <= '9')
        {
            digit4 = digit4 * 10 + (ch - '0');
            num4++;//★ 数位数
            ch = getchar();
        }
        //输入数字之后
        //可以继续输入空格
        while(ch == ' ' || ch == '\t')
        {
            ch = getchar();
        }
        //不能输入其他字符,除了换行符
        if((ch < '0' || ch > '9') && ch != '\n')
        {
            printf("错误,请重新输入!\n");
            pin4++;
            //清空缓冲区
            while(ch != '\n' && ch != EOF) ch = getchar();
            continue;
        }
        //输入\n,结束
        //是负数
        if(neg4)
        {
            digit4 = -digit4;
        }
        //不能超值
        if(num4 > 9)//★ 10 位数一定超出 int（int 最大 10 位但不超过 2147483647）
        {
            printf("数据超出范围,请重新输入\n");
            continue;
        }
        break;//能顺利运行到这说明输入了一个合格的数字
    }
    //开始对比查找
    int count4 = 0;//相同数据出现的次数
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
    if(count4 == 0)//没有
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
    if(cancel == 1)//★ 取消了（EOF）就不算一次查找
    {
        break;
    }
    search++;
    break;
}
case 5://去重显示
{
    printf("去重后(保持原有顺序):\n");
    //生成一个影武者数组
    int data5[100] = {0};
    for(int i = 0;i < num;i++)
    {
        data5[i] = data[i];
    }
    //找重复
    for(int i = 0;i < num;i++)
    {
        for(int j = i + 1;j < num;j++)
        {
            if(data5[i] == data5[j])
            {
                data5[j] = -1;//将所有有重复只保留一项,剩下的都赋值-1(数据中没有-1)
            }
        }
    }
    //去重显示
    int n5 = 0;//打印时换行的标志
    for(int i = 0;i < num;i++)
    {
        if(data5[i] != -1)
        {
            printf("%d ",data5[i]);
            n5++;
        }
        if((n5 % 10 == 0)  && n5 != 0)//每十个换行
        {
            printf("\n");
            n5 -= 10;//换行时n5清零,重新判断
        }
    }
    if(n5 != 0)//★ 只有最后一行没满 10 个才补换行，否则会多一个空行
    {
        printf("\n");
    }
    dudup++;
    break;
}
/* ===== 下面是原版 case 6（保留备查，已被 #if 0 屏蔽）===== */
#if 0
case 6://显示直方图
{
    int binum = 0;//档数
    //算档数还要先求出最大值和最小值,哎
    int data6[100] = {0};//设置一个替代数组
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
    //算出了最大值最小值
    //计算档数
    if((max6 - min6 + 1) < 10)
    {
        binum = max6 - min6 + 1;
    }
    else
    {
        binum = 10;
    }
    int binwidth = (max6 - min6 + binum) / binum;//档宽
    int bin[10] = {0};//第i档(i从0开始),各档区间: [最小值 + i * 档宽, 最小值 + (i+1) * 档宽 - 1]
    //将数据计入各档
    for(int i = 0;i < binum;i++)
    {
        int note = 0;//记录data中的数据是否在该档区间
        for(int j = 0;j < num;j++)
        {
            if(data[j] >= (min6 + i * binwidth) && data[j] <= (min6 + (i + 1) * binwidth - 1))
            {
                note++;
            }
        }
        bin[i] = note;
    }
    //计入完毕
    //开始打印直方图
    //如果没录入数组,不可能
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
        printf("  %d 个\n",bin[i]);
    }
    histogram++;
    break;
}
#endif

/* ==================== case 6 改进版 ====================
   两个 bug 的修法：
     ① 标签宽度改成【动态计算】——用最大值的位数当宽度，
        既不会因为数字变大而不齐，也不会白占 20 多列
        （%*d 的用法见原书 4.4.6《printf() 和 scanf() 的 * 修饰符》）
     ② 柱子上限 maxbar 格，数据超过就按比例缩放，
        保证一行不超过 80 列，人数不会被挤到下一行
   ======================================================== */
case 6://显示直方图（改进版：动态标签宽度 + 柱子按比例缩放）
{
    int binum = 0;//档数
    int i6, j6;
    int data6[100] = {0};//设置一个替代数组

    for(i6 = 0;i6 < num;i6++)
    {
        data6[i6] = data[i6];
    }

    //求最大值最小值（用副本排序，不动原数组）
    int max6 = 0;
    for(i6 = 0;i6 < num;i6++)
    {
        for(j6 = i6 + 1;j6 < num;j6++)
        {
            if(data6[i6] <= data6[j6])
            {
                max6 = data6[j6];
                data6[j6] = data6[i6];
                data6[i6] = max6;
            }
        }
    }
    max6 = data6[0];
    int min6 = data6[num - 1];

    //计算档数
    if((max6 - min6 + 1) < 10)
    {
        binum = max6 - min6 + 1;
    }
    else
    {
        binum = 10;
    }

    int binwidth = (max6 - min6 + binum) / binum;//档宽
    int bin[10] = {0};
    //将数据计入各档
    for(i6 = 0;i6 < binum;i6++)
    {
        int note = 0;
        for(j6 = 0;j6 < num;j6++)
        {
            if(data[j6] >= (min6 + i6 * binwidth) && data[j6] <= (min6 + (i6 + 1) * binwidth - 1))
            {
                note++;
            }
        }
        bin[i6] = note;
    }

    // ---------- ★ 新增 1：算标签宽度 = 最大值的位数 ----------
    int w = 1;
    {
        int t = (max6 >= 0) ? max6 : -max6;
        while(t >= 10)
        {
            w++;
            t /= 10;
        }
    }
    // （负数还要多留一位放负号）
    if(min6 < 0)
    {
        w++;
    }

    // ---------- ★ 新增 2：柱子上限 + 比例缩放 ----------
    int maxbar = 45;//柱子最长 45 格（80 列 - 标签 - 人数）
    //缩放基准用【最大的那一档】，不是总数 num —— 否则柱子会很短
    int maxbin = 0;
    for(i6 = 0;i6 < binum;i6++)
    {
        if(bin[i6] > maxbin)
        {
            maxbin = bin[i6];
        }
    }
    int scale = (maxbin + maxbar - 1) / maxbar;//每格代表几个人
    if(scale < 1)
    {
        scale = 1;
    } 
    if(scale > 1)
    {
        printf("直方图(按数值范围分 %d 档，档宽 %d,每格 = %d 个):\n", binum, binwidth, scale);
    }
    else
    {
        printf("直方图(按数值范围分 %d 档，档宽 %d):\n", binum, binwidth);
    }

    for(i6 = 0;i6 < binum;i6++)
    {
        int lo = min6 + i6 * binwidth;
        int hi = min6 + (i6 + 1) * binwidth - 1;
        int bars = (bin[i6] + scale - 1) / scale;//向上取整，有数据至少画 1 格

        printf("%*d-%*d | ", w, lo, w, hi);//★ 动态宽度，自动对齐
        for(j6 = 0;j6 < bars;j6++)
        {
            printf("#");
        }
        for(j6 = bars;j6 < maxbar;j6++)
        {
            printf(" ");
        }
        printf(" %d 个\n", bin[i6]);
    }
    histogram++;
    break;
}
case 7://反转显示
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
    if(num % 10 != 0)//★ 只有最后一行没满 10 个才补换行
    {
        printf("\n");
    }
    reverse++;
    break;
}
case 8://按[录入时的顺序]输出当前数组里的内容
{
    printf("当前数组(按录入顺序):\n");
    int n8 = 0;//★ 已打印个数，用来控制每 10 个换行
    for(int i = 0;i < num;i++)
    {
        printf("%d ",data[i]);
        n8++;
        if(n8 % 10 == 0)//★ 每 10 个换行，避免 100 个数挤成一行导致折行
        {
            printf("\n");
        }
    }
    if(n8 % 10 != 0)//★ 最后一行不满 10 个才补换行
    {
        printf("\n");
    }
    output++;
    break;
}
}//switch小循环结束
//选择9直接退出
if(button == 9)
{
    break;
}
}//大循环结束
printf("本次会话使用情况:\n");
printf("录入 %d 次,统计 %d 次,排序 %d 次,查找 %d 次,\n",input,count,order,search);
printf("去重 %d 次,直方图 %d 次,反转 %d 次,显示 %d 次。\n",dudup,histogram,reverse,output);
printf("再见~~\n");
//十道前8章综合题结束~~


    return 0;
}