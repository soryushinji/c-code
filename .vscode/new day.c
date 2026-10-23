#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<windows.h>
#include<ctype.h>
#include<math.h>
// int main()
// {
    // float salary;

    // printf("\aEnter your desired monthly salary:");
    // printf(" $_______\b\b\b\b\b\b\b");
    // scanf("%f", &salary);
    // printf("\n\t$%.2f a month is $%.2f a year.", salary, salary * 12.0);
    // printf("\rGee!\n");
    //printf("%o",32);
    // char arr[100];
    // printf("Enter a string: ");
    // scanf("%99s", arr);
    // printf("You entered: %s\n", arr);
//     int i;
//     printf("请输入一个整数：");
//     scanf("%d",&i);
//     int j = i;
//     while( i >= 1)
//     {
//         int a = i % 10;
//         printf("%d\n", a);
//         i = i / 10;
//     }
//     printf("反转\n");
//     int c = 10;
//    while(j / c >= 10)
//    {
//        c *= 10;
//    }
//     while( j >= 1)
//     {
//         int b =j / c;
//         printf("%d\n", b);
//         j = j % c;
//         c = c / 10;
//     }
// int a = 0;
// for(int i = 1;i <= 100;i++)
// {
//     if(i % 3 == 0)
//     {
//         a = a + i;
//     }

   

// }
    // printf("Sum of multiples of 3 from 1 to 100 is: %d\n", a);

// for(int i = 2;i <= 1200;i++)
// {
//     int a = 2;
//     while(a < i)

//     {
//         if(i % a == 0)
//         {
//             a = 0;
//             break;
//         }
//         a++;
//     }

//     if(a)
//     {
//         printf("%d\n", i);
//     }
// }

// a:
// printf("请输入一个整数：");
// int i;  
// scanf("%d",&i);
// printf("您输入的整数是：%d\n",i);
// goto a;
// int i = 0;
// int arr[3][5] = {1,2,6,7,10,14,15};
// for(i = 0;i < 3;i++)
// {
//     int j = 0;
//     for(j = 0;j < 5;j++)
//     {
//         scanf("%d",&arr[i][j]);
//     }
// }
// for(i = 0;i < 3;i++)
// {
//     int j = 0;
//     for(j = 0;j < 5;j++)
//     {
//         printf("%d ",arr[i][j]);
//     }
//     printf("\n");
// }
// int num = sizeof(arr) / sizeof(arr[0][0]);
// printf("Total number of elements: %d\n", num);
//welcome to bit!!!!!
//################### 19
// char arr[19][19];
// int i = 0;
// int k = 0;
// int a = 19;
// for(i = 0;i < 19;i++)
// {
    
//         for(int j = 0;j < a;j++)
//     {
//         arr[j][k] = '#';
//         printf("%c ", arr[j][k]);
//     }
//     printf("\n");
//     k++;
//     a--;
// }
// char text[1024];

//     printf("请输入一段话：");
//     if (fgets(text, sizeof(text), stdin) == NULL) {
//         return 1;
//     }

//     // 去掉 fgets 读入的末尾换行符
//     size_t len = strlen(text);
//     if (len > 0 && text[len - 1] == '\n') {
//         text[len - 1] = '\0';
//         len--;
//     }

//     int n = (int)len;

//     // i 表示左右两边各保留的字符数
//     for (int i = 0; i <= (n + 1) / 2; i++) {
//         for (int j = 0; j < n; j++) {
//             // 左边保留 i 个字符，右边保留 i 个字符
//             if (j < i || j >= n - i) {
//                 putchar(text[j]);
//             } else {
//                 putchar('#');
//             }
//         }
//         putchar('\n');
//     }

// char text[] = "sweet death!!!!";
// char text1[] = "###############";
// int n = strlen(text) - 1;
// int m = 0;
// while(m <= n)
// {
//     text1[m] = text[m];
//     text1[n] = text[n];
//     printf("%s\n", text1);
//     sleep(1);
//     system("cls"); 
//     m++;
//     n--;
// }
// printf("%s\n", text1);
// char test1[1024]; 
// char test2[1024];
// printf("请输入一段话：");
// fgets(test1,sizeof(test1),stdin);
// int num = strlen(test1);
// int i = 0;
// while(i <= num - 2)
// {
//     test2[i] = '#';
//     i++;
// }
// int left = 0;
// int right = num - 2;
// while(left <= right)
// {
//     test2[left] = test1[left];
//     test2[right] = test1[right];
//     left++;
//     right--;
//     sleep(1);
//     system("cls");
//     printf("%s\n", test2);
// }
//查找数字
// int number;
// printf("请输入数组的长度：");
// scanf("%d", &number);
// int arr[number];
// srand((unsigned)time(NULL));
// for(int i = 0;i < number;i++)
// {
//     arr[i] = rand() % (2 * number - 1 + 1);
//     printf("%d ", arr[i]);
// }
// printf("\n");
// printf("该数组从小到大排列为：");
// int min = arr[0];
// for(int i = 0;i < number;i++)
// {
//     for(int j = 1 + i;j < number;j++)
//     {
//         if(arr[i] >= arr[j])
//         {
//             int abc = arr[j];
//             arr[j] = arr[i];
//             arr[i] = abc;
//         }
//     }
// }
// for(int i = 0;i < number;i++)
// {
//     printf("%d ", arr[i]);
// }
// printf("\n");
// printf("请输入您要查找的数字(1-20):");
// int num;
// scanf("%d", &num);
// //逐个查找
// /*int a = 0;
// for(int i = 0;i < number;i++)
// {
//     if(arr[i] == num)
//     {
//         printf("找到了,该数字在调整后的数组中下标为：[%d]\n",i);
//         a++;
//     }
// }
// if(a == 0)
// {
//     printf("没有\n");
// }*/
// //二分查找
// int b = 0;
// int l = 0;
// int r = number - 1;
// int ave = (l + r) / 2;
// while(l <= r)
// {
//     if(num == arr[ave])
//     {
//         //printf("找到了,该数字在调整后的数组中下标为：[%d]\n",ave);
//         b++;
//         break;
//     }
//     else if(num < arr[ave])
//     {
//         r = ave - 1;
//     }
//     else
//     {
//         l = ave + 1;
//     }
//     ave = (l + r) / 2;
// }
// if(b == 0)
// {
//     printf("没有\n");
// }
// else
// {
//     int le = ave;
//     int ri = ave;
//     while(arr[le] == num && le >= 0)
//     {
//         le--;
//     }
//     while(arr[ri] == num && ri < number - 1)
//     {
//         ri++;
//     }
//     for(le + 1;le + 1 <= ri - 1;le++)
//     {
//         printf("找到了,该数字在调整后的数组中下标为：[%d]\n",le);
//     }
// }

// int num;
// int num1;
// int num2 = scanf("%d %d", &num, &num1);
// printf("%d %d %d\n", num, num1, num2);
//6.16 3题
// char arr;
// printf("请输入一个字母：");
// int a = scanf("%c", &arr);
// int num = (int)arr;
// //a97 z122 A65 Z90
// int gin = 97;
// int gin1 = 65;
// if(a == 0)
// {
//     printf("输入错误\n");
// }

// else if(num >= 97 && num <= 122)
// {
//     int b = num;
//     for(num;num >= 97;num--)
//     {
//         for(int i = b;i >= num;i--)
//         {
//             printf("%c", i);
//         }
//         printf("\n");
//     }
// }
// else if(num >= 65 && num <= 90)
// {
//     int c = num;
//    for(num;num >= 65;num--)
//     {
//         for(int i = c;i >= num;i--)
//         {
//             printf("%c", i);
//         }
//         printf("\n");
//     }
// }
// else
// {
//     printf("不是字母\n");
// }
//6.16 4题
// char arr[2];
// printf("请输入两个字母(大小写相同):");
// scanf("%c %c", &arr[0], &arr[1]);
// int num1 = (int)arr[0];
// int num2 = (int)arr[1];
// char temp = arr[0];
// if(num1 > num2)
// {
//     arr[0] = arr[1];
//     arr[1] = temp;
// }
// int i = (int)arr[0];
// int j = (int)arr[1];
// int l = 1;
// while(1)
// {
//     int k = 1;
//     for(int k = 1;k <=l;k++)
//     {
//         printf("%c", i);
//         i++;
//         if(i > j)
//         {
//             goto end;
//         }
//     }
//     printf("\n");
//     l++;
// }
// end:
//6.16 5题
// printf("请输入一个大写字母：");
// char arr;
// scanf("%c", &arr);
// int num = (int)arr - 65;
// int mon = num * 2 + 1;
// for(int i = 0;i <= num;i++)
// {
//     for(int j = i;j <num;j++)
//     {
//         printf(" ");
//     }
//     for(int k = 0;k <= i;k++)
//     {
//         printf("%c", 65 + k);
//     }
//     for(int l = i - 1;l >= 0;l--)
//     {
//         printf("%c", 65 + l);
//     }
//     printf("\n");
// }
// //6.16 11题
// srand((unsigned)time(NULL));
// int num[8];
// for(int i = 0;i < 8;i++)
// {
//     num[i] = rand() % (100 - 1 + 1);
// }
// int max = num[0];
// for(int i = 0;i < 8;i++)
// {
//     for(int j =i + 1;j < 8;j++)
//     {
//         if(num[j] >= num[i])
//         {
//             max = num[j];
//             num[j] = num[i];
//             num[i] = max;
//         }
//     }
// }
// for(int i = 0;i < 8;i++)
// {
//    printf("%d ",num[i]);
// }
//6.16 12题
// int num;
// printf("计算至第(次):");
// scanf("%d",&num);
// double mount = 1.0;
// for(int i = 1;2 * i <= num;i++)
// {
//     double le = -(1.0 / (2 * i));
//     mount += le;
// }
// for(int j = 1;2 * j + 1 <= num;j++)
// {
//     double ri = (1.0 / (2 * j + 1));
//     mount += ri;
// }
// printf("%d项时的总和为:%lf",num,mount);
//6.16 18题
// int num = 5;
// int i = 1;
// while(num < 150)
// {
//     num -= i;
//     num *= 2;
//     printf("第%d周有%d位朋友\n",i,num);
//     i++;
// }
//6.16 14题
// srand((unsigned)time(NULL));
// int num;
// printf("你想要多长的数组：");
// scanf("%d",&num);
// int arr1[num];
// int arr2[num];
// for(int i = 0;i < num;i++)
// {
//     arr1[i] = rand() %(100 -1 + 1);
// }
// int min = arr1[0];
// for(int i = 0;i < num;i++)
// {
//     for(int j = i + 1;j < num;j++)
//     {
//         if(arr1[j] < arr1[i])
//         {
//             min = arr1[j];
//             arr1[j] = arr1[i];
//             arr1[i] = min;
//         }
//     }
// }
// for(int i = 0;i < num;i++)
// {
//     int zero = 0;
//     for(int j = 0;j <= i;j++)
//     {
//         zero += arr1[j];
//     }
//     arr2[i] = zero;
// }
// for(int i = 0;i < num;i++)
// {
//     printf("%d ",arr1[i]);
// }
// printf("\n");
// for(int i = 0;i < num;i++)
// {
//     printf("%d ",arr2[i]);
// }
//7.12 7题
// int hour;
// printf("请输入每周工作的小时数：");
// scanf("%d",&hour);
// double total = 0;
// if(hour <= 40)
// {
//     total = hour * 10;
// }
// else
// {
//     total = hour * 1.5 * 10;
// }
// double paper = 0;
// if(total <= 300)
// {
//     paper = total * 0.85;
// }
// else if(total > 300 && total <= 450)
// {
//     paper = 300 * 0.85 + (total - 300) * 0.8;
// }
// else
// {
//     paper = 300 * 0.85 + 150 * 0.8 + (total - 450) * 0.75;
// }
// printf("您一周的工资总额,税金,净收入分别为:%.2lf$,%.2lf$,%.2lf$",total,total-paper,paper);
//7.12 9题
// printf("请输入一个正整数：");
// int num;
// scanf("%d",&num);
// int i = 2;
// while(i <= num)
// {
//     int k = 0;
//     int j = 2;
//     while(j * j <= i)
//     {
//         if(i % j == 0 && j != i)
//         {
//             k++;
//         }
//         j++;
//     }
//     if(k == 0)
//     {
//         printf("%d ",i);
//     }
//     i++;
// const double yangji = 2.05;
// const double tiancai = 1.15;
// const double huluobo = 1.09;
// // 方法一：用goto语句
// // char key;
// // start:
// // printf("请问您要买(a:洋蓟)(b:甜菜)(c:胡萝卜)(q:退出):");
// // scanf(" %c",&key);
// // double ynum = 0;
// // double tnum = 0;
// // double hnum = 0;
// // switch(key)
// //     {
// //     case 'a':
// //         {
// //             printf("请输入洋蓟的磅数：");
// //             scanf("%lf",&ynum);
// //             goto start;
// //         }
// //     case 'b':
// //         {
// //             printf("请输入甜菜的磅数：");
// //             scanf("%lf",&tnum);
// //             goto start;
// //         }
// //     case 'c':
// //         {
// //             printf("请输入胡萝卜的磅数：");
// //             scanf("%lf",&hnum);
// //             goto start;
// //         }
// //     case 'q':
// //         {
// //             printf("购买结束,即将打印小票");
// //             break;
// //         }
// //         default:
// //         {
// //             printf("请输入正确的字母！");
// //         }
// //     }
// //方法二：用while语句
// char key;
// double ynum = 0;
// double tnum = 0;
// double hnum = 0;
// double amount;
// do
// {
// printf("请问您要买(a:洋蓟)(b:甜菜)(c:胡萝卜)(q:退出):");
// scanf(" %c",&key);
// switch(key)
//     {
//     case 'a':
//         {
//             printf("请输入洋蓟的磅数：");
//             scanf("%lf",&amount);
//             ynum += amount;
//             break;
//         }
//     case 'b':
//         {
//             printf("请输入甜菜的磅数：");
//             scanf("%lf",&amount);
//             tnum += amount;
//             break;
//         }
//     case 'c':
//         {
//             printf("请输入胡萝卜的磅数：");
//             scanf("%lf",&amount);
//             hnum += amount;
//             break;
//         }
//     case 'q':
//         {
//             printf("购买结束,即将打印小票\n");
//             break;
//         }
//         default:
//         {
//             printf("请输入正确的字母！\n");
//             break;
//         }
//     }
// }
// while(key != 'q');



// double total = ynum * yangji + tnum *tiancai + hnum * huluobo;
// double total_cai =total;
// double zhekou = 0;
// if(total >= 100)
// {
//     zhekou = total * 0.05;
//     total *= 0.95;
// }
// double total_dingdan = total;
// double num = ynum + tnum + hnum;
// double yab = 0;
// if(num <= 5)
// {
//     total += 6.5;
//     yab = 6.5;
// }
// else if(num > 5 && num <= 20)
// {
//     total += 14;
//     yab =14;
// }
// else
// {
//     yab = 14 + (num - 20) * 0.5;
//     total += yab;
// }
// printf("***********************************************************************************\n");
// printf("物品售价:洋蓟2.05美元/磅,甜菜1.15美元/磅,胡萝卜1.09美元/磅\n");
// printf("订购的重量(单位:磅):洋蓟(%.2lf),甜菜(%.2lf),胡萝卜(%.2lf)\n",ynum,tnum,hnum);
// printf("订购的蔬菜费用:%.2lf$\n",total_cai);
// printf("订单的总费用:%.2lf$\n",total_dingdan);
// printf("折扣:%.2lf$\n",zhekou);
// printf("运费和包装费:%.2lf$\n",yab);
// printf("总费用:%.2lf$\n",total);
// printf("***********************************************************************************");

//  int c;

//     while ((c = getchar()) != EOF || (c = getchar()) != '\n') 
//     {
//         putchar(c);
//     }
// printf("请随意输入(除中文):");
// int c;
// int alpha = 0;
// int digit = 0;
// int space = 0;
// int enter = 0;
// int punct = 0;
// while((c = getchar()) != '#')
// {
//     if(isalpha(c))
//     {
//         alpha += 1;
//     }
//     else if(isdigit(c))
//     {
//         digit += 1;
//     }
//     else if(ispunct(c))
//     {
//         punct += 1;
//     }
//     else if(c == '\n')
//     {
//         enter += 1;
//     }
//     else if(c == ' ')
//     {
//         space += 1;
//     }
// }
// printf("您输入的话中有字母%d个,数字%d个,标点符号%d个,空格%d个,换行符%d个",alpha,digit,punct,space,enter);

// int ch;
//     int count = 0;

//     printf("请输入一些字符，输入 # 结束：\n");

//     while ((ch = getchar()) != '#' && ch != EOF)
//     {
//         printf("'%c':%d  ", ch, ch);
//         count++;

//         if (count % 8 == 0)
//             putchar('\n');
//     }

//     if (count % 8 != 0)
//         putchar('\n');

//7.12 3题
// int num[1024];
// int num1[1024];
// printf("请输入整数(按零结束):\n");
// int i = 0;
// int j = 0;
// int input;
// while(scanf("%d",&input) == 1 && input != 0)
// {
//     if(input % 2 == 0)
//     {
//         num[i] = input;
//         i++;
//     }
//     else
//     {
//         num1[j] = input;
//         j++;
//     }
// }
// double total = 0.0;
// double total1 = 0.0;
// printf("输入的偶数为:\n");
// for(int k = 0;k < i;k++)
// {
//     printf("%-4d ",num[k]);
//     total += num[k];
//     if((k + 1) % 8 == 0)
//     {
//         printf("\n");
//     }
// }
// printf("\n");
// printf("输入的奇数为:\n");
// for(int k = 0;k < j;k++)
// {
//     printf("%-4d ",num1[k]);
//     total1 += num1[k];
//     if((k + 1) % 8 == 0)
//     {
//         printf("\n");
//     }
// }
// double ave = (i > 0)? total / (double)i : 0.0;
// double ave1 = (j > 0)? total1 / (double)j: 0.0;
// printf("\n");
// printf("****************************************************************\n");
// printf("偶数的个数为：%d,平均值为:%.2lf\n",i,ave);
// printf("奇数的个数为：%d,平均值为:%.2lf\n",j,ave1);
// printf("****************************************************************\n");
//7.12 4 6题
// int c;
// int num1 = 0;
// int num2 = 0;
// int num3 = 0;
// int pre = 0;
// printf("请输入(输入#退出):");
// while((c = getchar()) != EOF && c != '#')
// {
//     if(c == '.')
//     {
//         num1 += 1;
//         putchar('!');
//     }
//     else if(c == '!')
//     {
//         num2 += 1;
//         putchar('!');
//         putchar('!');
//     }
//     else if(pre == 'e' && c == 'i')
//     {
//         num3 += 1;
//         putchar(c);
//     }
//     else
//     {
//     putchar(c);
//     }
//     pre = c;
// }
// printf("\n");
// printf("交替了%d次,ei出现了%d次",num1 + num2,num3);
//8.11 1题
// int num1 = 0;
// int num2 = 0;
// int c;
// while((c = getchar()) != EOF && c != '#')
// {
//     num1++;
//     if(isdigit(c))
//     {
//         num2 += 1;
//     }
//     putchar(c);
// }
// printf("\n");
// printf("在文件结尾之前读到的字符数为%d,数字为%d",num1,num2);

// printf("请随意打印:");
// int c;
// int num = 0;
// int i = 0;
// int j = 0;
// while((c = getchar()) != EOF)
// {
//     if(c == '\n')
//     {
//         putchar('\\');
//         putchar('n');
//         j = (int)'\n';
//         printf(" %d",j);
//         printf("\n");
//         i++;
//     }
//     else if(c == '\t')
//     {
//         putchar('\\');
//         putchar('t');
//         j = (int)'\t';
//         printf(" %d",j);
//         printf("   ");
//         i++;
//     }
//     else
//     {
//         num = (int)c;
//         putchar(c);
//         printf(" %d",num);
//         printf("   ");
//         i++;
//     }
// if(i % 10 == 0 && c != '\n')
// {
//     printf("\n");
// }
// }
// //8.11 8题(不完善)
// start:
// printf("请输入您的选择:\na.加        s.减\nm.乘        d.除\nq.退出\n");
// int c;
// int ch;
// double first;
// double second;
// while((c = getchar()) != EOF && c != 'q')
// {
//     switch(c)
//     {
//         case'a':
//         {
//             printf("请输入第一个数字:");
//             while((scanf(" %lf",&first)) != 1)
//             {
//                 while((ch = getchar()) != '\n')
//                 {
//                     putchar(ch);
//                 }
//                 printf("不是数字");
//                 printf("请输入一个数字,如2.5,-1.78E8或3:");
//             }
//             printf("请输入第二个数字:");
//             while((scanf(" %lf",&second)) != 1)
//             {
//                 while((ch = getchar()) != '\n')
//                 {
//                     putchar(ch);
//                 }
//                 printf("不是数字");
//                 printf("请输入一个数字,如2.5,-1.78E8或3:");
//             }
//             printf("%.2f + %.2f = %.2f\n",first,second,first + second);
//             while (getchar() != '\n')
//             continue;
//             goto start;
//         }
//         case's':
//         {
//             printf("请输入第一个数字:");
//             while((scanf(" %lf",&first)) != 1)
//             {
//                 while((ch = getchar()) != '\n')
//                 {
//                     putchar(ch);
//                 }
//                 printf("不是数字");
//                 printf("请输入一个数字,如2.5,-1.78E8或3:");
//             }
//             printf("请输入第二个数字:");
//             while((scanf(" %lf",&second)) != 1)
//             {
//                 while((ch = getchar()) != '\n')
//                 {
//                     putchar(ch);
//                 }
//                 printf("不是数字");
//                 printf("请输入一个数字,如2.5,-1.78E8或3:");
//             }
//             printf("%.2f - %.2f = %.2f\n",first,second,first - second);
//             while (getchar() != '\n')
//             continue;
//             goto start;
//         }
//         case'm':
//         {
//                         printf("请输入第一个数字:");
//             while((scanf(" %lf",&first)) != 1)
//             {
//                 while((ch = getchar()) != '\n')
//                 {
//                     putchar(ch);
//                 }
//                 printf("不是数字");
//                 printf("请输入一个数字,如2.5,-1.78E8或3:");
//             }
//             printf("请输入第二个数字:");
//             while((scanf(" %lf",&second)) != 1)
//             {
//                 while((ch = getchar()) != '\n')
//                 {
//                     putchar(ch);
//                 }
//                 printf("不是数字");
//                 printf("请输入一个数字,如2.5,-1.78E8或3:");
//             }
//             printf("%.2f * %.2f = %.2f\n",first,second,first * second);
//             while (getchar() != '\n')
//             continue;
//             goto start;
//         }
//         case'd':
//         {
//             printf("请输入第一个数字:");
//             while((scanf(" %lf",&first)) != 1)
//             {
//                 while((ch = getchar()) != '\n')
//                 {
//                     putchar(ch);
//                 }
//                 printf("不是数字");
//                 printf("请输入一个数字,如2.5,-1.78E8或3:");
//             }
//             printf("请输入第二个数字:");
//             while((scanf(" %lf",&second)) != 1 )
//             {
//                 while((ch = getchar()) != '\n')
//                 {
//                     putchar(ch);
//                 }
//                 printf("不是数字");
//                 printf("请输入一个数字,如2.5,-1.78E8或3:");
//             }
//             while(second == 0)
//             {
//                 printf("请输入非零数字");
//                 while (scanf("%lf", &second) != 1)
//                 {
//                     while ((ch = getchar()) != '\n')
//                         putchar(ch);
//                     printf("不是数字");
//                     printf("请输入一个数字，如 2.5, -1.78E8 或 3: ");
//     }
//             }
//             printf("%.2f / %.2f = %.2f\n",first,second,first / second);
//             while (getchar() != '\n')
//             continue;
//             goto start;
//         }
//         default:
//         {
//             printf("输入失败,请重新输入\n");
//             while (getchar() != '\n')
//             continue;
//             break;
//         }

//     }
// }
// printf("再见");
//综合题1
// printf("请输入一个非负整数:");
// long long int num;
// int i = 0;
// int j = 0;
// int max = 0;
// int min  = 9;
// int he = 0;
// int ch;
// long long int ji = 1;
// long long int num1 = 0;
// long long int num2 = 0;
// long long int num3 = 0;
// start:
// if((scanf(" %lld",&num)) != 1 || num < 0)
// {
//     printf("请输入一个非负整数:");
//     while((ch = getchar()) != '\n' && ch != 'EOF')
//         continue;
//     if (ch == EOF) 
//     {                        /* 输入真的结束了 */
//         printf("\n输入结束,程序退出。\n");
//         return 0;
//     }
//     goto start;
// }
// else if(num > 0)
// {
// num3 = num;
// num1 = num;
// while(num1 >= 1)
// {
//     num1 /= 10;
//     j++;
// }
// while(num >= 1)
// {
//     i = num % 10;
//     he += i;
//     ji *= i;
//     if(i <= min)
//     {
//         min = i;
//     }
//     if (i >= max)
//     {
//         max = i;
//     }
//     num2 += i;
//     num2 *= 10;;
//     num /= 10;
// }
// }
// else
// {
//     j = 1;
//     ji = 0;
//     min = 0;
// }
// num2 /= 10;
// printf("位数:%d\n",j);
// printf("各个位数之和:%d\n",he);
// printf("各个位数之积:%lld\n",ji);
// printf("把这个数逆序后得到的新数:%lld\n",num2);
// printf("最大位:%d    最小位:%d\n",max,min);
// if(num2 == num3)
// {
//     printf("是否回文：是");
// }
// else
// {
//     printf("是否回文：否");
// }


// int n;
 
//     while (1) 
//     {
//         printf("请输入 1 到 100 之间的整数：");
 
//         /* ① 检查返回值 */
//         if (scanf("%d", &n) != 1) 
//         {
//             printf("  这不是一个整数，请重新输入。\n");
//             /* ② 清空这一行的残留字符 —— 少了这两行就会死循环 */
//             while (getchar() != '\n')
//                 continue;
//             continue;
//         }
 
//         /* ③ 检查取值范围 */
//         if (n < 1 || n > 100) 
//         {
//             printf("  超出范围了（你输入的是 %d），请重新输入。\n", n);
//             continue;
//         }
 
//         break;                            /* 三重检查都过了，才跳出 */
//     }
 
//     printf("输入合法：%d\n", n);

//综合题2
// int button = 0;
// int ch;
// int h;
// int num1 = 0;
// int num2 = 0;
// start:
// printf("************************************************************************************************\n");
// printf("输出示例\n");
// printf("1) 直角三角形        2) 等腰三角形\n*                     *\n**                   ***\n***                 *****\n****               *******                      ← 等腰三角形共 4 行，第 n 行有 2n-1 个 *\n");
// printf("3) 菱形（h=2 时共 3 行）      4) 数字金字塔（h=4）\n  *                             1\n ***                           121\n  *                           12321\n                             1234321\n");
// printf("5) 退出\n");
// printf("************************************************************************************************\n");
// start1:
// printf("请选择:");

// if((scanf("%d",&button)) != 1 || button <= 0 || button == 5 || button >5)
// {
//     if(button == 5)
//     {
//         goto end;
//     }
//     while((ch = getchar()) != '\n' && ch != EOF)
//     {
//     continue;
//     }
//     printf("无效选项，请重新选择:\n");
//     goto start;
// }
// else
// {
//     printf("请输入高度h(1-15):");
//     start2:
//     if((scanf("%d",&h)) != 1 || h <= 0 || h > 15)
//     {
//         printf("高度必须在 1-15 之间，请重新输入:");
//         while((ch = getchar()) != '\n' && ch != EOF)
//         {
//         continue;
//         }
//         goto start2;
//     }
//     else
//     {
//         while((ch = getchar()) != '\n' && ch != EOF)
//         {
//         continue;
//         }
//         switch(button)
//         {
//         case 1:
//             for(int i = 1;i <= h;i++)
//             {
//                 for(int j = 1;j <= i;j++)
//                 {
//                     printf("*");
//                 }
//                 printf("\n");
//             }
//             num1++;
//             num2 += h;
//             break;
//         case 2:
//             for(int i = 1;i <= h;i++)
//             {
//                 for(int k = i;k <= h - 1;k++)
//                 {
//                     printf(" ");
//                 }
//                 for(int j = 1;j <= 2 * i - 1;j++)
//                 {
//                     printf("*");
//                 }
//                 printf("\n");
//             }
//             num1++;
//             num2 += h;
//             break;
//         case 3:
//             for(int i = 1;i <= (h / 2) + 1;i++)
//             {
//                 for(int m = i;m <= (h / 2) + 1;m++)
//                 {
//                     printf(" ");
//                 }
//                 for(int j = 1;j <= 2 * i - 1;j++)
//                 {
//                     printf("*");
//                 }
//                 printf("\n");
//             }
//             for(int l = (h / 2);l >= 1;l--)
//             {
//                 for(int n = l;n <= (h / 2) + 1;n++)
//                 {
//                     printf(" ");
//                 }
//                 for(int k = 2 * l - 1;k >= 1;k--)
//                 {
//                     printf("*");
//                 }
//                 printf("\n");
//             }
//             num1++;
//             if(h % 2 == 0)
//             {
//                 num2 += h + 1;
//             }
//             else
//             {
//             num2 += h;
//             }
//             break;
//         case 4:
//             for(int i = 1;i <= h;i++)
//             {
//                 for(int k = i;k <= h - 1;k++)
//                 {
//                     printf(" ");
//                 }
//                 for(int j = 1;j <= i;j++)
//                 {
//                     printf("%d",j);
//                 }
//                 for(int m = i - 1;m >= 1;m--)
//                 {
//                         printf("%d",m);
//                 }
//                 printf("\n");
//             }
//             num1++;
//             num2 += h;
//             break;
//         }
//     } 
// }
// goto start1;
// end:
// if(num1 == 0)
// {
// printf("本次共打印 0 个图案，合计 0 行。再见~~\n");
// }
// else
// {
// printf("本次共打印 %d 个图案，合计 %d 行。再见~~\n",num1,num2);
// }

// /* ============================================================================
//    第 2 题　「只用前八章知识」版
//    ----------------------------------------------------------------------------
//    约束：不使用自己定义的函数、不使用指针、不使用数组（字符串以外的）。
//    只用：printf / getchar / 运算符 / while / if / switch / continue / break
//          / 标志变量 / EOF                       （全部出自第 3~8 章）
//    三个要点：
//    ① 不用函数 → 用「一个循环 + need 标记」把「等菜单选择」和「等高度」
//       合并到同一处，避免把读输入的代码写两遍。
//    ② 不用指针 → 放弃 strtol，改用 getchar() **逐字符**读入并当场校验。
//    ③ 不用 goto  → while(!quit) + continue/break；输入结束用 quit 标志退出。
//    ============================================================================ */
//     int patternCount = 0;        /* 共打印了多少个图案 */
//     int totalLines = 0;          /* 共打印了多少行     */
//     int button = 0;              /* 菜单选择 */
//     int h = 0;                   /* 高度     */
//     int need = 0;                /* 0 = 正在等菜单选择；1 = 正在等高度 */
//     int quit = 0;                /* 输入结束标志（标志变量，第 7 章） */
//     /* ---------- 启动时展示一次示例 ---------- */
//     printf("================ 输出示例 ================\n");
//     printf("1) 直角三角形      2) 等腰三角形\n");
//     printf("*                     *\n");
//     printf("**                   ***\n");
//     printf("***                 *****\n");
//     printf("****               *******\n");
//     printf("3) 菱形（h=2 共 3 行）   4) 数字金字塔（h=4）\n");
//     printf("  *                       1\n");
//     printf(" ***                     121\n");
//     printf("  *                     12321\n");
//     printf("                       1234321\n");
//     printf("==========================================\n");
//     while (!quit) 
//     {                       /* ← 主循环：替代 goto */
//         int value = 0;                    /* 本次读到的数值 */
//         int state = 1;                    /* 1=成功  0=非法  2=输入结束 */
//         int digits = 0;                   /* 读到了几位数字 */
//         int neg = 0;                      /* 是不是负数 */
//         int ch;                           /* 必须是 int，才能装下 EOF */
//         /* ---------- ① 提示（由 need 决定问什么） ---------- */
//         if (need == 0) 
//         {
//             printf("------------------------------------------\n");
//             printf("  1) 直角三角形     2) 等腰三角形\n");
//             printf("  3) 菱形           4) 数字金字塔\n");
//             printf("  5) 退出\n");
//             printf("------------------------------------------\n");
//             printf("请选择:");
//         } else 
//         {
//             printf("请输入高度h(1-15):");
//         }
//         /* ---------- ② 逐字符严格读一个整数 ----------
//            不使用任何函数和指针，只用 getchar() 一个字符一个字符地读，
//            读到什么就当场判断什么。                              */
//         do 
//         {                              /* 跳过前导空白（不含换行） */
//             ch = getchar();
//         } while (ch == ' ' || ch == '\t');
//         if (ch == EOF) 
//         {
//             state = 2;                    /* 输入结束了 */
//         } 
//         else 
//         {
//             if (ch == '+' || ch == '-') 
//             { /* 允许正负号 */
//                 neg = (ch == '-');
//                 ch = getchar();
//             }
//             while (ch >= '0' && ch <= '9') 
//             {   /* 收集数字 */
//                 if (digits < 9)                /* 只收 9 位，避免 int 溢出 */
//                     value = value * 10 + (ch - '0');
//                 digits++;
//                 ch = getchar();
//             }
//             while (ch == ' ' || ch == '\t')    /* 允许数字后面跟空白 */
//                 ch = getchar();
//             /* 关键校验：必须读到了数字，且后面除了换行（或输入结束）
//                不能再有任何别的东西。1.5 / 1abc / 1e2 都死在这里。 */
//             if (digits == 0 || digits > 9 || (ch != '\n' && ch != EOF)) 
//             {
//                 state = 0;                     /* 非法 */
//                 while (ch != '\n' && ch != EOF) /* 丢掉本行剩余部分 */
//                     ch = getchar();
//             } 
//             else if (neg) 
//             {
//                 value = -value;
//             }
//         }
//         /* ---------- ③ 按状态决定下一步 ---------- */
//         if (state == 2) 
//         {
//             quit = 1;                          /* 输入结束 → 退出主循环 */
//         } 
//         else if (need == 0) 
//         {                /* 正在处理菜单选择 */
//             if (state == 0 || value < 1 || value > 5) 
//             {
//                 printf("无效选项，请重新选择。\n");
//             } 
//             else if (value == 5) 
//             {
//                 quit = 1;                      /* 选 5 → 退出 */
//             } 
//             else 
//             {
//                 button = value;                /* 记下选择 */
//                 need = 1;                      /* 下次循环改问高度 */
//             }
//         } 
//         else 
//         {                               /* 正在处理高度 */
//             if (state == 0 || value < 1 || value > 15) 
//             {
//                 printf("高度必须是 1 到 15 之间的整数，请重新输入。\n");
//             } 
//             else 
//             {
//                 h = value;
//                 /* ---------- 打印图案（嵌套循环，第 6 章） ---------- */
//                 switch (button) 
//                 {
//                 case 1:                        /* 直角三角形：第 n 行 n 个星号 */
//                     for (int i = 1; i <= h; i++) 
//                     {
//                         for (int j = 1; j <= i; j++)
//                             printf("*");
//                         printf("\n");
//                     }
//                     totalLines += h;
//                     break;
//                 case 2:                        /* 等腰三角形：第 n 行 (h-n) 空格 + (2n-1) 星号 */
//                     for (int i = 1; i <= h; i++) 
//                     {
//                         for (int k = i; k <= h - 1; k++)
//                             printf(" ");
//                         for (int j = 1; j <= 2 * i - 1; j++)
//                             printf("*");
//                         printf("\n");
//                     }
//                     totalLines += h;
//                     break;
//                 case 3:                        /* 菱形：上半 (h/2)+1 行 + 下半 h/2 行 */
//                     for (int i = 1; i <= (h / 2) + 1; i++) 
//                     {
//                         for (int m = i; m <= (h / 2) + 1; m++)
//                             printf(" ");
//                         for (int j = 1; j <= 2 * i - 1; j++)
//                             printf("*");
//                         printf("\n");
//                     }
//                     for (int l = (h / 2); l >= 1; l--) 
//                     {
//                         for (int n = l; n <= (h / 2) + 1; n++)
//                             printf(" ");
//                         for (int k = 2 * l - 1; k >= 1; k--)
//                             printf("*");
//                         printf("\n");
//                     }
//                     totalLines += (h / 2) + 1 + (h / 2);
//                     break;
//                 case 4:                        /* 数字金字塔：第 n 行 1..n 再 n-1..1 */
//                     for (int i = 1; i <= h; i++) 
//                     {
//                         for (int k = i; k <= h - 1; k++)
//                             printf(" ");
//                         for (int j = 1; j <= i; j++)
//                             printf("%d", j);
//                         for (int m = i - 1; m >= 1; m--)
//                             printf("%d", m);
//                         printf("\n");
//                     }
//                     totalLines += h;
//                     break;
//                 }
//                 patternCount++;
//                 need = 0;                      /* 回到菜单 */
//             }
//         }
//     }
//     printf("本次共打印 %d 个图案，合计 %d 行。再见~~\n", patternCount, totalLines);
 
//综合题3
// int quit = 0;
// int ch;
// int num = 0;
// int add = 0;
// int subtract = 0;
// int multiply = 0;
// int divide = 0;
// int modulo = 0;
// while(!quit)
// {
//     double first = 0;
//     char operator;
//     double second = 0;
//     int neg = 0;
//     int digits = 0;
//     int decimals = 0;//计算小数部分的位数
//     int o = 0;//记录first是不是浮点数
//     printf("请输入表达式（如 12.5 * 3,输入 q 退出)\n(支持 +、-、*、/、%% 五种运算):");
// //允许一开始有空格
//     do
//     {
//         ch = getchar();
//     } while (ch == ' ' || ch == '\t');
//     if(ch == EOF)
//     {
//         quit = 1;
//         continue;
//     }
//     else if(ch == 'q' || ch == 'Q')
//     {
//         quit = 1;
//         continue;
//     }
//     else//非q非EOF
//     {
//         /*带+-号的部分*/
//         if(ch == '+' || ch == '-')
//         {
//             neg = (ch == '-');
//             ch = getchar();
//         }
//         /*整数部分*/
//         while(ch >= '0' && ch <= '9')
//         {
//             first = first * 10 + (ch - '0');
//             digits++;//计算位数
//             ch = getchar();
//         }
//         /*小数部分*/
//         if(ch == '.')
//         {
//             ch = getchar();
//             while(ch >= '0' && ch <= '9')
//             {
//                 first = first * 10 + (ch - '0');
//                 digits++;
//                 decimals++;
//                 ch = getchar();
//             } 
//         }
//     }//条件1结束
// //计算first的值
// for(int i = 1;i <= decimals;i++)
// {
//     first /= 10;
// }
// //加+-号
// if(neg)
// {
//     first = -first;
// }
// //判断是否输入有效的数字
// if(digits == 0)
// {
//     printf("错误：第一个数格式不正确。\n");
//     while (ch != '\n' && ch != EOF) ch = getchar();
//     continue;  
// }
// else
// {
//     //第一个数字之后
//     //如果输入完第一个数字之后输入abc或者,.之类非空格字符 12.3+也不行，必须至少空一格
//     if(ch != ' ')
//     {
//         printf("错误：数字和运算符之间需要一个空格。\n");
//         while (ch != '\n' && ch != EOF) ch = getchar();
//         continue; 
//     }
//     do
//     {
//         ch = getchar();
//     } while (ch == ' ' || ch == '\t');//允许空格存在
// }
// //接下来读运算符
// //如果输入第一个数字+空格之后输入其他符号
// if(ch != '+' && ch != '-' && ch != '*' && ch != '/' && ch != '%')
// {
//     printf("错误：未知运算符，请输入 + - * / %%\n");
//     while (ch != '\n' && ch != EOF) ch = getchar();
//     continue; }
// else if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%')
// {
//     operator = (char)ch;
// }
// //也同样允许有空格
// do
// {
//     ch = getchar();
// } while (ch == ' ' || ch == '\t');
// //输入第二个数
// neg = 0;
// digits = 0;
// if(decimals != 0)
// {
//     o++;
// }
// decimals = 0;
// //从这一行到1588行与第一个数类似**************************************************************************************
//     if(ch == EOF)
//     {
//         quit = 1;
//         continue;
//     }
//     else if(ch == 'q' || ch == 'Q')
//     {
//         quit = 1;
//         continue;
//     }
//     else//非q非EOF
//     {
//         /*带+-号的部分*/
//         if(ch == '+' || ch == '-')
//         {
//             neg = (ch == '-');
//             ch = getchar();
//         }
//         /*整数部分*/
//         while(ch >= '0' && ch <= '9')
//         {
//             second = second * 10 + (ch - '0');
//             digits++;//计算位数
//             ch = getchar();
//         }
//         /*小数部分*/
//         if(ch == '.')
//         {
//             ch = getchar();
//             while(ch >= '0' && ch <= '9')
//             {
//                 second = second * 10 + (ch - '0');
//                 digits++;
//                 decimals++;
//                 ch = getchar();
//             } 
//         }
//     }//条件2结束
// //计算second的值
// for(int i = 1;i <= decimals;i++)
// {
//     second /= 10;
// }
// //加+-号
// if(neg)
// {
//     second = -second;
// }
// //判断是否输入有效的数字
// if(digits == 0)
// {
//         printf("错误：第二个数格式不正确。\n");
//         while (ch != '\n' && ch != EOF) ch = getchar();
//         continue;  
// }
// //从1532行到这一行与第一个数类似**************************************************************************************
// else
// {
//     //第二个数字之后
//     //如果输入完第二个数字之后输入除了enter之外的任何内容
//     while (ch == ' ' || ch == '\t')//允许输入空格
//     ch = getchar();
//     if (ch != '\n' && ch != EOF)      /* ← 还有别的东西 = 垃圾 */
//     {
//         printf("错误：表达式末尾有多余内容。\n");
//         while (ch != '\n' && ch != EOF) ch = getchar();
//         continue;    
//     }
// }
// if(operator == '/' && second == 0)
// {
//         printf("错误：除数不能为 0。\n");             /* ★ 专门的文案 */
//         continue;                                   /* 没有垃圾要清 */
// }
// else if(operator == '%' && (second == 0 || o == 1 || decimals != 0))
// {
//         printf("错误：%% 只支持两个整数，且除数不能为 0。\n");   /* ★ */
//         continue;
// }
//     switch(operator)
//     {
//         case '+':
//             printf("= %f\n",first + second);
//             add++;
//             break;
//         case '-':
//             printf("= %f\n",first - second);
//             subtract++;
//             break;
//         case '*':
//             printf("= %f\n",first * second);
//             multiply++;
//             break;
//         case '/':
//             printf("= %f\n",first / second);
//             divide++;
//             break;
//         case '%':
//             printf("= %d\n",(int)first % (int)second);
//             modulo++;
//             break;
// }
// num++;
// }
// printf("本次共成功计算 %d 次:\n+ : %d 次    - : %d 次    * : %d 次    / : %d 次    %% : %d 次\n再见~~",num,add,subtract,multiply,divide,modulo);

//综合题4
// /* ============================================================================
//    第 4 题　全能文本分析器
//    ----------------------------------------------------------------------------
//    这是【在你的原代码基础上修改】的版本：
//      · 你原来写的部分，用  #if 0 ... #endif  原样包起来保留
//      · 紧接着是  ✅ 修正后的写法
//      · 没改动的部分（分类 if-else 等）保持原样，不重复贴
//    为什么用 #if 0 而不是块注释来注释旧代码？
//      因为你旧代码里面本身就有块注释，而 C 语言【不允许块注释嵌套】。
//      外层块注释会被内层的结束符号提前截断，后面的代码就变成"活代码"，编译报错。
//      #if 0 ... #endif 是预处理指令，可以安全地包住任何内容 —— 包括注释。
//    ============================================================================ */
// /* ────────────────────────────────────────────────────────────────────────────
//    ① 分类计数器  —— 这一段你写对了，一字未改
//    ──────────────────────────────────────────────────────────────────────────── */
// int totalnum = 0;
// int digits = 0;
// int blank = 0;          /* 32 */
// int punctuation = 0;    /* 32~64  91~96  123~126 */
// int others = 0;
// int dalpha = 0;         /* 65~90 */
// int xalpha = 0;         /* 97~122 */
// int yalpha = 0;         /* 65 69 73 79 85 97 101 105 111 117 */
// #if 0
// /* ========== 你原来的写法开始（存"字符序列"，n 不可控会越界） ========== */
// char ch1[128];
// int ch1num[128];
// int i = 0;
// int num = 0;
// /* ========== 你原来的写法结束 ========== */
// #endif
// /* ✅ 改成：大小为 128 的计数数组，下标就是 ASCII 码
//       —— 题册提示的就是这个。= {0} 不能省，否则初值是随机数。          */
// int count[128] = {0};
// int ch;
// printf("请输入文本（以 # 结束）:");
// /* ────────────────────────────────────────────────────────────────────────────
//    ② 读取循环
//    ──────────────────────────────────────────────────────────────────────────── */
// #if 0
// /* ========== 你原来的 do-while 开始 ==========
//    问题：totalnum++ 写在判断之前，所以 # 和 EOF 也被算进总数；
//          ch1[i]=ch 把 \n、空格、# 全部存进数组，后面统计会混入。
// do
// {
//     ch = getchar();
//     totalnum++;
//     // 不用ctype.h
//     // （这里是你那段被注释掉的 ASCII 范围判断版本，共约 45 行，略）
//     // （这里是你后来启用的 ctype.h 版本：islower/isupper/isdigit/
//     //   ispunct/isspace，逻辑正确，下面新循环里原样保留）
//     ch1[i] = ch;
//     i++;
// } while(ch != '#' && ch != EOF);   // #35
//    ========== 你原来的 do-while 结束 ========== */
// #endif
// /* ✅ 改成：while 的"条件成立才进循环体"
//       所以 # 和 EOF 根本不会被执行到 → 后面所有的 "- 1" 补丁都能删掉   */
// while ((ch = getchar()) != EOF && ch != '#')
// {
//     totalnum++;                    /* ← 只有真字符才计数 */
//     /* ── 你的分类逻辑：一字未改（注意 isupper 里原来是双引号 "I"，已改回 'I'）── */
//     if (islower(ch))
//     {
//         xalpha++;
//         if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
//         {
//             yalpha++;
//         }
//     }
//     else if (isupper(ch))
//     {
//         dalpha++;
//         if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
//         {
//             yalpha++;
//         }
//     }
//     else if (isdigit(ch))
//     {
//         digits++;
//     }
//     else if (ispunct(ch))
//     {
//         punctuation++;
//     }
//     else if (isspace(ch))
//     {
//         blank++;
//     }
//     else
//     {
//         others++;
//     }
//     /* ── ★ 新增：只统计可打印字符（ASCII 33~126）──
//           \n(10)、空格(32) 自动被排除；下标锁在 33~126，不可能出界。 */
//     if (ch >= 33 && ch <= 126)
//     {
//         count[ch]++;
//     }
// }
// /* ────────────────────────────────────────────────────────────────────────────
//    ③ 频率统计：整段删除（约 20 行）
//       它的问题是：只有字符"第一次出现"的位置才等于真实次数，
//       第二、三次出现的位置会少算；而且 i 没有上限 → 越界写内存。
//    ──────────────────────────────────────────────────────────────────────────── */
// #if 0
// /* ========== 你原来的写法开始 ========== */
// for(int j = 0;j < i;j++)
// {
//     num = 0;
//     for(int k = j + 1;k < i;k++)
//     {
//         if(ch1[j] == ch1[k])
//         {
//             num++;
//         }
//     }
//     if(num != 0)
//     {
//         num += 1;
//     }
//     ch1num[j] = num;
// }
// /* ========== 你原来的写法结束 ========== */
// #endif
// /* ────────────────────────────────────────────────────────────────────────────
//    ④ 排序：整段删除（它只是想把最大频字符挪到下标 0，用计数数组后不需要了）
//    ──────────────────────────────────────────────────────────────────────────── */
// #if 0
// /* ========== 你原来的写法开始 ========== */
// int max = 0;
// char max1;
// for(int j = 0;j < i;j++)
// {
//     for(int k = j;k < i;k++)
//     {
//         if(ch1num[k] >= ch1num[j])
//         {
//             max = ch1num[j];
//             ch1num[j] = ch1num[k];
//             ch1num[k] = max;
//             max1 = ch1[j];
//             ch1[j] = ch1[k];
//             ch1[k] = max1;
//         }
//     }
// }
// // 检验数组是否成功选出最大频字符和出现次数
// // for(int j = 0;j <= i;j++)
// // {
// //     printf("%d ",ch1num[j]);
// // }
// /* ========== 你原来的写法结束 ========== */
// #endif
// /* ────────────────────────────────────────────────────────────────────────────
//    ⑥ 百分比：删掉所有 "- 1"，改成"分母为 0 时给 0.0"
//    ──────────────────────────────────────────────────────────────────────────── */
// #if 0
// /* ========== 你原来的写法开始 ==========
//    问题 1：只输入 # 时 totalnum-1 = 0 → 除以 0 → 打印出 -1.$% 这种乱码
//    问题 2：以 EOF 结束时没有 #，punctuation-1 会变成负数
// double alphacent = ((double)(dalpha + xalpha) / (totalnum - 1)) * 100;
// double digitscent = ((double)digits / (totalnum - 1)) * 100;
// double blankcent = ((double)blank / (totalnum - 1)) * 100;
// double punctuationcent = ((double)(punctuation - 1) / (totalnum - 1)) * 100;
// double otherscent = ((double)others / (totalnum - 1)) * 100;
// printf("总字符数: %d 个\n",totalnum - 1);
// printf("字母: %d 个(%.1f%%)\n",dalpha + xalpha,alphacent);
// printf("数字: %d 个(%.1f%%)\n",digits,digitscent);
// printf("空白: %d 个(%.1f%%)\n",blank,blankcent);
// printf("标点: %d 个(%.1f%%)\n",punctuation - 1,punctuationcent);
// printf("其他: %d 个(%.1f%%)\n",others,otherscent);
//    ========== 你原来的写法结束 ========== */
// #endif
// /* ✅ 改成 */
// double alphacent = 0.0, digitscent = 0.0, blankcent = 0.0;
// double punctuationcent = 0.0, otherscent = 0.0;
// if (totalnum > 0)
// {
//     alphacent       = (double)(dalpha + xalpha) / totalnum * 100;
//     digitscent      = (double)digits            / totalnum * 100;
//     blankcent       = (double)blank             / totalnum * 100;
//     punctuationcent = (double)punctuation       / totalnum * 100;
//     otherscent      = (double)others            / totalnum * 100;
// }
// printf("\n总字符数: %d 个\n", totalnum);
// printf("字母: %d 个(%.1f%%)\n", dalpha + xalpha, alphacent);
// printf("数字: %d 个(%.1f%%)\n", digits, digitscent);
// printf("空白: %d 个(%.1f%%)\n", blank, blankcent);
// printf("标点: %d 个(%.1f%%)\n", punctuation, punctuationcent);
// printf("其他: %d 个(%.1f%%)\n", others, otherscent);
// printf("\n");
// printf("大写字母: %d 个    小写字母: %d 个\n", dalpha, xalpha);
// printf("元音字母: %d 个\n", yalpha);
// /* ────────────────────────────────────────────────────────────────────────────
//    ⑤ 出现最多的可打印字符 —— 换成"正序扫描计数数组"
//    ──────────────────────────────────────────────────────────────────────────── */
// #if 0
// /* ========== 你原来的写法开始 ==========
//    问题：1) 输出了所有并列的字符，不是"ASCII 最小的那一个"
//          2) 没有说明规则（验收标准④明确要求）
//          3) m 可能越界读内存
// printf("出现最多的字符:");
// int m = 0;
// while(ch1num[m] == ch1num[0])
// {
//     printf("'%c'(%d次)",ch1[m],ch1num[m]);
//     printf("   ");                 // 隔开
//     if((m + 1) % 4 == 0)           // 每四个换行
//     {
//         printf("\n");
//         printf("              ");
//     }
//     m++;
// }
// printf("\n");
//    ========== 你原来的写法结束 ========== */
// #endif
// /* ✅ 改成：从 33 正序扫到 126，用 > 而不是 >=
//       为什么这样就实现了"并列取 ASCII 最小"？
//         先到的（ASCII 小的）已经占住 maxChar；
//         后面的因为用 >，"等于"不算 → 不会覆盖它。
//       一个额外判断都不用加。                                        */
// int maxCount = 0;
// int maxChar  = 0;
// for (int c = 33; c <= 126; c++)
// {
//     if (count[c] > maxCount)
//     {
//         maxCount = count[c];
//         maxChar  = c;
//     }
// }
// if (maxCount == 0)
// {
//     printf("出现最多的字符：没有可打印字符\n");
// }
// else
// {
//     printf("出现最多的字符：'%c'（%d 次）\n", maxChar, maxCount);
//     printf("（规则：只统计 ASCII 33~126 的可打印字符，空格与结束符 # 不计入；\n");
//     printf("　　　　若有多个字符并列最多，取 ASCII 码最小的那个）\n");
// }
// /* ────────────────────────────────────────────────────────────────────────────
//    ⑦ 柱状图：cent[] 排序 + 标签
//    ──────────────────────────────────────────────────────────────────────────── */
// #if 0
// /* ========== 你原来的 cent[] 排序开始 ==========
//    你已经把 cent[j] = cent[k] 改成 cent[j] = maxcent，交换是对的、排序也对了。
//    但它只是"把值排好"，名字没跟着走 —— 所以下面打印时只能靠
//    "值相等"反推名字。一旦两个分类百分比相同（如空白 11.8% 和标点 11.8%），
//    第 4 行就会被印成"空白"。
//    所以这里换成"值和下标一起排"的标准选择排序。
// double cent[5] = {alphacent,digitscent,blankcent,punctuationcent,otherscent};
// double maxcent = 0;
// for(int j = 0;j < 5;j++)
// {
//     maxcent = cent[j];
//     for(int k = j;k < 5;k++)
//     {
//         if(maxcent <= cent[k])
//         {
//             maxcent = cent[k];
//             cent[k] = cent[j];
//             cent[j] = maxcent;
//         }
//     }
// }
//    ========== 你原来的 cent[] 排序结束 ========== */
// #endif
// /* ✅ 改成：选择排序，cent 和 idx 一起换 */
// const char *label[5] = {"字母", "数字", "空白", "标点", "其他"};
// double cent[5] = {alphacent, digitscent, blankcent, punctuationcent, otherscent};
// int    idx[5]  = {0, 1, 2, 3, 4};      /* ★ 记住每一项原来是谁 */
// for (int j = 0; j < 5; j++)
// {
//     int m = j;                          /* 假设 j 是最大的 */
//     for (int k = j + 1; k < 5; k++)     /* ★ 从 j+1 开始，不和自己比 */
//     {
//         if (cent[k] > cent[m])
//         {
//             m = k;                      /* 找真正最大的下标 */
//         }
//     }
//     if (m != j)                         /* 一次交换到位 */
//     {
//         double t = cent[j];  
//         cent[j] = cent[m];  
//         cent[m] = t;
//         int u = idx[j];   
//         idx[j]  = idx[m];   
//         idx[m]  = u;   /* ★ 名字一起换 */
//     }
// }
// printf("\n占比柱状图（每 2%% 一格）：\n");
// #if 0
// /* ========== 你原来的柱状图开始（整段删除）==========
//    两处问题：
//      · 标签用 cent[j] == alphacent 这种"浮点相等"反推 → 并列时认错行
//      · 补空格用 (int)(cent[0]/2) - (int)(xxxcent/2) —— 你已经加了 (int)，
//        对齐是对的，保留这个思路，但换成"补到固定宽度"更稳
// for(int j = 0;j < 5;j++)
// {
//     if(cent[j] == alphacent)
//     {
//         printf("字母  |");
//         for(int k = 1;k <= (cent[j] / 2);k++) { printf("#"); }
//         for(int k = 1;k <= (int)((cent[0]) / 2) - (int)((alphacent) / 2);k++) { printf(" "); }
//         printf("  %.1f%%",cent[j]);
//         printf("\n");
//     }
//     else if(cent[j] == digitscent)
//     {
//         printf("数字  |");
//         for(int k = 1;k <= (cent[j] / 2);k++) { printf("#"); }
//         for(int k = 1;k <= (int)((cent[0]) / 2) - (int)((digitscent) / 2);k++) { printf(" "); }
//         printf("  %.1f%%",cent[j]);
//         printf("\n");
//     }
//     else if(cent[j] == blankcent)
//     {
//         printf("空白  |");
//         for(int k = 1;k <= (cent[j] / 2);k++) { printf("#"); }
//         for(int k = 1;k <= (int)((cent[0]) / 2) - (int)((blankcent) / 2);k++) { printf(" "); }
//         printf("  %.1f%%",cent[j]);
//         printf("\n");
//     }
//     else if(cent[j] == punctuationcent)
//     {
//         printf("标点  |");
//         for(int k = 1;k <= (cent[j] / 2);k++) { printf("#"); }
//         for(int k = 1;k <= (int)((cent[0]) / 2) - (int)((punctuationcent) / 2);k++) { printf(" "); }
//         printf("  %.1f%%",cent[j]);
//         printf("\n");
//     }
//     else
//     {
//         printf("其他  |");
//         for(int k = 1;k <= (cent[j] / 2);k++) { printf("#"); }
//         for(int k = 1;k <= (int)((cent[0]) / 2) - (int)((otherscent) / 2);k++) { printf(" "); }
//         printf("  %.1f%%",cent[j]);
//         printf("\n");
//     }
// }
//    ========== 你原来的柱状图结束 ========== */
// #endif
// /* ✅ 改成：先用 idx 取名字，条长算一次、再补到固定宽度 maxLen */
// int maxLen = (int)(cent[0] / 2);        /* 最长条的格数 */
// for (int j = 0; j < 5; j++)
// {
//     int barLen = (int)(cent[j] / 2);    /* 本行实际画几格 */
//     printf("%s  |", label[idx[j]]);     /* ★ 直接用名字，不做浮点比较 */
//     for (int k = 0; k < barLen;  k++) 
//     {
//         printf("#");
//     }
//     for (int k = barLen; k < maxLen; k++) 
//     {
//         printf(" ");   /* ★ 补到固定宽度 */
//     }
//         printf("  %.1f%%\n", cent[j]);
// }

// //综合题5
// int ch;
// int num = 0;//统计转换次数
// int button = 0;//让除了第一轮以外都打印提示
// int radixnum[15] = {2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};//记录各目标进制
// int radixchange[15] = {0};//记录各目标进制分别转换多少次
// printf("请输入十进制数和目标进制(1-16)(输入负数结束):\n");
// //while((ch = getchar()) != EOF)这样会先打字符再输出提示
// while(1)
// {
// int dicimal = 0;//十进制数
// int radix = 0;//目标进制
// int neg = 0;//判断十进制数是不是负数
// int digit10 = 0;//十进制数不能过大,最大不能超过9位,记录十进制数的位数
// int digit = 0;//判断数字转换数字的位数
// int modulus[30] = {0};//要逆序输出的余数,30位封顶
// if(button != 0)
// {
// printf("请输入十进制数和目标进制:\n");
// }//第一次转换不用输出，之后的转换再循环
// //提示输入完后再打字符
// ch = getchar();
// if(ch == EOF)
// {
//     break;//退出循环
// }
// while(ch == ' ' || ch == '\t')//允许一开始输入空格
// {
//     ch = getchar();
// }
// //判断输入的字符
// if(ch == '+' || ch == '-')//如果输入+-号
// {
//     if(ch == '-')//是-先给neg赋1，之后十进制数输入的是整数再判断
//     {
//         neg = 1;
//     }
// ch = getchar();
// }
// //再判断
// if(ch < '0' || ch > '9')//不是数字
// {
//     printf("错误,应输入十进制数!请重新输入\n");
//     while(ch != '\n' && ch != EOF) ch = getchar();
//     button++;
//     continue;//清除缓冲区里的多余字符
// }
// else//是数字
// {
//     while(ch >= '0' && ch <= '9')//将输入的十进制数赋值给dicimal
//     {
//         if(digit10 >= 9)//位数过大,重新循环防止崩溃,等十进制数和目标进制确定完再判断
//         {
//         printf("十进制数过大,请重新输入\n");
//         while(ch != EOF && ch != '\n') ch = getchar();
//         goto next;
//         }
//         dicimal = dicimal * 10 + (ch - '0');
//         digit10++;
//         ch = getchar();
//     }
// }
// /* ★★ 放在"检查空格"之前，任何负数都结束 ★★ */
// if(neg)
// {
//     printf("结束输入\n");
//     break;
// }
// //判断输入数字后面是什么,是空格还是其他的字符
// if(ch == ' ' || ch == '\t')//是空格
// {
//     while(ch == ' ' || ch == '\t')//允许两个数中间输入多个空格
//     {
//     ch = getchar();
//     }
// }
// else//非空格字符
// {
//     printf("错误,应输入十进制数!请重新输入\n");
//     while(ch != '\n' && ch != EOF) ch = getchar();
//     next:
//     button++;
//     continue;//清除缓冲区里的多余字符
// }
// //现在十进制数能确定下来了
// //接下来到目标进制
// if(ch < '0' || ch > '9')//目标进制非数字
// {
//     printf("错误,目标进制必须是2~16之间的整数,请重新输入\n");
//     while(ch != '\n' && ch != EOF) ch = getchar();
//     button++;
//     continue;
// }
// else//目标进制是数字
// {
//     while(ch >= '0' && ch <= '9')//将输入的值赋给目标进制
//     {
//         radix = radix * 10 + (ch - '0');
//         ch = getchar();
//     }
// }
// //输入数字之后,判断数字后面是什么
// //是字符,空格,还是换行符
// if(ch != ' ' && ch != '\t' && ch != '\n')//字符
// {   
//     printf("错误,目标进制必须是2~16之间的整数,请重新输入\n");
//     while(ch != '\n' && ch != EOF) ch = getchar();
//     button++;
//     continue;
// }
// else if(ch == ' ' || ch == '\t')//是空格,可大量输入,直到输入回车
// {
//     while(ch == ' ' || ch == '\t')
//     {
//         ch = getchar();
//     }
// }
// //再对目标进制进一步判断
// if(radix < 2 || radix > 16)//提示错误并重新输入
// {
//     printf("错误,目标进制必须是2~16之间的整数,请重新输入\n");
//     button++;
//     continue;
// }
// //现在十进制数和目标进制确定下来了
// /*printf("十进制数%d\n",dicimal);
// printf("目标进制%d\n",radix);*/
// //成功打印了
// //现在要输出转换进制了
// int dicimal1 = dicimal;//十进制数的替身
// //循环开始有int digit = 0;
// if(dicimal > 0)
// {
// while(dicimal1 > 0)
// {
//     modulus[digit] = dicimal1 % radix;//取余数
//     dicimal1 = dicimal1 / radix;//除
//     digit++;
// }
// //10-A 11-B 12-C 13-D 14-E 15-F
// //输出转换数字
// printf("%d 的 %d 进制是: ",dicimal,radix);
// for(int i = digit - 1;i >= 0;i--)
// {
//     switch(modulus[i])
//     {
//         case 15:
//             printf("%c",'F');
//             break;
//         case 14:
//             printf("%c",'E');
//             break;
//         case 13:
//             printf("%c",'D');
//             break;
//         case 12:
//             printf("%c",'C');
//             break;
//         case 11:
//             printf("%c",'B');
//             break;
//         case 10:
//             printf("%c",'A');
//             break;
//         default:
//             printf("%d",modulus[i]);
//             break;
//     }
// }
// printf(", 共 %d 位\n",digit);
// }
// else//十进制数为0
// {
//     printf("%d 的 %d 进制是 %d,共 %d 位\n",dicimal,radix,0,1);
// }
// //转换数字打印完成
// //记录各进制用了几次
// for(int i = 0;i < 15;i++)
// {
//     if(radixnum[i] == radix)
//     {
//         radixchange[i]++;
//     }
// }
// button++;//确保循环结束到下一轮仍可以打印提示
// num++;//每次循环记录一次转换次数
// }
// printf("共转换 %d 次:",num);
// for(int i = 0;i < 15;i++)
// {
//     if(radixchange[i] != 0)
//     {
//         printf(" %d 进制 %d 次,",radixnum[i],radixchange[i]);
//     }
// }
// printf("\n");
// printf("再见~~");
//综合题6
// int ch;
// int need = 0;//用来触发循环中的提示
// do//最外层循环 EOF结束
// {
//     int neg = 0;//判断是否是负数
//     int n = 0;//最终输入的整数n,每次循环清零
// printf("请输入一个正整数(2-100000):");
// ch = getchar();
// while(ch == ' ' || ch == '\t')//允许一开始输入多个空格
// {
//     ch = getchar();
// }
// //如果输入EOF,直接退出
// if(ch == EOF)
// {
//     break;
// }
// //先判断有无+-号
// if(ch == '+' || ch == '-')
// {
//     if(ch == '-')
//     {
//         neg = 1;
//     }
//     ch = getchar();
// }
// //再判断+-号之后是啥：数字，其他字符
// if(ch < '0' || ch > '9')//非数字
// {
//     printf("错误,应输入一个正整数\n");
//     //清理缓冲区，如输入a 缓冲区中为: a  \n 再次循环时会将\n赋给ch,导致错误提示输出两次
//     while(ch != EOF && ch != '\n') ch = getchar();
//     continue;
// }
// else
// {
//     while(ch >= '0' && ch <= '9')//输入数字时
//     {
//         n = n * 10 + (ch - '0');
//         ch = getchar();
//     }
// }
// //输入数字之后，后面是什么:空格，换行符，还是其他字符
// //允许输入数字之后再输入任意空格
// while(ch == ' ' || ch == '\t')
// {
//     ch = getchar();
// }
// //在判断是不是其他字符
// if((ch < '0' || ch > '9') && ch != '\n')//非换行符字符
// {
//     printf("错误,应输入一个正整数\n");
//     //清理缓冲区，如输入11a 缓冲区中为: a  \n 再次循环时会将\n赋给ch,导致错误提示输出两次
//     while(ch != EOF && ch != '\n') ch = getchar();
//     continue;
// }
// //整数n的值确定下来了
// //如果是负数
// if(neg)
// {
//     printf("错误,请输入一个2-100000之间的整数\n");
//     continue;
//     //不需要清理缓冲区
//     //输入-12 后无论之后输入空格还是换行符，都会从缓冲区里被拿走，不会对下轮循环造成影响
// }
// else if(n < 2)
// {
//     printf("错误,请输入一个2-100000之间的整数\n");
//     continue;
//     //同样不需要清理缓冲区    
// }
// else if(n > 100000)//过大
// {
//     printf("错误,请输入一个2-100000之间的整数\n");
//     continue;
//     //同样
// }
// //现在开始对n做判断
// int posdivisor[200] = {0};//存放正因数的数组
// //判断n是不是质数
// int i = 2;
// int note = 1;//给正因数数组里存放正因数，n是不是指数的判断标准
// int num = 0;//算1-n之间的质数数量
// int pridivisor[10000] = {0};//记录质因数
// int m = n;//n的影武者
// posdivisor[0] = 1;//第一个正因数一定是1
// while(i * i <= n)
// {
//     if(n % i == 0)//i是正因数
//     {
//         posdivisor[note] = i;//将正因数放数组中
//         note++;//注意最后note比数组实际长度大1
//     }
//     i++;
// }
// //判断是不是质数
// if(note == 1)//是质数
// {
//     printf("%d 是质数\n",n);
//     //再打印所有正因数,质数只有1和它本身
//     printf("所有正因数: %d %d\n",posdivisor[0],n);
//     //质因数分解
//     printf("质因数分解: %d = %d\n",n,n);
//     //算1-n之间的质数
//     for(int j = 2;j <= n;j++)
//     {
//         int i2 = 2;
//         int log = 0;//判断1-n之间的数是不是质数的标志
//         while(i2 * i2 <= j)
//         {
//             if(j % i2 == 0)
//             {
//                 log++;//log非零说明不是质数
//             }
//             i2++;
//         }
//         if(log == 0)//是质数
//         {
//             num++;
//         }
//     }
//     printf("%d 到 %d 之间共有 %d 个质数\n",1,n,num);
// }
// else//不是质数
// {
//     printf("%d 不是质数\n",n);
//     //再打印最小质因数
//     /*for(int j = 1;j < note - 1;j++)
//     {
//         int i1 = 2;//判断最小质因数用的
//         while(i1 * i1 <= posdivisor[j])
//         {
//             if(posdivisor[j] % i1 == 0)
//             {
//                 i1++;
//             }
//         }
//         if(i1 == 2)//找到最小质因数的标记
//         {
//             printf("最小质因数: %d\n",posdivisor[j]);
//             break;//找到后跳出这个for循环
//         }
//     } */ //不合格 如果(除了1和它本身)因数<= 2时,note = 2,会直接跳过循环,导致最小质因数不打印
//       //且如果note >= 3时除1的最小因数为5时,会在while里卡死
//     if (note >= 2)
//     {
//     printf("最小质因数: %d\n", posdivisor[1]);
//     }
//     //再打印所有正因数
//     printf("所有正因数:");
//     for(int j = 0;j <= note - 1;j++)//只能打印前一半正因数
//     {
//         printf(" %d",posdivisor[j]);
//     }
//     //防止平方数的特殊情况
//     //j = note -1时,平方数的平方根会打印两次
//     //j = note -2时,非平方数又会少打印一个数
//     int last = note - 1;//判断n是不是平方数
//     if(posdivisor[last] * posdivisor[last] == n)
//     {
//         last--;//是平方数时令j = note - 2;不是平方数时令j = note - 1
//     }
//     for(int j = last;j >= 0;j--)//打印后半部分正因数
//     {
//         printf(" %d",n / posdivisor[j]);
//     }
//     printf("\n");
//     //打印质因数分解
//     printf("质因数分解: %d =",n);
//     for(int j = 2;j <= n;j++)//先记录n的质因数
//     {
//         int log = 0;//判断1-n之间的数是不是质数的标志
//         int i2 = 2;
//         while(i2 * i2 <= j)
//         {
//             if(j % i2 == 0)
//             {
//                 log++;//log非零说明不是质数
//             }
//             i2++;
//         }
//         if(log == 0)//是质数
//         {
//             pridivisor[num] = j;
//             num++;
//         }
//     }
// //现在pridivisor里面就存放了1-n之间的质因数
//     for(int j = 0;j <= num - 1;j++)
//     {
//         int exponent = 0;//计算质因数分解时各项的指数
//         while(m % pridivisor[j] == 0)
//         {
//             m /= pridivisor[j];
//             exponent++;
//         }
//         if(exponent != 0)//可分解的质因数
//         {
//             printf(" %d",pridivisor[j]);
//             if(exponent == 1)
//             {
//                 printf(" *");
//             }
//             else
//             {
//                 printf("^%d *",exponent);
//             }
//         }
//     }
//     printf("\b ");
//     printf("\n%d 到 %d 之间共有 %d 个质数\n",1,n,num);
// }

// printf("\n");
// }while(ch != EOF);

//综合题7
// int ch;
// int pwnum = 0;//记录检查密码次数
// int wpwnum = 0;//弱密码次数
// int mpwnum = 0;//中密码次数
// int spwnum = 0;//强密码次数
// int pin = 0;//针,如果输入空格+换行的形式,负责触发提示
// printf("请输入密码（直接回车结束）:\n");
// while(ch != EOF )//最初的大循环
// {
// if(pin != 0 || pwnum != 0)//第二次循环之后输出
// {
//     printf("请输入密码:\n");
// }
// char password[100];//记录密码的数组
// char alpha[100];//记录密码中的字母
// int length = 0;//记录密码长度
// int dalpha = 0;//记录大写字母长度
// int xalpha = 0;//记录小写字母长度
// int digits = 0;//记录数字长度
// int punct = 0;//记录特殊符号长度
// int strength = 5;//记录密码强度
// int button = 0;//记录密码中间是否含有空格
// int i = 0;//作为存放密码的char数组的下标
// //开始输入密码
// ch = getchar();
// //直接回车结束
// if(ch == '\n')
// {
//     break;//跳出循环
// }
// //允许开头输出空格
// while(ch == ' ' || ch == '\t')
// {
//     ch = getchar();
// }
// //开头输入空格+换行,报错
// if(ch == '\n')
// {
//     printf("错误,请输入正确格式的密码！\n");
//     pin++;
//     continue;
//     //不需要清理缓冲区
// }
// //开始输入密码
// while(ch != EOF)//密码输入
// {
// if(ch == ' ' || ch == '\t')//输入字符后再输入空格
// {
//     button++;//表明在密码后输入了空格
//     //读空格之后下一个输入的是什么
//     //如果是空格,在这个while里循环,直到输入其他字符
//     //如果输入换行enter,跳出循环，说明密码输入完成
//     //输入字母数字标号之类的,报错
// }
// if(isupper(ch) && button == 0)//是大写字母
// {
//     dalpha++;
//     password[i] = ch;
//     alpha[i] = ch;
// }
// else if(islower(ch) && button == 0)//小写字母
// {
//     xalpha++;
//     password[i] = ch;
//     alpha[i] = ch;
// }
// else if(isdigit(ch) && button == 0)//数字
// {
//     digits++;
//     password[i] = ch;
// }
// else if(ispunct(ch) && ch != '\t' && ch != '\n' && button == 0)//除空格字母数字外的标号,也不包含换行
// {
//     punct++;
//     password[i] = ch;
// }
// ch = getchar();
// //如果在输入密码空格后再输入密码——即密码中间插入空格,直接跳出
// if(button != 0 && ch != ' ' && ch != '\t' && ch != '\n')
// {
//     //清空缓冲区的字符
//     while(ch != '\n' && ch != EOF) ch = getchar();
//     break;//跳出这个小循环
// }
// if(ch == '\n')//输出换行符
// {
//     //进入这个的条件:1: abc(正常输入密码) 2:abc   (输入密码后输入空格+换行)
//     //将button清零,防止影响判断
//     button = 0;
//     break;//跳出这个小循环
// }
// if(button == 0 && ch != ' ' && ch != '\t')//记录密码的长度,不记录空格(密码后输入第一个空格时button=0)
// {
// i++;//每循环一次i + 1
// }
// }//小循环结束
// if(button != 0)//说明是密码+空格+密码的错误形式
// {
//     printf("错误,密码之间不能带空格,请输入正确格式的密码!\n");
//     pin++;
//     continue;//重新循环    
// }
// //检查看密码是否存入数组中
// // printf("密码是:");
// // for(int j = 0;j <= i;j++)
// // {
// //     printf("%c",password[j]);
// // }
// // printf("\n");
// //密码输入完毕,接下来该判断了
// length = i + 1;//确定密码长度
// //判断密码情况
// if(length < 8)
// {
//     printf("长度不足 8 位; ");
//     strength--;
// }
// if(dalpha == 0)
// {
//     printf("缺少大写字母; ");
//     strength--;
// }
// if(xalpha == 0)
// {
//     printf("缺少小写字母; ");
//     strength--;
// }
// if(digits == 0)
// {
//     printf("缺少数字; ");
//     strength--;
// }
// if(punct == 0)
// {
//     printf("缺少特殊符号; ");
//     strength--;
// }
// if(strength == 5)
// {
//     printf("✓ 长度 ≥ 8   ✓ 大写字母   ✓ 小写字母   ✓ 数字   ✓ 特殊符号");
// }
// printf("\n");
// //判断强度
// switch(strength)
// {
//     case 1:
//     case 2:
//         printf("强度:弱 (满足 %d / %d 项)",strength,5);
//         wpwnum++;
//         break;
//     case 3:
//     case 4:
//         printf("强度:中 (满足 %d / %d 项)",strength,5);
//         mpwnum++;
//         break;
//     case 5:
//         printf("强度:强 (满足 %d / %d 项)",strength,5);
//         spwnum++;
//         break;
//     default:
//         printf("强度:弱 (满足 %d / %d 项)", strength, 5);
//         wpwnum++;
//         break;
// }
// printf("\n");
// //加密
// for(int j = 0;j <= i;j++)
// {
//     if(isalpha(password[j]))//是字母
//     {
//         if(password[j] == 'x' || password[j] == 'y' || password[j] == 'z' || password[j] == 'X' || password[j] == 'Y' || password[j] == 'Z')//是xyz的特殊情况
//         {
//             alpha[j] -= 23;
//         }
//         else
//         {
//         alpha[j] += 3;//将alpha数组中的对应字母转换
//         }
//     }
// }
// //打印加密后的密码
// printf("加密后: ");
// for(int j = 0;j <= i;j++)
// {
//     if(isalpha(password[j]))//当读到字母时
//     {
//         printf("%c",alpha[j]);//输出的是alpha数组的
//     }
//     else
//     {
//         printf("%c",password[j]);
//     }
// }
// printf("\n");
// pwnum++;//记录密码检查次数
// }//大循环结束
// printf("共检查 %d 个密码:强 %d 个，中 %d 个，弱 %d 个。再见~~",pwnum,spwnum,mpwnum,wpwnum);

//综合题9
// int round = 0;//总共玩了几局
// int yround = 0;//赢得局数
// printf("=== 猜数字游戏(1-100,最多猜 7 次)===\n");
// srand((unsigned)time(NULL));//设置随机数种子  是以秒数作为种子,循环太快会导致每次循环随机数不变
// while(1)//大循环,看循环的条件是什么(或者就用1)
// {
//     int times = 7;//每局猜数字的次数
//     int i = 1;//提示第几次猜测
//     int secret = rand() % (100 - 1 + 1) + 1;//获取随机数
//     int chosen = 0;//是否再来一局的选项y/n
//     char yn;//是否再来一局的选项y/n
//     int ch;
//     if(round > 0)//第一局之后打印
//     {
//         printf("=== 第 %d 局 ===\n",round + 1);
//     }
//     //每一局猜数字游戏单独一个小循环
// while(times >= 0)//次数耗尽或猜中结束循环
// {
//     int neg = 0;//输入负数时的信号
//     int num = 0;//每次猜的数字,重新猜时要清零
//     printf("第 %d 次猜测:",i);
//     //输入数字
//     ch = getchar();
//     //防止EOF卡死
//     if (ch == EOF)                   /* ★ 输入结束 → 退出程序 */
//     {
//     printf("\n输入结束,再见!\n");
//     round = round ? round : 1;   /* 避免胜率除零 */
//     break;
//     }
//     //允许开头输入空格
//     while(ch == ' ' || ch == '\t')
//     {
//         ch = getchar();
//     }
//     //输入+-号的情况
//     if(ch == '+' || ch == '-')
//     {
//         if(ch == '-')
//         {
//             neg++;
//         }
//         ch = getchar();
//     }
//     //接下来看输入的是数字还是其他符号
//     if(ch < '0' || ch > '9')//非数字情况
//     {
//         printf("错误:请输入 1 到 100 之间的整数(本次不计入次数)\n");
//         //清除缓冲区的所有字符
//         while(ch != '\n' && ch != EOF) ch = getchar();
//         continue;
//     }
//     else//数字情况
//     {
//         //将输入的数字赋值给num
//         while(ch >= '0' && ch <= '9')
//         {
//             num = num * 10 + (ch - '0');
//             ch = getchar();
//         }
//     }
//     //输入数字之后
//     //1是空格,可以
//     while(ch == ' ' || ch == '\t')
//     {
//         ch = getchar();
//     }
//     //2是其他非数字空格换行符字符,如12abc
//     if((ch < '0' || ch > '9') && ch != '\n')
//     {
//         printf("错误:请输入 1 到 100 之间的整数(本次不计入次数)\n");
//         //清除缓冲区的所有字符
//         while(ch != '\n' && ch != EOF) ch = getchar();
//         continue;
//     }
//     //3是换行符——数字确定下来了
//     //再对数字做出判断
//     //是负数
//     if(neg)
//     {
//         printf("错误:请输入 1 到 100 之间的整数(本次不计入次数)\n");
//         continue;
//     }
//     if(num < 1 || num > 100)//范围之外的数字
//     {
//         printf("错误:请输入 1 到 100 之间的整数(本次不计入次数)\n");
//         //不用清除缓冲区
//         continue;
//     }
//     else//在范围内
//     {
//         //与随机数比较,并给出答复
//         //times = 7猜的次数  i = 1第几次猜
//         //应该是小循环,好吧不是
//         if(num > secret && times > 1)//猜大了
//         {
//             times--;//剩余次数-1
//             printf("太大了!还有 %d 次机会。\n",times);
//             i++;//下次提醒还有+1次机会
//         }
//         else if(num < secret && times > 1)//猜小了
//         {
//             times--;
//             printf("太小了!还有 %d 次机会。\n",times);
//             i++;
//         }
//         else if(num != secret && times == 1)//第七次也没猜中,第七次猜测时times为1,第七次猜后变为零
//         {
//             printf("很遗憾,机会耗尽!答案是: %d。\n",secret);
//             round++;//局数+1,但胜利局数不变
//             break;
//         }
//         else if(num == secret && times > 1)//第七次之前猜中了,
//         {
//             times--;
//             printf("恭喜!你用了 %d 次猜中,答案就是 %d。\n",i,secret);
//             round++;//一局玩完,总玩次数+1
//             yround++;//胜利局数+1
//             break;//跳出猜数字循环
//         }
//         else if(num == secret && times == 1)//第七次猜中
//         {
//             printf("恭喜!你用了 %d 次猜中,答案就是 %d。\n",i,secret);
//             round++;//一局玩完,局数+1
//             yround++;
//             break;//跳出猜数字循环
//         }

//     }
// }//猜数字小循环结束
// printf("\n");
// //提问是否继续
// while(chosen == 0)
// {
// printf("再来一局?(y/n)");
// //scanf("%c",&yn);//好怀念,这几个题都没见你  好吧还是用不到你
// //输入y/n
// ch = getchar();
// //允许开头输入空格
// //解决EOF问题
// if (ch == EOF)                  /* ★ 加这一段 */
// {
//     printf("\n输入结束,再见!\n");
//     yn = 'n';                   /* 当成回答了 n */
//     chosen = 1;
//     break;
// }
// while(ch == ' ' || ch == '\t')
// {
//     ch = getchar();
// }
// //输入字符
// if(ch != 'y' && ch != 'n')//输入非y/n
// {
//     printf("错误!\n");
//     //清除缓冲区的多余字符
//     while(ch != '\n' && ch != EOF) ch = getchar();
// }
// else//输入y/n
// {
//     yn = ch;
//     ch = getchar();
//     //如果y/n之后输入空格,允许
//     while(ch == ' ' || ch == '\t')
//     {
//         ch = getchar();
//     }
//     //如果再输入其他非换行字符,重新输入
//     if(ch != '\n')
//     {
//         printf("错误!\n");
//         //清空缓冲区
//         while(ch != '\n' && ch != EOF) ch = getchar();
//     }
//     else//输入\n
//     {
//     chosen = 1;//跳出小循环
//     }
// }
// }//小循环结束
// if(yn == 'n')
// {
//     break;
//     //跳出大循环
// }
// printf("\n");
// }//大循环结束
// printf("\n");
// //打印结果
// double ycent =(double)yround / (double)round * 100;
// printf("本次共玩 %d 局,赢 %d 局，胜率 %.1f%%。再见~~",round,yround,ycent);

//综合题8
// int ch;
// int score[50] = {0};//记录成绩的数组
// double passrate = 0;//记录最终及格率
// double ave = 0;//记录最终平均分
// int num = 0;//记录输入的成绩数量
// double median = 0;//记录最终中位数
// double variance = 0;//记录方差
// int scoreband[5] = {0};//记录分数段
// int loop = 0;//记录是否输入错误的标志,每轮循环归零
// printf("请输入成绩(0-100,输入 -1 结束,最多 50 个):\n");
// //开始输入成绩
// while(ch != EOF)//输入记录成绩的大循环
// {
//     int neg = 0;//记录输入数字是否是负数的标志,每轮循环归零
//     int n = 0;//记录输入成绩,每次循环清零
//     //如果输入错误,再次输入时要提示,正常输入时不用提示
// if(loop != 0)
// {
//     printf("请输入成绩:\n");
// }
//     loop = 0;//记录是否输入错误的标志,每轮循环归零
//     ch = getchar();
// //如果第一次输入EOF
// if(ch == EOF)
// {
//     break;//跳出循环,防止运行循环后面的代码
// }
// //允许一开始输入多个空格,如果成绩之间输入很多空格也能跳过
// while(ch == ' ' || ch == '\t')
// {
//     ch = getchar();
// }
// //允许输入+-号
// if(ch == '+' || ch == '-')
// {
//     if(ch == '-')
//     {
//         neg = 1;
//     }
//     ch = getchar();
// }
// //如果输入非数字字符
// if(ch < '0' || ch > '9')
// {
//     printf("错误,请输入1-100之间的整数!\n");
//     printf("请从错误的地方开始输入成绩!\n");
//     printf("\n");
//     loop++;
//     //清除缓冲区
//     while(ch != '\n' && ch != EOF) ch = getchar();
//     continue;//重新循环
// }
// //输入数字
// else
// {
//     while(ch >= '0' && ch <= '9')//记录输入的数字
//     {
//         n = n * 10 + (ch - '0');
//         ch = getchar();
//     }
// }
// //输入数字之后
// //1：允许再次输入空格
// // //1)允许输入多个空格,最后还是决定启用这版,在改：应该是输入空格之后重新循环,不存在输入多个空格的
// // while(ch == ' ' || ch == '\t')
// // {
// //     ch = getchar();
// // }
// //2输入的是非空格数字换行符
// if((ch < '0' || ch > '9') && ch != '\n'&& ch != ' ' && ch != '\t')
// {
//     printf("错误,请正确输入!\n");
//     printf("请从错误的地方开始输入成绩!\n");
//     printf("\n");
//     loop++;
//     //清除缓冲区
//     while(ch != '\n' && ch != EOF) ch = getchar();
//     continue;//重新循环
// }
// //验证输入的数字
// if(neg)//输入的是负数
// {
//     if(n == 1)//该结束输入了
//     {
//         break;
//     }
//     else//输入非-1的负数
//     {
//         printf("错误,请输入1-100之间的正整数!\n");
//         printf("请从错误的地方开始输入成绩!\n");
//         printf("\n");
//         loop++;
//         continue;
//     }
// }
// if(n > 100)//数字过大
// {
//     printf("错误,请输入1-100之间的整数!\n");
//     printf("请从错误的地方开始输入成绩!\n");
//     printf("\n");
//     loop++;
//     continue;
// }
// //到这说明输入的是正确的数字
// //如果数组满了
// if(num >= 50)
// {
//     printf("[提示]已满50个\n");
//     break;
// }
// //将数赋给数组
// score[num] = n;
// num++;//下一轮时score数字记录下一个
// //2)只允许输入一个空格,应该用这版,应该放到验证数字的后面
// if(ch == ' ' || ch == '\t')
// {
//     continue;//数字后输入空格后重新循环
// }

// }//跳出大循环
// //验证成绩是否成功录入
// // printf("\n共录入 %d 个\n", num);
// // printf("数据: ");
// // for(int i = 0; i < num; i++) 
// // {
// //     printf("%d ", score[i]); 
// // }
// //开始输出结果
// printf("共 %d 个成绩\n",num);
// //如果什么也没输入
// if (num == 0)
// {
//     printf("[提示] 没有录入任何成绩，无法统计。\n");
//     return 0;                 /* 后面全跳过 */
// }
// //打印平均数
// for(int i = 0;i < num;i++)
// {
//     ave += score[i];
// }
// ave /= (double)num;
// printf("平均分: %.2f\n",ave);
// //找最高分和最低分,顺便降序排列
// int max = score[0];
// for(int i = 0;i < num;i++)
// {
//     for(int j = i + 1;j < num;j++)
//     {
//         if(score[i] < score[j])
//         {
//             max = score[j];
//             score[j] = score[i];
//             score[i] = max;
//         }
//     }
// }
// //打印最高分最低分
// printf("最高分: %d    最低分: %d\n",score[0],score[num - 1]);
// //统计及格率>= 60
// int pass = 0;//记录及格人数,顺带记录各分数段人数
// for(int i = 0;i < num;i++)
// {
//     int j = 0;//给各分数段做标记
//     if(score[i] >= 90 && score[i] <= 100)//分数段1
//     {
//         scoreband[j]++;
//         pass++;
//     }
//     else if(score[i] >= 80 && score[i] <= 89)//分数段2
//     {
//         j = 1;
//         scoreband[j]++;
//         pass++;
//     }
//     else if(score[i] >= 70 && score[i] <= 79)//分数段3
//     {
//         j = 2;
//         scoreband[j]++;
//         pass++;
//     }
//     else if(score[i] >= 60 && score[i] <= 69)//分数段3
//     {
//         j = 3;
//         scoreband[j]++;
//         pass++;
//     }
//     else//分数段4
//     {
//         j = 4;
//         scoreband[j]++;
//     }
// }
// passrate = (double)pass / (double)num * 100;
// printf("及格率: %.1f%%\n",passrate);
// //打印柱状图,题目没说要求,就默认是和之前一样每2%一个#...补充:50人最多,就是一个人一个#,好吧
// printf("分数段分布:\n");
// for(int k = 0;k <= 4;k++)
// {
// switch(k)
// {
//     case 0:
//         printf("%d-%d | ",90,100);
//         break;
//     case 1:
//         printf("%d-%d  | ",80,89);
//         break;
//     case 2:
//         printf("%d-%d  | ",70,79);
//         break;
//     case 3:
//         printf("%d-%d  | ",60,69);
//         break;
//     case 4:
//         printf("%d-%d   | ",0,59);
//         break;
// }
// for(int j = 0;j < scoreband[k];j++)
// {
//     printf("#");
// }
// for(int j = scoreband[k];j < num;j++)
// {
//     printf(" ");
// }
// printf("     %d 人\n",scoreband[k]);
// }
// printf("\n");
// //打印降序排列
// printf("降序排列: ");
// for(int i = 0;i < num;i++)
// {
//     printf("%d ",score[i]);
// }
// printf("\n");
// //打印中位数
// printf("中位数: ");
// if(num % 2 == 0)//有偶数个
// {
//     median = ((double)(score[num / 2 - 1] + score[num / 2]) /2.0);//注意数组是从0开始的
//     printf("%.2f\n",median);
// }
// else//有奇数个
// {
//     median = (double)score[num / 2];
//     printf("%.2f\n",median);
// }
// //打印方差variance
// for(int i = 0;i < num;i++)
// {
//     variance += ((double)score[i] - ave) * ((double)score[i] - ave);
// }
// variance /= num;
// printf("方差: %.2f",variance);

//综合题10!
#if 0
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
十道前8章综合题结束~~
     return 0;
}
#endif
//现在开始函数的学习
#if 0
//输入一个整数，顺序打印整数的每一位
void input(int n);//函数声明
int main()
{
    int n = 0;
    printf("请打印一个正整数:");
    scanf("%d",&n);
    input(n);
    return 0;
}
void input(int n)//函数定义
{
    if(n >= 10)
    {
        input(n / 10);
        printf("%d ",n % 10);
    }
    else//n < 10
    {
        printf("%d ",n);
    }
}
#endif
//三道递归题测试
//1正序逆序输入函数
#if 0
void print_num(int n);//正序函数
void print_num_rev(int n);//逆序函数
int main()
{
    int num = 0;
    scanf("%d",&num);
    printf("正序输出:\n");
    print_num(num);
    printf("\n");
    printf("逆序输出:\n");
    print_num_rev(num);
    return 0;
}
void print_num(int n)
{
    if(n >= 10)
    {
        print_num(n / 10);
        printf("%d ",n % 10);
    }
    else
    {
        printf("%d ",n);
    }
}
void print_num_rev(int n)
{
    if(n >= 10)
    {
        printf("%d ",n % 10);
        print_num_rev(n / 10);
    }
    else
    {
        printf("%d ",n);
    }
}
#endif
//2汉诺塔(返回步数)。。。看不懂
#if 0
long long hanoi(int n, char from, char to, char via);
int main()
{
    int num = 0;
    printf("请输入盘子数:");
    scanf("%d",&num);
    int n = hanoi(num,'A','B','C');
    printf("需要%d步",n);
    return 0;
}
long long hanoi(int n,char from,char to,char via)
{
    long long s = 0;

    if (n == 0) return 0;

    s += hanoi(n - 1, from, via, to);           /* 1. 上面 n-1 个 -> 中转柱 */
    printf("盘 %d: %c -> %c\n", n, from, to);   /* 2. 自己这一盘 */
    s += 1;
    s += hanoi(n - 1, via, to, from);           /* 3. 上面 n-1 个 -> 目标柱 */

    return s;
}
#endif
//十进制数转2~16进制
#if 0
void to_base(int n, int base);    /* base 取 2~16 */
int main()
{
    printf("请输入整数和要转换成的进制:");
    int n = 0;
    int base = 0;
    scanf("%d %d",&n,&base);
    printf("转换后的数为：\n");
    to_base(n,base);
    return 0;
}
void to_base(int n, int base)
{
    if(n >= base)
    {
        to_base((n / base),base);
        if(n % base < 10)
        {
            printf("%d",n % base);
        }
        else
        {
            printf("%c",'A' + ((n % base) - 10));
        }
    }
    else//n < base
    {
        if(n < 10)
        {
            printf("%d",n);
        }
        else//n >= 10
        {
            printf("%c",'A' + (n - 10));
        }
    }

}
#endif
//求第n个斐波那契数列
#if 0
long long fbnq(int n);
int main()
{
    int num = 0;
    scanf("%d",&num);
    printf("第%d个斐波那契数列为:%lld",num,fbnq(num));
    return 0;
}
long long fbnq(int n)
{
    if(n <= 2)
    {
        return 1;
    }
    else
    {
        long long num = fbnq(n - 1) + fbnq(n - 2);
        return num;
    }
}
#endif
//斐波那契循环方式
#if 0 
int main()
{
    long long fei[1024] = {0};
    int num = 0;
    scanf("%d",&num);
    if(num <= 2)
    {
        printf("第%d个斐波那契数为:%lld",num,1);
    }
    else
    {
        for(int i = 0;i <= num - 1;i++)
        {
            if(i <= 1)
            {
                fei[i] = 1;
            }
            else
            {
                fei[i] = fei[i - 1] + fei[i - 2];
            }
        }
        printf("第%d个斐波那契数为:%lld",num,fei[num - 1]);
    }
    return 0;
}
#endif
// int main()
// {
// int n = -1 << 1;
// printf("%d",n);
//     return 0;
// }
//9.11 1
#if 0
double minnum(double x,double y);
int main()
{
    double x,y;
    printf("请输入两个数:");
    scanf("%lf %lf",&x,&y);
    printf("%f",minnum(x,y));
    return 0;
}
double minnum(double x,double y)
{
    if(x > y)
    {
        return y;
    }
    else
    {
        return x;
    }
}
#endif
//9.11 10
#if 0
int to_binary(int num,int n);
int main()
{
    printf("请输入十进制数和转换进制:");
    int num,n;
    scanf("%d %d",&num,&n);
    printf("转换后的数为:");
    to_binary(num,n);
    return 0;
}
int to_binary(int num,int n)
{
    if(num >= n)
    {
        to_binary(num / n,n);
        printf("%d",num % n);
    }
    else//num < n
    {
        printf("%d",num);
    }
}
#endif
//9.11 7
#if 0
void alpha_pos(char arr[1024],int num);
int main()
{
    int ch;
    char arr[1024];
    int i = 0;
    while((ch = getchar()) != EOF)
    {
        arr[i] = ch;
        i++;
        //跳过换行
    }
    alpha_pos(arr,i);
    return 0;
}
void alpha_pos(char arr[1024],int num)
{
    for(int i = 0;i < num;i++)
    {
    if(arr[i] < 'A' || (arr[i] > 'Z' && arr[i] < 'a') || arr[i] > 'z')
    {
        printf("不是所有字符都是字母\n");
        printf("%d\n",-1);
    }
    else if(arr[i] >= 'A' && arr[i] <= 'Z')
    {
        printf("%c在字母表中的位置为:%d\n",arr[i],(arr[i] - 'A' + 1));
    }
    else if(arr[i] >= 'a' && arr[i] <= 'z')
    {
        printf("%c在字母表中的位置为:%d\n",arr[i],(arr[i] - 'a' + 1));
    }
    }
}
#endif
//综合题10函数版
#if 0
void show_menu(void);//函数1：打印菜单
int read_choice(void);//函数2：返回选项
void do_input(void);//函数3：；录入数据
void do_stats(void);//函数4：统计显示
void do_sort(void);//函数5：升序显示
int do_find(void);//函数6：查找数据
void do_dedup(void);//函数7：去重显示
void do_histogram(void);//函数8：显示直方图
void do_reverse(void);//函数9：反转显示
void do_show_all(void);//函数10：显示全部
void result_output(void);//函数11：打印最后统计结果
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
int main()
{
show_menu();
int button;
while((button = read_choice()) != 0)
{
if((button >= 2 && button <= 8) && num == 0)//没录入数据就选择2-8
{
    printf("[提示] 还没有数据，请先使用选项 1 录入数据。\n");
    printf("\n");
    continue;//重新循环
}
switch(button)
{
    case 1:
    {
        do_input();
        break;
    }
    case 2:
    {
        do_stats();
        break;
    }
    case 3:
    {
        do_sort();
        break;
    }
    case 4:
    {
        int cancel =  do_find();
        if(cancel == 1)
        {
            break;
        }
        search++;
        break;
    }
    case 5:
    {
        do_dedup();
        break;
    }
    case 6:
    {
        do_histogram();
        break;
    }
    case 7:
    {
        do_reverse();
        break;
    }
    case 8:
    {
        do_show_all();
        break;
    }
    case 9:
    {
        break;
    }
}
if(button == 9)
{
    break;
}
}
result_output();
    return 0;
}//main函数结束
void show_menu(void)//函数1
{
printf("================= 数字分析工具箱 =================\n");
printf("\n");
printf("1) 录入数据      2) 显示统计      3) 升序排序\n");
printf("4) 查找数值      5) 去重显示      6) 显示直方图\n");
printf("7) 反转显示      8) 显示全部数据  9) 退出\n");
printf("\n");
printf("==================================================\n");
}//函数1结束
int read_choice(void)//函数2
{
while(1)
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
    return 0;//直接跳出循环
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
//能到这说明button = 1-9
return button;
}
}//函数2结束
void do_input(void)//函数3
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
}//函数3结束
void do_stats(void)//函数4
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
}//函数4结束
void do_sort(void)//函数5
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
}//函数5结束
int do_find(void)//函数6
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
    return cancel;
}//函数6结束
void do_dedup(void)//函数7
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
}//函数7结束
void do_histogram(void)//函数8
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
}//函数8结束
void do_reverse(void)//函数9
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
}//函数9结束
void do_show_all(void)//函数10
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
}//函数10结束
void result_output(void)//函数11
{
printf("本次会话使用情况:\n");
printf("录入 %d 次,统计 %d 次,排序 %d 次,查找 %d 次,\n",input,count,order,search);
printf("去重 %d 次,直方图 %d 次,反转 %d 次,显示 %d 次。\n",dudup,histogram,reverse,output);
printf("再见~~\n");
}//函数11结束
#endif
//!!初版扫雷游戏!!
#if 0
int button = 0;//判断是否开始游戏的条件
char outer[11][11];//表层棋盘
char inner[11][11];//里层棋盘
void menu_print(void);//函数1：菜单输出
int choice_print(void);//函数2：输入选项
void game(void);//游戏函数
void mine_set(void);//布雷函数(顺便设置表棋盘)
void inner_set(void);//里盘布置
void chess_print(void);//表棋盘输出
void select_cell(void);//选择格子
int main()
{
    srand((unsigned)time(NULL));
    while(1)
    {
        mine_set();//每局开始雷随机
        inner_set();//里棋盘布置
        button = 0;
        menu_print();//菜单输出
        button = choice_print();
        if(button == 0)
        {
            break;
        }
        else//选择1
        {
            game();
        }
    }
    return 0;
}
void menu_print(void)//函数1
{
    printf("============ 初 等 扫 雷 ============\n");
    printf("   9 x 9 棋盘,10 颗雷\n");
    printf("   1) 开始游戏\n");
    printf("   0) 退出\n");
    printf("=====================================\n");
}//函数1结束
int choice_print(void)//函数2
{
while(1)
{
    int button = 0;//选项
    printf("请选择>>");
    scanf("%d",&button);
    if(button == 1)
    {
        return button;
    }
    else if(button == 0)
    {
        printf("退出游戏\n");
        return 0;
    }
    else
    {
        printf("错误,请输入正确的选项\n");
        continue;
    }
}
}//函数2结束
void mine_set(void)//布雷函数
{
    int placed = 0;
    //先给里棋盘所有的格子都赋值0
    for(int i = 0;i < 11;i++)
    {
        for(int j = 0;j < 11;j++)
        {
            inner[i][j] = '0';//防止雷格的干扰
        }
    }
    //将雷输入里棋盘中
    /* ② 放 10 颗，不重复 */
    while (placed < 10)
    {
        int r = rand() % 9 + 1;      /* 1..9 ✓ */
        int c = rand() % 9 + 1;
        if (inner[r][c] == '1') continue;   /* ★ 已经有雷就重抽 */
        inner[r][c] = '1';
        placed++;
    }
    //开始设置表棋盘
    for(int i = 1;i <= 9;i++)
    {
        for(int j = 1;j <= 9;j++)
        {
            outer[i][j] = '#';
        }
    }
}//布雷函数结束
void inner_set(void)//里棋盘的非雷格要显示周围8格的雷数
{
    //设置影武者数组
    char copy[11][11];
    for(int i = 0;i < 11;i++)
    {
        for(int j = 0;j < 11;j++)
        {
            copy[i][j] = inner[i][j];
        }
    }
    for(int i = 1;i <= 9;i++)
    {
        int k = 0;
        for(int j = 1;j <= 9;j++)
        {
            if(inner[i][j] == '1')
            {
                inner[i][j] = '*';
                continue;
            }
            k = (int)((copy[i - 1][j - 1] - '0')+ (copy[i][j - 1] - '0') + (copy[i + 1][j - 1] - '0') + (copy[i + 1][j] - '0') + (copy[i + 1][j + 1] - '0')+ (copy[i][j + 1] - '0') + (copy[i - 1][j + 1] - '0') + (copy[i - 1][j] - '0'));
            inner[i][j] = (char)('0' + k);
        }
    }//里棋盘布置完成
}
void chess_print(void)
{
    printf("  1 2 3 4 5 6 7 8 9\n");
    printf("  _ _ _ _ _ _ _ _ _\n");
    for(int i = 1;i <= 9;i++)//输出表棋盘
    {
        printf("%d|",i);
        for(int j = 1;j <= 9;j++)
        {
            printf("%c ",outer[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    // //输出里棋盘(验证)
    // printf("  1 2 3 4 5 6 7 8 9\n");
    // printf("  _ _ _ _ _ _ _ _ _\n");
    // for(int i = 1;i <= 9;i++)//输出里棋盘(验证)
    // {
    //     printf("%d|",i);
    //     for(int j = 1;j <= 9;j++)
    //     {
    //         printf("%c ",inner[i][j]);
    //     }
    //     printf("\n");
    // }//验证完毕
}
void select_cell(void)//检查格子函数
{
while(1)
{
    int row,col;
    printf("请选择您要检查的格子( 行 列):");
    //用里棋盘对应的格子替换表棋盘
    if (scanf("%d %d", &row, &col) != 2)
    {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    printf("输入有误\n");
    continue;
    }
    if (row < 1 || row > 9 || col < 1 || col > 9)
    {
    printf("坐标非法！请输入 1~9\n");
    continue;
    }
    outer[row][col] = inner[row][col];
    int opened = 0;
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            if (outer[i][j] != '#') 
            {
                opened++;
            }
        }
    }

if (opened >= 71) { printf("恭喜您找出了所有的雷！\n"); break; }
    if(outer[row][col] == '*')
    {
        printf("*******************boom!!!~~~~~*****************\n");
        printf("******************你被炸死了!!*******************\n");
        chess_print();
        break;//跳出循环
    }
    chess_print();//输出棋盘
    if(opened >= 71)
    {
        printf("恭喜您找出了所有的雷！\n");
        break;
    }
}
}//查格子函数结束
void game(void)//游戏函数
{
    chess_print();//输出棋盘
    select_cell();
}//游戏函数结束
#endif
//函数题1（过度题）
//随机点名器
#if 0
int button = 0;//录入选项
int sum = 0;//录入的总人数
int num = 0;//每次录入的人数
int ch;//清空缓冲区，排除非法输入情况
int ID[50] = {0};//录入学号
int picked_ID[50] = {0};//记录抽中的学号
void print_menu(void);//输出菜单函数
int read_chosen(void);//录入选项
int read_people(int num);//录入人数
void read_list(int num);//录入名单
void show_list(int sum);//显示名单
void choice_N(int n);//抽N人（抽一人可看作特殊情况）
int total = 0;//记录抽中的人数
void clear_choice(void);//重置抽中人数
int picked_note = 0;//重置的标志
void print_num(void);//统计各项数据
int main()
{
    srand((unsigned)time(NULL));//设置随机数种子
    print_menu();//输出菜单
    do//开始循环
    {
        num = 0;
        button = read_chosen();//录入选项
        switch(button)
        {
            case 1://录入名单
            {
                num = read_people(num);//录入人数
                sum += num;//记录录入的总人数
                //录入num个学号
                read_list(num);
                break;
            }
            case 2://显示名单
            {
                show_lisr(sum);
                break;
            }
            case 3://抽一人
            {
                choice_N(1);
                break;
            }
            case 4://抽N人
            {
                int N;
                //录入输入的数字
                while(1)
                {
                    int ret;
                    printf("请输入人数 > ");
                    ret = scanf("%d",&N);
                    if(ret == EOF)//输入EOF的情况
                    {
                        printf("错误\n");
                        return -1;
                    }
                    //输入非数字的情况
                    if(ret == 0)
                    {
                        printf("错误,一个合适的正整数!\n");
                        //清空缓冲区
                        while((ch = getchar()) != '\n'&& ch != EOF);
                        continue;
                    }
                    //输入数字但不是选项提供的
                    if(N > sum || N < 1)
                    {
                        printf("错误,请输入范围内的数字!\n");
                        continue;
                    }
                    //能到这说明是个合格的选项
                    break;
                }
                choice_N(N);
                break;
            }
            case 5://重置
            {
                clear_choice();
                break;
            }
            case 6:
            {
                print_num();
                break;
            }
            case 0:
            {
                //直接就能退出
                break;
            }
        }
        if(num == -1)//录入人数时输入EOF
        {
            break;
        }
    }while(button != 0);
    return 0;
}
void print_menu(void)//输出菜单函数
{
    printf("========== 随 机 点 名 器 ==========\n");
    printf("  1) 录入名单\n");
    printf("  2) 显示名单\n");
    printf("  3) 抽 1 人\n");
    printf("  4) 抽 N 人（不重复）\n");
    printf("  5) 重置（清空已抽记录）\n");
    printf("  6) 统计\n");
    printf("  0) 退出\n");
    printf("====================================\n");
}//输出菜单函数结束
int read_chosen(void)//录入选项函数
{
while(1)//循环
{
    int button = 0;
    int ret;
    printf("请选择 >> ");
    ret = scanf("%d",&button);
    if(ret == EOF)//输入EOF的情况
    {
        printf("错误\n");
        return 0;
    }
    //输入非数字的情况
    if(ret == 0)
    {
        printf("错误,请输入选项提供的数字!\n");
        //清空缓冲区
        while((ch = getchar()) != '\n'&& ch != EOF);
        continue;
    }
    //输入数字但不是选项提供的
    if(button > 6 || button < 0)
    {
        printf("错误,请输入选项提供的数字!\n");
        continue;
    }
    //能到这说明是个合格的选项
    return button;
}
}//录入选项函数结束
int read_people(int num)//录入人数函数
{
while(1)
{
    int ret;
    printf("请输入人数 > ");
    ret = scanf("%d",&num);
    if(ret == EOF)//输入EOF的情况
    {
        printf("错误\n");
        return -1;
    }
    //输入非数字的情况
    if(ret == 0)
    {
        printf("错误,请输入选项提供的数字!\n");
        //清空缓冲区
        while((ch = getchar()) != '\n'&& ch != EOF);
        continue;
    }
    //输入数字但不是选项提供的
    if(num > 50 || num < 1)
    {
        printf("错误,请输入选项提供的数字!\n");
        continue;
    }
    //能到这说明是个合格的选项
    return num;
}
}//录入人数函数结束
void read_list(int num)//录入名单函数
{
    printf("请依次输入 %d 个学号\n",num);
    for(int i = sum - num;i < sum;i++)
    {
        int stunum = 0;//记录每个学生的学号
        printf("第 %d 个 > ",i + 1);
        while(1)
        {
            int ret;
            ret = scanf("%d",&stunum);
            if(ret == EOF)//输入EOF的情况
            {
            printf("错误\n");
            return 0;
            }
            //输入非数字的情况
            if(ret == 0)
            {
            printf("错误,请输入选项提供的数字!\n");
            //清空缓冲区
            while((ch = getchar()) != '\n'&& ch != EOF);
            continue;
            }
            //输入数字
            if(stunum < 1)
            {
            printf("错误,请输入选项提供的数字!\n");
            continue;
            }
            //能到这说明是个合格的学号
            break;
        }
        ID[i] = stunum;//将学号录入
        printf("\n");
    }    
    printf("已录入 %d 人\n",num);
}//录入名单函数结束
void show_lisr(int sum)//显示名单函数
{
    printf("  序号        学号          状态\n");
    printf("  ----     ---------     ----------\n");
    for(int i = 0;i < sum;i++)
    {
        if(i + 1 < 10)
        {
        printf("  %d         %d              ",i + 1,ID[i]);
        if(ID[i] == picked_ID[i])//检查是否被选中
        {
            printf("已选中");
        }
        else
        {
            printf("未选中");
        }
        printf("\n");
        }
        else
        {
        printf("  %d        %d              ",i + 1,ID[i]);
        if(ID[i] == picked_ID[i])//检查是否被选中
        {
            printf("已选中");
        }
        else
        {
            printf("未选中");
        }
        printf("\n");
        }
    }
}//显示名单函数
void choice_N(int n)//抽N人函数
{
#if 0//原函数
    if(sum == 0)
    {
        printf("[提示] 名单是空的，请先选 1\n");
        return; 
    }
    total += n;
    int i = 0;
    if(picked_note != 0)//说明重置了
    {
        total = 0;
    }
    printf("***** 抽签结果 *****\n");
    while(i < n)
    {
        int j = rand() % ((sum - 1) - 0 + 1) + 0;
        if(picked_ID[j] == ID[j])//已经被抽中了
        {
            continue;
        }
        picked_ID[j] = ID[j];
        printf("第 %d 个: %d 号\n",i + 1,ID[j]);
        i++;
        if((i >= total - sum) && (total - sum) > 0)//全部抽过了
        {
            printf("[提示] 所有人都抽过了，请先选 5 重置\n");
            break;
        }
    }
#endif
    int left = 0;
    int i, j;

    /* ① 名单为空 */
    if (sum == 0)
    {
        printf("[提示] 名单是空的，请先选 1\n");
        return;
    }
    /* ② 先数还剩几个没抽 */
    for (i = 0; i < sum; i++)
    {
        if (!picked_ID[i]) 
        {
            left++;
        }
    }
        /* ③ 全抽过了 */
    if (left == 0)
    {
        printf("[提示] 所有人都抽过了，请先选 5 重置\n");
        return;
    }

    /* ④ 要抽的比剩下的多 → 改成抽剩下的 */
    if (n > left)
    {
        printf("[提示] 只剩 %d 人，改为抽 %d 人\n", left, left);
        n = left;
    }

    /* ⑤ 抽 n 个 */
    printf("***** 抽签结果 *****\n");
    for (i = 0; i < n; i++)
    {
        do {
            j = rand() % sum;
        } while (picked_ID[j]);          /* ★ 抽到"没抽过的"为止 */

        picked_ID[j] = ID[j];
        printf("第 %d 个: %d 号\n", i + 1, ID[j]);
    }

}//抽N人函数结束
void clear_choice(void)//重置函数
{
    for(int i = 0;i < sum;i++)
    {
        picked_ID[i] = 0;
    }
    picked_note++;
    printf("重置完成\n");
}//重置函数结束
void print_num(void)//统计函数
{
    int picked_num = 0;
    double picked_rate = 0.0;
    for(int i = 0;i < sum;i++)
    {
        if(picked_ID[i] != 0)
        {
            picked_num++;
            printf("%d ",picked_num);
        }
    }
    printf("总人数: %d\n",sum);
    printf("抽中人数: %d\n",picked_num);
    printf("未抽中人数: %d\n",sum - picked_num);
    picked_rate = (double)picked_num /(double)sum * 100;
    printf("完成度: %.2f%%\n",picked_rate);
}//统计函数结束
#endif

//~~噩梦开始~~
//~~或许最终结局是放弃~~
//~~也许你坚持了下来~~
//~~但不论结局如何~~
//~~等待你的只有绝望~~
//~~无非是程度的大小~~

//函数题2 五子棋
#if 0
#define ROW 19//行
#define COL 19//列
int button = 0;//录入选项,选项为0退出大循环
int ch;
char chess[ROW][COL];//棋盘
int move = 0;//作为黑白的标志,note为偶数黑下,同时记录下棋步数
int black_move= 0;//记录黑棋步数
void print_menu(void);//菜单输出函数
int read_chosen(void);//录入选项函数
void Gobang(void);//五子棋游戏函数
void print_chess(void);//录入棋盘函数
void show_chess(void);//输出棋盘
int read_move(int move,int row,int col);//读入落子
int g_row = 0;
int g_col = 0;//作为全局变量,在悔棋时重置棋盘,同时存储了最后下的位置
int read_undo(int g_row,int g_col);//悔棋
int is_win(int move);//判断是黑赢还是白赢

int main()
{
    do
    {
        print_chess();//每局开始前先录好空棋盘
        print_menu();//输出菜单
        button = read_chosen();//录入选项
        //录入0直接退出小函数,还是需要分情况讨论
        if(button == 1)
        {
            Gobang();//开始五子棋游戏
        }
    } while (button != 0);//大循环
    
    return 0;
}

void print_menu(void)//菜单输出函数
{
    printf("================ 五 子 棋 ================\n");
    printf("  1) 开始新局\n");
    printf("  0) 退出\n");
    printf("==========================================\n");
}//菜单输出函数结束
int read_chosen(void)//录入选项函数
{
    while(1)
    {
        int chosen;
        int ret;
        printf("请选择 >> ");
        ret = scanf("%d",&chosen);
        //如果输入EOF
        if(ret == EOF)
        {
            return -1;//直接结束
        }
        //如果输入非数字
        if(ret == 0)
        {
            printf("错误,请输入选项提供的数字\n");
            //清空缓冲区
            while((ch = getchar()) != '\n' && ch != EOF) ;
            continue;
        }
        //如果输入数字
        if(chosen >= 2 || chosen < 0)//非选项提供的数字
        {
            printf("错误,请输入选项提供的数字\n");
            //清空缓冲区
            while((ch = getchar()) != '\n' && ch != EOF) ;
            continue;
        }
        //如果输入的是1.1之类的非法输入
        if(((ch = getchar()) < '0' || ch > '9') && ch != '\n')
        {
            printf("错误,请输入选项提供的数字\n");
            //再清空缓冲区,防止输入1.1之类的非法输入使.1留在缓冲区干扰下轮循环
            while(ch != '\n' && ch != EOF) ch = getchar();
            continue;
        }
        // //检验录入的选项
        // printf("%d\n",chosen);
        //合格
        //至此,是个合格的选项了
        return chosen;
    }
}//录入选项函数结束
void print_chess(void)//录入棋盘函数
{
    for(int i = 0;i < ROW;i++)
    {
        for(int j = 0;j < COL;j++)
        {
            chess[i][j] = '.';
        }
    }
}//录入棋盘函数结束
void show_chess(void)//输出棋盘函数
{
    printf("      1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19\n ");
    printf("  -----------------------------------------------------------\n");
    for(int i = 0;i < ROW;i++)
    {
        if(i + 1 < 10)
        {
            printf("%d  |",i + 1);
        }
        else
        {
            printf("%d |",i + 1);
        }
        for(int j = 0;j < COL;j++)
        {
            printf("  %c",chess[i][j]);
        }
        printf("\n");
    }
    printf("\n  . 空   * 黑   O 白   \n\n");
}//输出棋盘函数结束
int read_move(int move,int row,int col)//读入落子函数
{
    while(1)//小循环,输入正确的位置才能退出
    {
        int ret;
        ret = scanf("%d %d",&row,&col);//读入落子位置
        //判断输入的落子位置是否合法
        if(ret == EOF)//老朋友EOF
        {
            return -1;//直接退出
        }
        if(ret == 0)//输入非数字字符
        {
            printf("错误,请输入正确的位置\n");
            //清空缓冲区
            while((ch = getchar()) != '\n' && ch != EOF)  ;
            continue;
        }
        //输入的行列不在范围
        if(row > 19 || row < 1 || col > 19 || col < 1)
        {
            printf("错误,请输入棋盘范围内的行列\n");
            //清空缓冲区
            while((ch = getchar()) != '\n' && ch != EOF)  ;
            continue;
        }
        //到这就合格了。。。应该
        //如果落子的地方已经有子了
        if(chess[row - 1][col - 1] == '*' || chess[row - 1][col - 1] == 'O')//有子
        {
            printf("错误,请在无子的地方落子\n");
            //清空缓冲区
            while((ch = getchar()) != '\n' && ch != EOF)  ;
            continue;
        }
        g_row = row;
        g_col = col;
        //开始将选择的地方录入棋盘
        if(move % 2 == 0)//是黑子
        {
            chess[row - 1][col - 1] = '*';
        }
        else//白字
        {
            chess[row - 1][col - 1] = 'O';
        }
        //到这所有的任务结束,循环也该结束了
        break;
    }
    return 0;
}//读入落子函数结束
int read_undo(int g_row,int g_col)//悔棋函数
{
    printf("\n========是否确定结束这轮=======\n");
    printf("========    1) 结束    ========\n");
    printf("========    0) 重下    ========\n");
    printf("===============================\n\n");
    while(1)//开始选择
    {
        int n = 0;//录入选择
        int ret;
        printf("请选择 >> ");
        ret = scanf("%d",&n);
        //老朋友EOF
        if(ret == EOF)
        {
            return -1;//直接退出
        }
        //输入非数字
        if(ret == 0)
        {
            printf("错误,请输入选项提供的数字\n");
            //清空缓冲区
            while((ch = getchar()) != '\n' && ch != EOF) ;
            continue;
        }
        //输入非01数字
        if(n > 1 || n < 0)
        {
            printf("错误,请输入选项提供的数字\n");
            //清空缓冲区
            while((ch = getchar()) != '\n' && ch != EOF) ;
            continue;
        }
        //输入1.1或1abc这样的
        if(((ch = getchar()) < '0' || ch > '9') && ch != '\n')
        {
            printf("错误,请输入选项提供的数字\n");
            //清空缓冲区
            while(ch != '\n' && ch != EOF) ch = getchar();
            continue;  
        }
        //到这说明是个合格的选项了
        if(n == 0)//要悔棋
        {
            chess[g_row - 1][g_col - 1] = '.';//怎么将前一个函数的row和col放到这个函数中
        }
        return n + 1;
    }
}//悔棋函数结束
int is_win(int move)//判赢函数
{
    //g_row - 1,g_col - 1存储了最后一次下的位置
    //如果悔棋了,这一轮最后一次下的地方就是空的
    //返回0：都没赢
    //返回-1：黑赢
    //返回-2：白赢
    int num = 0;//记录连子的个数
    if(chess[g_row - 1][g_col - 1] == '.')
    {
        return 0;//谁都没赢,重新开始
    }
    else//不是空的
    {
        if(move % 2 == 1)//最后一次下的是黑
        {
            //横竖斜四种情况
            //情况1:横
            for(int i = 1;i <= 4;i++)
            {
                if((g_row - 1 + i) > 18)//到边界了
                {
                    break;
                }
                if(chess[g_row - 1 + i][g_col - 1] == '*')
                {
                    num++;
                }
                else
                {
                    break;
                }
            }
            for(int i = 1;i <= 4;i++)
            {
                if((g_row - 1 - i) < 0)
                {
                    break;
                }
                if(chess[g_row - 1 - i][g_col - 1] == '*')
                {
                    num++;
                }
                else
                {
                    break;
                }
            }
            //判断横的是否有5个,没有清零
            if(num == 4)
            {
                return -1;
            }
            else
            {
                num = 0;//将num清零
            }
            //情况2：竖
            for(int i = 1;i <= 4;i++)
            {
                if((g_col - 1 + i) > 18)//到边界了
                {
                    break;
                }
                if(chess[g_row - 1][g_col - 1 + i] == '*')
                {
                    num++;
                }
                else
                {
                    break;
                }
            }
            for(int i = 1;i <= 4;i++)
            {
                if((g_col - 1 - i) < 0)
                {
                    break;
                }
                if(chess[g_row - 1][g_col - 1 - i] == '*')
                {
                    num++;
                }
                else
                {
                    break;
                }
            }
            //判断竖的是否有5个,没有清零
            if(num == 4)
            {
                return -1;
            }
            else
            {
                num = 0;//将num清零
            }
            //情况3：右下斜
            for(int i = 1;i <= 4;i++)
            {
                if(((g_row - 1 + i) > 18) ||((g_col - 1 + i) > 18))//到边界了
                {
                    break;
                }
                if(chess[g_row - 1 + i][g_col - 1 + i] == '*')
                {
                    num++;
                }
                else
                {
                    break;
                }
            }
            for(int i = 1;i <= 4;i++)
            {
                if(((g_row - 1 - i) < 0) || ((g_col - 1 - i) < 0))
                {
                    break;
                }
                if(chess[g_row - 1 - i][g_col - 1 - i] == '*')
                {
                    num++;
                }
                else
                {
                    break;
                }
            }
            //判断右下斜的是否有5个,没有清零
            if(num == 4)
            {
                return -1;
            }
            else
            {
                num = 0;//将num清零
            }
            //情况4：左下斜
            for(int i = 1;i <= 4;i++)
            {
                if(((g_row - 1 + i) > 18) ||((g_col - 1 - i) < 0))//到边界了
                {
                    break;
                }
                if(chess[g_row - 1 + i][g_col - 1 - i] == '*')
                {
                    num++;
                }
                else
                {
                    break;
                }
            }
            for(int i = 1;i <= 4;i++)
            {
                if(((g_row - 1 - i) < 0) || ((g_col - 1 + i) > 18))
                {
                    break;
                }
                if(chess[g_row - 1 - i][g_col - 1 + i] == '*')
                {
                    num++;
                }
                else
                {
                    break;
                }
            }
            //判断左下斜的是否有5个,没有清零
            if(num == 4)
            {
                return -1;
            }
            else
            {
                num = 0;//将num清零
            }
            //到这里四个方向都判断完了
            return 0;
        }
        else if(move % 2 == 0)//最后一次下的是白
        {
            //横竖斜四种情况
            //情况1:横
            for(int i = 1;i <= 4;i++)
            {
                if((g_row - 1 + i) > 18)//到边界了
                {
                    break;
                }
                if(chess[g_row - 1 + i][g_col - 1] == 'O')
                {
                    num++;
                }
                else
                {
                    break;
                }
            }
            for(int i = 1;i <= 4;i++)
            {
                if((g_row - 1 - i) < 0)
                {
                    break;
                }
                if(chess[g_row - 1 - i][g_col - 1] == 'O')
                {
                    num++;
                }
                else
                {
                    break;
                }
            }
            //判断横的是否有5个,没有清零
            if(num >= 4)
            {
                return -2;
            }
            else
            {
                num = 0;//将num清零
            }
            //情况2：竖
            for(int i = 1;i <= 4;i++)
            {
                if((g_col - 1 + i) > 18)//到边界了
                {
                    break;
                }
                if(chess[g_row - 1][g_col - 1 + i] == 'O')
                {
                    num++;
                }
                else
                {
                    break;
                }
            }
            for(int i = 1;i <= 4;i++)
            {
                if((g_col - 1 - i) < 0)
                {
                    break;
                }
                if(chess[g_row - 1][g_col - 1 - i] == 'O')
                {
                    num++;
                }
                else
                {
                    break;
                }
            }
            //判断竖的是否有5个,没有清零
            if(num >= 4)
            {
                return -2;
            }
            else
            {
                num = 0;//将num清零
            }
            //情况3：右下斜
            for(int i = 1;i <= 4;i++)
            {
                if(((g_row - 1 + i) > 18) ||((g_col - 1 + i) > 18))//到边界了
                {
                    break;
                }
                if(chess[g_row - 1 + i][g_col - 1 + i] == 'O')
                {
                    num++;
                }
                else
                {
                    break;
                }
            }
            for(int i = 1;i <= 4;i++)
            {
                if(((g_row - 1 - i) < 0) || ((g_col - 1 - i) < 0))
                {
                    break;
                }
                if(chess[g_row - 1 - i][g_col - 1 - i] == 'O')
                {
                    num++;
                }
                else
                {
                    break;
                }
            }
            //判断右下斜的是否有5个,没有清零
            if(num >= 4)
            {
                return -2;
            }
            else
            {
                num = 0;//将num清零
            }
            //情况4：左下斜
            for(int i = 1;i <= 4;i++)
            {
                if(((g_row - 1 + i) > 18) ||((g_col - 1 - i) < 0))//到边界了
                {
                    break;
                }
                if(chess[g_row - 1 + i][g_col - 1 - i] == 'O')
                {
                    num++;
                }
                else
                {
                    break;
                }
            }
            for(int i = 1;i <= 4;i++)
            {
                if(((g_row - 1 - i) < 0) || ((g_col - 1 + i) > 18))
                {
                    break;
                }
                if(chess[g_row - 1 - i][g_col - 1 + i] == 'O')
                {
                    num++;
                }
                else
                {
                    break;
                }
            }
            //判断左下斜的是否有5个,没有清零
            if(num >= 4)
            {
                return -2;
            }
            else
            {
                num = 0;//将num清零
            }
            //到这里四个方向都判断完了
            return 0;
        }
    }

    return 0;
}//判赢函数结束

void Gobang(void)//五子棋游戏函数
{
    move = 0;//每局重新开始时步数清零
    black_move = 0;
    while(1)//游戏需要不断循环,直至游戏结束,这样开启下轮大循环
    {
        int draw = 0;//判断是否平局
        show_chess();//显示棋盘
        //开始下棋
        int row,col;//每轮决定下的位置
        int note = 0;//判断每轮是否悔棋,作为步数是否增加的标准
        //开始下棋
        if(move % 2 == 0)//黑下
        {
            printf("黑棋第 %d 步\n",black_move + 1);
            printf("轮到 黑棋,请输入 行 列 >> ");
            if(read_move(move,row,col) == -1)//落子
            {
                printf("\n输入结束,退出\n");
                return ;
            }
            //落子完了后再确定结果,是否悔棋
            note = read_undo(g_row,g_col);
            if(note == -1)
            {
                printf("\n输入结束,退出\n");
                return ;
            }
            //悔棋步数不增加
            if(note == 2)
            {
                move++;
                black_move++;
            }
        }
        else//白下
        {
            printf("白棋第 %d 步\n",move - black_move + 1);
            printf("轮到 白棋,请输入 行 列 >> ");
            //落子完了后再结果,是否悔棋
            //判断EOF的情况,该死的EOF
            if(read_move(move,row,col) == -1)
            {
                printf("\n输入结束,退出\n");
                return ;
            }
            note = read_undo(g_row,g_col);
            if(note == -1)
            {
                printf("\n输入结束,退出\n");
                return ;
            }
            if(note == 2)
            {
                move++;
            }
        }
        //下棋结束,开始判断
        //先判断平局
        for(int i = 0;i < 19;i++)
        {
            for(int j = 0;j < 19;j++)
            {
                if(chess[i][j] == '.')//判断是否平局,只需判断是否所有的格子都有棋子
                {
                    draw++;
                }
            }
        }
        if(draw == 0)//说明格子全是棋子了
        {
            printf("平局\n");
            break;
        }
        //再判断是黑胜还是白胜
        draw = is_win(move);//
        if(draw == -1)
        {
            printf("黑方获胜!\n");
            break;
        }
        else if(draw == -2)
        {
            printf("白方获胜!\n");
            break;
        }

    }
    return ;
}//游戏函数结束
#endif
//单词本+小测验
int button = 0;//记录选项的
int ch;
int wordnum = 10;//统计录入的单词数量(默认有十个单词)
char wordbook[1024][100] = {"apple","orange","banana","pencil","cherry","ice","fire","winter","autumn","jungle"};//录入单词的数组
char Chinesebook[1024][100] = {"苹果","橙子","香蕉","铅笔","樱桃","冰","火","冬天","秋天","丛林"};//录入单词对应中文的数组
void print_menu(void);//输出菜单函数
int read_chosen(void);//读入选项函数
void print_list(int wordnum);//列表显示函数
int read_word(void);//录入单词函数
int find_word(void);//查找单词函数
void set_word(int n);//排序函数
int delete_word(void);//删除函数
int print_test(void);//测验函数
int main()
{
    srand((unsigned)time(NULL));//设置种子
    do
    {
        button = 0;
        int note = 0;//记录录入时输入EOF的情况(直接退出)
        print_menu();//输出菜单
        button = read_chosen();//录入选项
        switch(button)
        {
            case 1:
            {
                note = read_word();
                break;
            }
            case 2:
            {
                print_list(wordnum);
                break;
            }
            case 3:
            {
                note = find_word();//查找单词函数
                break;
            }
            case 4:
            {
                int n = 0;
                set_word(n);//排序函数
                break;
            }
            case 5:
            {
                note = delete_word();//删除函数
                break;
            }
            case 6:
            {
                note = print_test();//测验函数
                break;
            }
            case 7:
            {

                break;
            }
            case 0:
            {
                break;
            }
        }
        if(button == 0)
        {
            break;
        }
        if(note == -1)
        {
            break;
        }
    }while(button != 0);
    return 0;
}

void print_menu(void)//输出菜单函数
{
    printf("============ 单 词 本 ============\n");
    printf("  1) 添加单词      2) 列表显示\n");
    printf("  3) 查找单词      4) 按字母排序\n");
    printf("  5) 删除单词      6) 小测验\n");
    printf("  7) 统计          0) 退出\n");
    printf("==================================\n");
}//输出菜单函数结束
int read_chosen(void)//读入选项函数
{
    while(1)
    {
        button = 0;
        printf("请选择 >> ");
        int ret = scanf("%d",&button);
        //如果输入EOF
        if(ret == EOF)
        {
            return 0;//返回0直接退出
        }
        //如果输入非数字
        if(ret == 0)
        {
            printf("错误,请输入选项提供的数字!\n");
            //清空缓冲区
            while((ch = getchar()) != '\n' && ch != EOF) ;
            continue;
        }
        //如果输入数字过大
        if(button > 7 || button < 0)
        {
            printf("错误,请选择选项范围内的数字!\n");
            //防止过大数字后再输些奇奇怪怪的东西,还是清空缓冲区
            while((ch = getchar()) != '\n' && ch != EOF) ;
            continue;
        }
        //防止输入数字后输入非字符
        if(((ch = getchar()) < '0' || ch > '7') && ch != '\n')
        {
            printf("错误,请输入正确的选项!\n");
            //清空缓冲区
            while((ch = getchar()) != '\n' && ch != EOF) ;
            continue;
        }
        //到这说明是个合格的选项了
        return button;
    }
}//读入选项函数
void print_list(int wordnum)//列表显示函数
{
    printf("  序号             英文                   中文\n");
    printf("  ----  ---------------------  --------------------\n");
    int k = 0;//记录录入单词数量的位数
    int j = wordnum;//影武者
    while(j >= 1)
    {
        j /= 10;
        k++;
    }
    //再记录最长位的单词
    int max = 0;
    for(int i = 0;i < wordnum;i++)
    {
        if(strlen(wordbook[i]) > max)
        {
            max = strlen(wordbook[i]);
        }
    }
    for(int i = 0;i < wordnum;i++)
    {
        printf("%-*d      %-*s                 %s\n",k,i + 1,max,wordbook[i],Chinesebook[i]);
    }
}//列表显示函数结束
int read_word(void)//录入单词函数(一次录入一个单词)
{
    while(1)
    {
        char eng[100];//记录英文的数组
        char che[100];//记录中文的数组
        int pin = 0;//用来排除非法输入情况的针
        printf("请输入(单词+中文) >> ");
        int ret = scanf("%99s %99s",eng,che);
        //又是判断不同的情况
        if(ret == EOF)
        {
            return -1;//返回-1
        }
        //输入非字母
        int num = strlen(eng);
        int chnum = strlen(che);
        for(int i = 0;i < num;i++)
        {
            if((eng[i] < 'A') || (eng[i] > 'Z' && eng[i] < 'a') || (eng[i] > 'z'))
            {
                pin++;
            }
        }
        if(pin != 0)
        {
            printf("错误,请输入正确的英文或中文\n");
            //清空缓冲区
            while((ch = getchar()) != '\n' && ch != EOF) ;
            continue;
        }
        pin = 0;//针归零,为下次判断做好准备
        //拒绝重名
        for(int i = 0;i < wordnum;i++)
        {
            pin = 0;
            int max = 0;
            if(strlen(wordbook[i]) > num)//防止出现单词前面一样,只对比前面的现象
            {
                max = strlen(wordbook[i]);
            }
            else
            {
                max = num;
            }
            for(int j = 0;j < max;j++)
            {
                if(eng[j] == wordbook[i][j])
                {
                    pin++;
                }
            }
            if(pin == max)//说明单词完全一样
            {
                pin = -1;
                break;
            }
        }
        if(pin == -1)
        {
            printf("有重复的单词,请输入别的单词\n");
            //清空缓冲区
            while((ch = getchar()) != '\n' && ch != EOF) ;
            continue;
        }
        //拒绝过长单词
        if(num > 99)
        {
            printf("过长,请输入范围内的单词\n");
            //清空缓冲区
            while((ch = getchar()) != '\n' && ch != EOF) ;
            continue;
        }
        //到这就差不多了吧,应该
        //将输入的单词中文录入数组中
        wordnum++;
        for(int i = 0;i < num;i++)
        {
            wordbook[wordnum - 1][i] = eng[i];
        }
        wordbook[wordnum - 1][num] = '\0';  
        for(int i = 0;i < chnum;i++)
        {
            Chinesebook[wordnum - 1][i] = che[i];
        }
        Chinesebook[wordnum - 1][chnum] = '\0'; 
        //能到这说明成功录入
        return 1;
    }
}//录入单词函数结束
int find_word(void)//查找单词函数
{
    while(1)
    {
        printf("请输入您要查找的单词 >> ");
        //又是输入,好烦
        char eng[100];
        int pin = 0;//排查非法输入情况的针
        int ret = scanf("%99s",eng);
        //继续排除非法输入情况
        if(ret == EOF)
        {
            return -1;//返回-1
        }
        int num = strlen(eng);
        //输入非字母
        for(int i = 0;i < num;i++)
        {
            if((eng[i] < 'A') || ((eng[i] > 'Z') && (eng[i] < 'a')) || (eng[i] > 'z'))
            {
                pin++;
            }
        }
        if(pin != 0)
        {
            printf("\n请输入正确的单词,不要输入非字母!\n");
            //清空缓冲区
            while((ch = getchar()) != '\n' && ch != EOF) ;
            continue;
        }
        pin = 0;
        //到这就差不多了吧
        int note = 0;//记录查找单词的顺序
        //开始对比
        for(int i = 0;i < wordnum;i++)
        {
            pin = 0;
            int max = 0;
            if(strlen(wordbook[i]) > num)//防止出现单词前面一样,只对比前面的现象
            {
                max = strlen(wordbook[i]);
            }
            else
            {
                max = num;
            }
            for(int j = 0;j < max;j++)
            {
                if(eng[j] == wordbook[i][j])
                {
                    pin++;
                }
            }
            if(pin == max)//说明单词完全一样
            {
                pin = -1;
                note = i;
                break;
            }
        }
        if(pin == -1)
        {
            printf("\n找到了!是第 %d 个,翻译为 %s\n\n",note + 1,Chinesebook[note]);
            //清空缓冲区
            while((ch = getchar()) != '\n' && ch != EOF) ;
            return 1;
        }
        else
        {
            printf("\n很抱歉,没有您要找的单词\n\n");
            //清空缓冲区
            while((ch = getchar()) != '\n' && ch != EOF) ;
            return 1;
        }
    }
}//查找单词函数结束
void set_word(int n)//排序函数
{
    char replace_word[100];
    char replace_Chinese[100];//影武者数组
    for(int i = 0;i < wordnum;i++)
    {
        for(int j = i + 1;j < wordnum;j++)
        {
            n = 0;//交换完n清零
            while(wordbook[i][0 + n] == wordbook[j][0 + n] && wordbook[i][n] != '\0')
            {
                n++;
            }
            if(wordbook[i][0 + n] > wordbook[j][0 + n])
            {
                for(int k = 0;k < 100;k++)//交换
                {
                    //交换英文(全部交换)
                    replace_word[k] = wordbook[i][k];
                    wordbook[i][k] = wordbook[j][k];
                    wordbook[j][k] = replace_word[k];
                    //交换中文(也是全部交换)
                    replace_Chinese[k] = Chinesebook[i][k];
                    Chinesebook[i][k] = Chinesebook[j][k];
                    Chinesebook[j][k] = replace_Chinese[k];
                }
            }
        }
    }
}//排序函数结束
int delete_word(void)//删除函数
{
    while(1)
    {
        printf("请输入您要删除的单词 >> ");
        //又是输入,好烦
        char eng[100];
        int pin = 0;//排查非法输入情况的针
        int ret = scanf("%99s",eng);
        //继续排除非法输入情况
        if(ret == EOF)
        {
            return -1;//返回-1
        }
        int num = strlen(eng);
        //输入非字母
        for(int i = 0;i < num;i++)
        {
            if((eng[i] < 'A') || ((eng[i] > 'Z') && (eng[i] < 'a')) || (eng[i] > 'z'))
            {
                pin++;
            }
        }
        if(pin != 0)
        {
            printf("\n请输入正确的单词,不要输入非字母!\n");
            //清空缓冲区
            while((ch = getchar()) != '\n' && ch != EOF) ;
            continue;
        }
        pin = 0;
        //到这就差不多了吧
        int note = 0;//记录查找单词的顺序
        //开始对比
        for(int i = 0;i < wordnum;i++)
        {
            pin = 0;
            int max = 0;
            if(strlen(wordbook[i]) > num)//防止出现单词前面一样,只对比前面的现象
            {
                max = strlen(wordbook[i]);
            }
            else
            {
                max = num;
            }
            for(int j = 0;j < max;j++)
            {
                if(eng[j] == wordbook[i][j])
                {
                    pin++;
                }
            }
            if(pin == max)//说明单词完全一样
            {
                pin = -1;
                note = i;
                break;
            }
        }
        if(pin == -1)//到这里说明找到要删去的单词,是第note个
        {
            //将第note个删去——将第note个之后的向前挪一格
            for(int i = note;i < wordnum - 1;i++)
            {
                for(int j = 0;j < 100;j++)//开始往前挪
                {
                    wordbook[i][j] = wordbook[i + 1][j];
                    Chinesebook[i][j] = Chinesebook[i + 1][j];
                }
            }//挪完了
            //录入的单词数量-1
            wordnum--;
            //结束循环
            break;
        }
        else
        {
            printf("\n很抱歉,没有您要删除的单词\n\n");
            //清空缓冲区
            while((ch = getchar()) != '\n' && ch != EOF) ;
            return 1;
        }
    }
}//删除函数结束
int print_test(void)//测验函数
{
    printf("================测验开始=================\n\n");
    int random[5] = {0};//储存随机数
    int m = 0;
    while(m < 5)//录入随机数,还要排除重复的情况
    {
        int pan = 0;//判断随机数是否重复的标志
        random[m] = rand() % ((wordnum - 1) - 0 + 1) + 0;
        //开始排除重复的情况
        for(int i = 0;i <= m;i++)
        {
            if(i > 0)
            {
                for(int j = i - 1;j >= 0;j--)
                {
                    if(random[i] == random[j])//相等
                    {
                        pan++;
                    }
                }   
            }
        }
        if(pan == 0)//说明暂时没有相同的数字
        {
            m++;
        }
        else//说明有相同的数字
        {
            continue;
        }
    }//五个不同的随机数生成完成
    int k = 0;
    while(1)
    {
        char eng[100];//记录英文的数组
        int pin = 0;//用来排除非法输入情况的针
        printf("%s\n",Chinesebook[random[k]]);
        printf("请输入英文 >> ");
        //又要开始输入了
        int ret = scanf("%99s",eng);
        //又是判断不同的情况
        if(ret == EOF)
        {
            return -1;//返回-1
        }
        //输入非字母
        int num = strlen(eng);
        for(int i = 0;i < num;i++)
        {
            if((eng[i] < 'A') || (eng[i] > 'Z' && eng[i] < 'a') || (eng[i] > 'z'))
            {
                pin++;
            }
        }
        if(pin != 0)
        {
            printf("错误,请输入正确的英文\n");
            //清空缓冲区
            while((ch = getchar()) != '\n' && ch != EOF) ;
            continue;
        }
        pin = 0;//针归零,为下次判断做好准备
        //拒绝过长单词
        if(num > 99)
        {
            printf("过长,请输入范围内的单词\n");
            //清空缓冲区
            while((ch = getchar()) != '\n' && ch != EOF) ;
            continue;
        }
        //到这就差不多了吧,应该
        //将输入的单词与目标单词对比
        int n = strlen(wordbook[random[k]]);
        for(int i = 0;i < num;i++)
        {
            if(eng[i] == wordbook[random[k]][i])
            {
                pin++;
            }
            if(pin == n)//说明完全一样
            {
                pin = -1;
                break;//跳出循环,后面的不必比较
            }
        }
        if((pin == -1) && (wordbook[random[k]][n - 1] == '\0') && (eng[num - 1] == '\0'))
        {
            printf("完美！\n\n");
            //清空缓冲区
            while((ch = getchar()) != '\n' && ch != EOF) ;
        }
        else
        {
            printf("错误,请再想一次吧\n\n");
            while((ch = getchar()) != '\n' && ch != EOF) ;
            continue;
        }
        //到这一轮测试结束
        k++;
        if(k >= 5)
        {
            break;
        }
    }
    return 1;
}//测验函数结束