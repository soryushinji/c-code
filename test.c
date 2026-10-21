#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAXN 16               /* 数组按最大尺寸声明 */

/* ======================= 全局数据 ======================= */
int mine[MAXN][MAXN];         /* 1 = 有雷，0 = 无雷 */
int state[MAXN][MAXN];        /* 0 未知，1 已翻开，2 已标记 */
int n = 9;                    /* 实际尺寸（运行时定） */
int totalMines = 10;          /* 实际雷数 */

int gameOver = 0;             /* 本局是否结束 */
int win = 0;                  /* 是否胜利 */

/* ---------- 上一局雷区（用于“沿用”） ---------- */
int haveLast = 0;
int lastN = 0;
int lastMines = 0;
int lastMine[MAXN][MAXN];

/* ---------- 计时 & 最佳成绩 ---------- */
time_t startTime;
double bestTime[5] = { -1, -1, -1, -1, -1 };  /* 下标 1~3 难度，4 自定义 */

/* ======================= 工具函数 ======================= */
/* 计算 (r,c) 周围 8 格的雷数，注意循环用 n 不用 MAXN */
static int countAdj(int r, int c) {
    int cnt = 0;
    for (int dr = -1; dr <= 1; dr++) {
        for (int dc = -1; dc <= 1; dc++) {
            if (dr == 0 && dc == 0) continue;
            int nr = r + dr, nc = c + dc;
            if (nr >= 0 && nr < n && nc >= 0 && nc < n && mine[nr][nc])
                cnt++;
        }
    }
    return cnt;
}

static int countFlags(void) {
    int cnt = 0;
    for (int r = 0; r < n; r++)
        for (int c = 0; c < n; c++)
            if (state[r][c] == 2) cnt++;
    return cnt;
}

/* ======================= 布雷（不重复、数量准确） ======================= */
static void placeMines(void) {
    int idx[MAXN * MAXN];
    int total = n * n;
    for (int i = 0; i < total; i++) idx[i] = i;
    /* Fisher-Yates 洗牌 */
    for (int i = total - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int t = idx[i]; idx[i] = idx[j]; idx[j] = t;
    }
    for (int i = 0; i < totalMines; i++)
        mine[idx[i] / n][idx[i] % n] = 1;
}

/* ======================= 显示棋盘 ======================= */
static void printBoard(void) {
    printf("\n    ");
    for (int c = 0; c < n; c++) printf("%2d", c + 1);
    printf("\n");

    printf("   +");
    for (int c = 0; c < n; c++) printf("--");
    printf("\n");

    for (int r = 0; r < n; r++) {
        printf("%2d |", r + 1);
        for (int c = 0; c < n; c++) {
            char ch;
            if (state[r][c] == 1) {              /* 已翻开 */
                if (mine[r][c]) ch = '*';
                else {
                    int cnt = countAdj(r, c);
                    ch = (cnt == 0) ? ' ' : (char)('0' + cnt);
                }
            } else if (state[r][c] == 2) {       /* 已标记 */
                ch = 'F';
            } else {                             /* 未翻开 */
                ch = (gameOver && mine[r][c]) ? '*' : '#';
            }
            printf("%2c", ch);
        }
        printf("\n");
    }
    printf("\n  # 未知   F 标记   * 雷   数字 = 周围雷数\n");
}

/* ======================= 空白递归展开 ======================= */
static void expand(int r, int c) {
    if (r < 0 || r >= n || c < 0 || c >= n) return;
    if (state[r][c] != 0) return;                /* 已翻开 / 已标记 */
    if (mine[r][c]) return;
    state[r][c] = 1;
    if (countAdj(r, c) == 0) {                   /* 空白格才递归 */
        for (int dr = -1; dr <= 1; dr++)
            for (int dc = -1; dc <= 1; dc++)
                if (dr || dc) expand(r + dr, c + dc);
    }
}

/* ======================= 翻开 / 标记 ======================= */
static int openCell(int r, int c) {
    if (r < 1 || r > n || c < 1 || c > n) {
        printf("坐标越界！行列范围应为 1~%d\n", n);
        return 0;
    }
    r--; c--;
    if (state[r][c] == 1) { printf("该格已经翻开过了\n"); return 0; }
    if (state[r][c] == 2) { printf("该格已被标记(F)，请先取消标记\n"); return 0; }
    if (mine[r][c]) {                            /* 踩雷 */
        state[r][c] = 1;
        gameOver = 1;
        win = 0;
        return 1;
    }
    expand(r, c);
    return 1;
}

static void flagCell(int r, int c) {
    if (r < 1 || r > n || c < 1 || c > n) {
        printf("坐标越界！行列范围应为 1~%d\n", n);
        return;
    }
    r--; c--;
    if (state[r][c] == 1) { printf("已翻开的格子不能标记\n"); return; }
    if (state[r][c] == 2) { state[r][c] = 0; printf("已取消标记\n"); }
    else                  { state[r][c] = 2; printf("已标记 F\n"); }
}

/* ======================= 胜利判定（标记不算翻开） ======================= */
static int checkWin(void) {
    for (int r = 0; r < n; r++)
        for (int c = 0; c < n; c++)
            if (!mine[r][c] && state[r][c] != 1) return 0;
    return 1;
}

/* ======================= 一局游戏 ======================= */
static void playGame(int idx) {
    char line[256];
    while (1) {
        printBoard();
        printf("剩余雷数(未标记): %d\n", totalMines - countFlags());
        if (gameOver) break;

        printf("命令 > ");
        fflush(stdout);
        if (!fgets(line, sizeof(line), stdin)) return;

        char cmd;
        int r = 0, c = 0;
        int k = sscanf(line, " %c %d %d", &cmd, &r, &c);
        if (k < 1) continue;

        if (cmd == 'Q' || cmd == 'q') {
            printf("已退出本局，返回主菜单\n");
            return;
        } else if (cmd == 'O' || cmd == 'o') {
            if (k != 3) { printf("格式：O 行 列 （例：O 5 4）\n"); continue; }
            if (openCell(r, c) && !gameOver && checkWin()) {
                gameOver = 1;
                win = 1;
            }
        } else if (cmd == 'F' || cmd == 'f') {
            if (k != 3) { printf("格式：F 行 列 （例：F 3 7）\n"); continue; }
            flagCell(r, c);
        } else {
            printf("未知命令 '%c'，可用：O / F / Q\n", cmd);
        }
    }

    /* ---------- 本局结束 ---------- */
    double elapsed = difftime(time(NULL), startTime);
    printf("\n==========================================\n");
    if (win) {
        printf("恭喜！你清除了所有非雷格，胜利！\n");
        printf("本局用时：%.0f 秒\n", elapsed);
        if (bestTime[idx] < 0 || elapsed < bestTime[idx]) {
            bestTime[idx] = elapsed;
            printf("★ 新纪录！该难度最佳成绩：%.0f 秒\n", bestTime[idx]);
        } else {
            printf("该难度最佳成绩：%.0f 秒\n", bestTime[idx]);
        }
    } else {
        printf("踩到雷了，本局失败！\n");
        printf("本局用时：%.0f 秒\n", elapsed);
    }
    printf("==========================================\n");
    printf("按回车返回主菜单...");
    fflush(stdout);
    fgets(line, sizeof(line), stdin);
}

/* ======================= 主函数 ======================= */
int main(void) {
    srand((unsigned)time(NULL));
    char line[256];

    while (1) {
        printf("\n==================== 扫  雷 ====================\n");
        printf("   1) 简单   9 x 9   10 雷\n");
        printf("   2) 中等  12 x 12  25 雷\n");
        printf("   3) 困难  16 x 16  50 雷\n");
        printf("   4) 自定义尺寸\n");
        printf("   0) 退出\n");
        printf("================================================\n");
        printf("请选择 > ");
        fflush(stdout);

        if (!fgets(line, sizeof(line), stdin)) break;
        int choice;
        if (sscanf(line, "%d", &choice) != 1) { printf("请输入数字\n"); continue; }
        if (choice == 0) { printf("游戏结束，再见！\n"); break; }
        if (choice < 1 || choice > 4) { printf("无效选项，请输入 0~4\n"); continue; }

        /* ---------- 自定义参数 ---------- */
        int cn = 9, cm = 10;
        if (choice == 4) {
            printf("请输入棋盘尺寸 n (2~%d): ", MAXN);
            fflush(stdout);
            if (!fgets(line, sizeof(line), stdin)) break;
            if (sscanf(line, "%d", &cn) != 1 || cn < 2 || cn > MAXN) {
                printf("尺寸无效\n"); continue;
            }
            int maxM = cn * cn - 1;
            printf("请输入雷数 (1~%d): ", maxM);
            fflush(stdout);
            if (!fgets(line, sizeof(line), stdin)) break;
            if (sscanf(line, "%d", &cm) != 1 || cm < 1 || cm > maxM) {
                printf("雷数无效\n"); continue;
            }
        }

        /* ---------- 是否沿用上一局 ---------- */
        int reuse = 0;
        if (haveLast) {
            printf("上一局：%d x %d，%d 雷\n", lastN, lastN, lastMines);
            printf("本局是否沿用上一局的雷区？(1=是  0=重新生成) > ");
            fflush(stdout);
            if (!fgets(line, sizeof(line), stdin)) break;
            sscanf(line, "%d", &reuse);
        }

        /* ---------- 建立雷区 ---------- */
        if (reuse && haveLast) {
            n = lastN;
            totalMines = lastMines;
            memcpy(mine, lastMine, sizeof(mine));
        } else {
            switch (choice) {
                case 1: n = 9;  totalMines = 10; break;
                case 2: n = 12; totalMines = 25; break;
                case 3: n = 16; totalMines = 50; break;
                case 4: n = cn; totalMines = cm; break;
            }
            memset(mine, 0, sizeof(mine));
            placeMines();
        }

        /* ---------- 初始化本局 ---------- */
        memset(state, 0, sizeof(state));
        gameOver = 0;
        win = 0;
        startTime = time(NULL);

        int idx = (choice >= 1 && choice <= 3) ? choice : 4;
        playGame(idx);

        /* ---------- 保存为“上一局” ---------- */
        haveLast = 1;
        lastN = n;
        lastMines = totalMines;
        memcpy(lastMine, mine, sizeof(mine));
    }
    return 0;
}