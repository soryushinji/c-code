/* ============================================================
 * 扫雷（增强版）—— 第 1-9 章综合题 第 4 题
 *
 * 编译：gcc -Wall -Wextra -std=c11 -fexec-charset=UTF-8 -o mine mine.c
 *
 * 功能：
 *   1) 三档难度（9x9/10、12x12/25、16x16/50）
 *   2) 沿用上一局雷区
 *   3) 开格 O r c / 标记 F r c / 退出 q
 *   4) 空白格自动展开（递归）
 *   5) 踩雷显示全部雷
 *   6) 通关判断
 *
 * 状态码约定：函数返回 0 = 正常结束，-1 = 遇到 EOF 要退出程序
 * ============================================================ */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RMAXN 28
#define CMAXN 40
#define MAXMINE 500

/* ===== 全局数据（第 1-9 章不能用指针参数，所以放这里）===== */
int  g_ch;                          /* 清缓冲用 */
int  g_button     = 0;              /* 本局选的选项 */
int  g_pre_button = 0;              /* 上一局选的选项 */
int  g_rounds     = 0;              /* 已玩局数 */
int  g_as_usual   = 0;              /* 是否沿用上局雷区 */

char g_outer[RMAXN][CMAXN];         /* 表棋盘：玩家看到的 */
char g_inner[RMAXN][CMAXN];         /* 里棋盘：真值 */

int  g_rmine[MAXMINE];              /* 雷的行 */
int  g_cmine[MAXMINE];              /* 雷的列 */
int  g_mine_count = 0;              /* 本局雷数 */

/* ===== 函数声明 ===== */
void print_menu(void);
int  read_chosen(void);
int  read_usual(void);
void read_outer(int row, int col);
int  read_inner(int row, int col, int mine, int as_usual);
void print_outchess(int row, int col);
int  play_game(int row, int col, int mine, int as_usual);
void print_all_mines(int row, int col);
void open_blank(int row, int col, int r, int c);


/* ============================================================
 *  main
 * ============================================================ */
int main(void)
{
    int ret = 0;

    srand((unsigned)time(NULL));
    print_menu();

    do
    {
        g_button = read_chosen();
        printf("\n");

        if (g_button == -1) break;              /* EOF */
        if (g_button == 0)  break;              /* 退出 */

        /* 至少玩过一局，且这次选的档位和上一局一样，才问是否沿用 */
        if (g_rounds > 0 && g_pre_button == g_button)
        {
            g_as_usual = read_usual();
            printf("\n");
            if (g_as_usual == -1) break;
        }
        else
        {
            g_as_usual = 0;                     /* 换了档位 → 必须重新生成 */
        }

        g_pre_button = g_button;

        switch (g_button)
        {
            case 1:
                ret = play_game(9, 9, 10, g_as_usual);
                break;
            case 2:
                ret = play_game(12, 12, 25, g_as_usual);
                break;
            case 3:
                ret = play_game(16, 16, 50, g_as_usual);
                break;
            case 4:
                printf("自定义功能暂未开放\n");
                ret = 0;
                break;
            default:
                ret = 0;
                break;
        }

        if (ret == 0) g_rounds++;               /* ★ 只有正常玩完才 +1 */
        printf("\n");
        print_menu();

    } while (g_button != 0);

    printf("再见\n");
    return 0;
}


/* ============================================================
 *  菜单
 * ============================================================ */
void print_menu(void)
{
    printf("*********************** 扫  雷 **************************\n");
    printf("   1) 简单   9 x  9   10 雷\n");
    printf("   2) 中等  12 x 12   25 雷\n");
    printf("   3) 困难  16 x 16   50 雷\n");
    printf("   4) 自定义\n");
    printf("   0) 退出\n");
    printf("*********************************************************\n");
}


/* ============================================================
 *  读选项（返回 -1 = EOF）
 * ============================================================ */
int read_chosen(void)
{
    int chosen, ret;

    while (1)
    {
        printf("请选择 >> ");
        ret = scanf("%d", &chosen);

        if (ret == EOF)  return -1;
        if (ret == 0)
        {
            printf("错误：请输入数字\n");
            while ((g_ch = getchar()) != '\n' && g_ch != EOF) ;
            continue;
        }
        if (chosen > 4 || chosen < 0)
        {
            printf("错误：请输入 0 ~ 4\n");
            while ((g_ch = getchar()) != '\n' && g_ch != EOF) ;
            continue;
        }
        /* 数字后面跟了别的字符（如 2.1、2abc） */
        if (((g_ch = getchar()) < '0' || g_ch > '9') && g_ch != '\n')
        {
            printf("错误：请输入整数\n");
            while ((g_ch = getchar()) != '\n' && g_ch != EOF) ;
            continue;
        }
        return chosen;
    }
}


/* ============================================================
 *  问是否沿用上一局雷区（返回 -1 = EOF）
 * ============================================================ */
int read_usual(void)
{
    int chosen, ret;

    while (1)
    {
        printf("本局是否沿用上一局的雷区？(1=是  0=重新生成) >> ");
        ret = scanf("%d", &chosen);

        if (ret == EOF)  return -1;
        if (ret == 0)
        {
            printf("错误：请输入 0 或 1\n");
            while ((g_ch = getchar()) != '\n' && g_ch != EOF) ;
            continue;
        }
        if (chosen > 1 || chosen < 0)
        {
            printf("错误：请输入 0 或 1\n");
            while ((g_ch = getchar()) != '\n' && g_ch != EOF) ;
            continue;
        }
        if (((g_ch = getchar()) < '0' || g_ch > '9') && g_ch != '\n')
        {
            printf("错误：请输入整数\n");
            while ((g_ch = getchar()) != '\n' && g_ch != EOF) ;
            continue;
        }
        return chosen;
    }
}


/* ============================================================
 *  表棋盘：全部置为 '#'
 *  注意：要填 [0 .. row+1] × [0 .. col+1]，和 print_outchess 对齐
 * ============================================================ */
void read_outer(int row, int col)
{
    int i, j;
    for (i = 0; i < row + 2; i++)
        for (j = 0; j < col + 2; j++)
            g_outer[i][j] = '#';
}


/* ============================================================
 *  里棋盘
 *    as_usual == 0 → 重新生成雷
 *    as_usual == 1 → 沿用上一局的 g_rmine / g_cmine
 *  返回 0 = 成功，-1 = 失败（自定义参数不合法）
 * ============================================================ */
int read_inner(int row, int col, int mine, int as_usual)
{
    int i, j, k, m, n;
    char copy[RMAXN][CMAXN];

    if (mine >= row * col)
    {
        printf("雷太多了，放不下\n");
        return -1;
    }

    /* ① 全填 '0'（含边框） */
    for (i = 0; i < row + 2; i++)
        for (j = 0; j < col + 2; j++)
            g_inner[i][j] = '0';

    /* ② 布置雷的坐标（1 .. row，1 .. col） */
    if (as_usual == 0)
    {
        g_mine_count = mine;

        for (i = 0; i < mine; i++)
        {
            g_rmine[i] = rand() % row + 1;      /* ★ 1 .. row */
            g_cmine[i] = rand() % col + 1;      /* ★ 1 .. col */
        }

        /* 查重：任何一个和后面对上就重抽，直到全不重 */
        for (k = 0; k < mine; k++)
        {
            for (m = k + 1; m < mine; m++)
            {
                while (g_rmine[k] == g_rmine[m] && g_cmine[k] == g_cmine[m])
                {
                    g_rmine[m] = rand() % row + 1;
                    g_cmine[m] = rand() % col + 1;
                }
            }
        }
    }
    else
    {
        if (g_mine_count != mine)
        {
            printf("警告：上一局的雷数和这一局不同，改为重新生成\n");
            return read_inner(row, col, mine, 0);
        }
    }

    /* ③ 埋雷 */
    for (i = 0; i < mine; i++)
    {
        g_inner[g_rmine[i]][g_cmine[i]] = '1';
    }

    /* ④ 影武者：算完邻居数要用原始值 */
    for (i = 0; i < row + 2; i++)
        for (j = 0; j < col + 2; j++)
            copy[i][j] = g_inner[i][j];

    /* ⑤ 非雷格填邻居雷数 */
    for (i = 1; i <= row; i++)
    {
        for (j = 1; j <= col; j++)
        {
            if (g_inner[i][j] == '1')
            {
                g_inner[i][j] = '*';
                continue;
            }
            n = (copy[i - 1][j - 1] - '0') + (copy[i - 1][j] - '0')
              + (copy[i - 1][j + 1] - '0') + (copy[i][j - 1] - '0')
              + (copy[i][j + 1] - '0')     + (copy[i + 1][j - 1] - '0')
              + (copy[i + 1][j] - '0')     + (copy[i + 1][j + 1] - '0');
            g_inner[i][j] = (char)(n + '0');
        }
    }

    return 0;
}


/* ============================================================
 *  打印表棋盘
 * ============================================================ */
void print_outchess(int row, int col)
{
    int i, j;
    int ccount = 0, rcount = 0;
    int tmp_c = col, tmp_r = row;

    /* 列号位数 */
    while (tmp_c >= 1) { ccount++; tmp_c /= 10; }
    /* 行号位数 */
    while (tmp_r >= 1) { rcount++; tmp_r /= 10; }

    /* 表头 */
    printf("%*s", rcount + 2, " ");
    for (i = 1; i <= col; i++) printf("%-2d ", i);
    printf("\n");

    printf("%*s", rcount + 2, " ");
    for (i = 1; i <= col; i++) printf("---");
    printf("\n");

    /* 每一行 */
    for (i = 1; i <= row; i++)
    {
        printf("%*d| ", rcount, i);
        for (j = 1; j <= col; j++)
        {
            printf("%-2c ", g_outer[i][j]);
        }
        printf("\n");
    }
}


/* ============================================================
 *  踩雷后：把所有雷显示出来
 * ============================================================ */
void print_all_mines(int row, int col)
{
    int i;
    for (i = 0; i < g_mine_count; i++)
    {
        if (g_outer[g_rmine[i]][g_cmine[i]] != 'F')
            g_outer[g_rmine[i]][g_cmine[i]] = '*';
    }
    (void)row; (void)col;
}


/* ============================================================
 *  递归展开空白格
 *    g_inner[r][c] == '0' 时，把它和 8 个邻居都翻开
 * ============================================================ */
void open_blank(int row, int col, int r, int c)
{
    int dr, dc, nr, nc;

    if (r < 1 || r > row || c < 1 || c > col) return;
    if (g_outer[r][c] != '#') return;            /* 已经开过 / 已标记 */

    g_outer[r][c] = g_inner[r][c];

    if (g_inner[r][c] != '0') return;            /* 不是空白就别继续 */

    for (dr = -1; dr <= 1; dr++)
        for (dc = -1; dc <= 1; dc++)
        {
            if (dr == 0 && dc == 0) continue;
            nr = r + dr;
            nc = c + dc;
            open_blank(row, col, nr, nc);
        }
}


/* ============================================================
 *  一局游戏：★ 这就是你缺的那一段
 *  返回 0 = 正常结束，-1 = EOF
 * ============================================================ */
int play_game(int row, int col, int mine, int as_usual)
{
    int r, c, i, j;
    int opened = 0;
    int left;
    char cmd;

    read_outer(row, col);
    if (read_inner(row, col, mine, as_usual) != 0) return 0;

    left = row * col - mine;

    while (1)
    {
        print_outchess(row, col);
        printf("剩余雷数(未标记): %d    剩余空格: %d\n", mine, left);
        printf("命令 [O 行 列 = 开格 / F 行 列 = 标记 / q = 放弃本局] > ");

        if (scanf(" %c", &cmd) != 1) return -1;

        if (cmd == 'q' || cmd == 'Q')
        {
            printf("放弃本局\n");
            return 0;
        }

        if (cmd != 'O' && cmd != 'o' && cmd != 'F' && cmd != 'f')
        {
            printf("命令只有 O / F / q\n");
            while ((g_ch = getchar()) != '\n' && g_ch != EOF) ;
            continue;
        }

        if (scanf("%d %d", &r, &c) != 2) return -1;

        if (r < 1 || r > row || c < 1 || c > col)
        {
            printf("坐标越界：行 1~%d，列 1~%d\n", row, col);
            while ((g_ch = getchar()) != '\n' && g_ch != EOF) ;
            continue;
        }

        /* ---- 标记 ---- */
        if (cmd == 'F' || cmd == 'f')
        {
            if (g_outer[r][c] == '#')      g_outer[r][c] = 'F';
            else if (g_outer[r][c] == 'F') g_outer[r][c] = '#';
            else printf("这个格子已经翻开，不能标记\n");
            continue;
        }

        /* ---- 开格 ---- */
        if (g_outer[r][c] == 'F')
        {
            printf("这里插了旗，先取消标记再开\n");
            continue;
        }

        if (g_inner[r][c] == '*')
        {
            printf("\n");
            printf("==================================\n");
            printf("  ✗  踩 雷 了 ！\n");
            printf("==================================\n");
            print_all_mines(row, col);
            print_outchess(row, col);
            return 0;
        }

        /* 记录开格前已开数量，算新增 */
        opened = 0;
        for (i = 1; i <= row; i++)
            for (j = 1; j <= col; j++)
                if (g_outer[i][j] != '#' && g_outer[i][j] != 'F') opened++;

        open_blank(row, col, r, c);

        /* 通关判断 */
        left -= 1;
        {
            int now = 0;
            for (i = 1; i <= row; i++)
                for (j = 1; j <= col; j++)
                    if (g_outer[i][j] != '#' && g_outer[i][j] != 'F') now++;

            if (now >= row * col - mine)
            {
                printf("\n");
                printf("==================================\n");
                printf("  ✓  通 关 ！\n");
                printf("==================================\n");
                print_outchess(row, col);
                return 0;
            }
        }
    }
}
