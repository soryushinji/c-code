/* ========================================================================
   字符打印练习_片段
   摘自 new day.c 第 688-701 行（已取消注释）
   ======================================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

int main(void)
{
/* printf("请输入一些字符，输入 # 结束：\n"); */

    while ((ch = getchar()) != '#' && ch != EOF)
    {
        printf("'%c':%d  ", ch, ch);
        count++;

        if (count % 8 == 0)
            putchar('\n');
    }

    if (count % 8 != 0)
        putchar('\n');
    return 0;
}
