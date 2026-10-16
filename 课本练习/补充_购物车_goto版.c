/* ========================================================================
   补充_购物车_goto版
   摘自 new day.c 第 524-561 行（已取消注释）
   ======================================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

int main(void)
{
// 方法一：用goto语句
// char key;
// start:
// printf("请问您要买(a:洋蓟)(b:甜菜)(c:胡萝卜)(q:退出):");
// scanf(" %c",&key);
// double ynum = 0;
// double tnum = 0;
// double hnum = 0;
// switch(key)
//     {
//     case 'a':
//         {
//             printf("请输入洋蓟的磅数：");
//             scanf("%lf",&ynum);
//             goto start;
//         }
//     case 'b':
//         {
//             printf("请输入甜菜的磅数：");
//             scanf("%lf",&tnum);
//             goto start;
//         }
//     case 'c':
//         {
//             printf("请输入胡萝卜的磅数：");
//             scanf("%lf",&hnum);
//             goto start;
//         }
//     case 'q':
//         {
//             printf("购买结束,即将打印小票");
//             break;
//         }
//         default:
//         {
//             printf("请输入正确的字母！");
//         }
//     }
    return 0;
}
