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
    while(1)//小循环,输入正确的位置才能退出
    {
        int row,col;
        int ret;
        ret = scanf("%d %d",&row,&col);//读入落子位置
        //判断输入的落子位置是否合法
        if(ret == EOF)//老朋友EOF
        {
            return;//直接退出
        }
        if(ret == 0)//输入非数字字符
        {
            printf("错误,请输入正确的位置\n");
            //清空缓冲区
            while((ch = getchar()) != '\n' && ch != EOF)  ;
            continue;
        }
        //输入的行列不在范围
        if(row > 18 || row < 0 || col > 18 || col < 0)
        {
            printf("错误,请输入棋盘范围内的行列\n");
            //清空缓冲区
            while((ch = getchar()) != '\n' && ch != EOF)  ;
            continue;
        }
        
    }
    return 0;
}