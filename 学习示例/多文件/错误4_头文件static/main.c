#include <stdio.h>
void show_a(void); void show_b(void);
int main(void)
{
    printf("=== 头文件里放 static 的后果 ===\n");
    show_a();   /* a.c 里的 s_counter 变成 1 */
    show_b();   /* b.c 里的 s_counter 还是 0！*/
    show_a();   /* a.c 里的 s_counter 变成 2 */
    printf("\n每个 .c 都有自己的一份 s_counter，互不相干\n");
    return 0;
}
