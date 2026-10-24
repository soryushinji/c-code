/* ============================================================
   初等扫雷（单独一题）—— 参考解
   固定 9x9 / 10 颗雷 / 雷区每局随机 / 不能标记 / 无难度
   ============================================================ */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 9
#define MINES 10

int mine[N][N];
int shown[N][N];

void show_menu(void)
{
    printf("\n============ 初 等 扫 雷 ============\n");
    printf("   9 x 9 棋盘，10 颗雷\n");
    printf("   1) 开始游戏\n");
    printf("   0) 退出\n");
    printf("=====================================\n");
    printf("请选择 > ");
}

/* ===== 随机布雷（★ 核心 1）===== */
void setup(void)
{
    int r, c, i;

    for (r = 0; r < N; r++)
        for (c = 0; c < N; c++)
        {
            mine[r][c] = 0;
            shown[r][c] = 0;
        }

    for (i = 0; i < MINES; i++)
    {
        do
        {
            r = rand() % N;          /* 0..8 ✓ 不是 % 10 ✗ */
            c = rand() % N;
        } while (mine[r][c]);        /* ★ 已有雷 → 重抽 */
        mine[r][c] = 1;
    }
}

/* ===== 数周围 8 格的雷（★ 核心 2）===== */
int count_around(int r, int c)
{
    int dr, dc, nr, nc, cnt = 0;
    for (dr = -1; dr <= 1; dr++)
        for (dc = -1; dc <= 1; dc++)
        {
            if (dr == 0 && dc == 0) continue;
            nr = r + dr;
            nc = c + dc;
            if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
            if (mine[nr][nc]) cnt++;
        }
    return cnt;
}

void print_board(void)
{
    int r, c;
    printf("\n     ");
    for (c = 1; c <= N; c++) printf("%d ", c);
    printf("\n    ");
    for (c = 1; c <= N; c++) printf("--");
    printf("\n");

    for (r = 1; r <= N; r++)
    {
        printf("%2d | ", r);
        for (c = 1; c <= N; c++)
        {
            if (!shown[r - 1][c - 1])      printf("# ");
            else if (mine[r - 1][c - 1])   printf("* ");
            else                           printf("%d ", count_around(r - 1, c - 1));
        }
        printf("\n");
    }
    printf("\n   # = 未翻开    * = 雷\n");
}

int open_cell(int r, int c)
{
    if (r < 1 || r > N || c < 1 || c > N) return 3;
    if (shown[r - 1][c - 1]) return 2;
    shown[r - 1][c - 1] = 1;
    if (mine[r - 1][c - 1]) return 1;
    return 0;
}

int check_win(void)
{
    int r, c, opened = 0;
    for (r = 0; r < N; r++)
        for (c = 0; c < N; c++)
            if (shown[r][c]) opened++;
    return (opened == N * N - MINES);
}

int main(void)
{
    int choice, row, col, res, over;

    srand((unsigned)time(NULL));

    while (1)
    {
        show_menu();
        if (scanf("%d", &choice) != 1) break;
        if (choice == 0) { printf("再见！\n"); break; }
        if (choice != 1) { printf("请输入 1 或 0\n"); continue; }

        setup();
        over = 0;
        print_board();

        while (!over)
        {
            printf("请输入要翻开的格子（行 列，1~9）> ");
            if (scanf("%d %d", &row, &col) != 2)
            {
                int c2;
                while ((c2 = getchar()) != '\n' && c2 != EOF)
                    ;                         /* ★ EOF 也要退出 */
                if (feof(stdin) || c2 == EOF)
                {
                    printf("\n(输入结束，退出游戏)\n");
                    return 0;                 /* ★ 别死循环 */
                }
                printf("输入有误，请输入两个整数\n");
                continue;
            }

            res = open_cell(row, col);
            if (res == 3) { printf("坐标非法！请输入 1~9\n"); continue; }
            if (res == 2) { printf("这一格已经翻开过了\n"); continue; }

            print_board();
            if (res == 1)
            {
                printf("踩到雷了！游戏结束 ✗\n");
                over = 1;
            }
            else if (check_win())
            {
                printf("全部翻开，你赢了！✓\n");
                over = 1;
            }
        }
    }
    return 0;
}
