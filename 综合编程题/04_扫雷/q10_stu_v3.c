#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int button = 0;
char outer[11][11];
char inner[11][11];

void menu_print(void);
int  choice_print(void);
void game(void);
void mine_set(void);
void inner_set(void);
void chess_print(void);
void select_cell(void);

int main(void)
{
    srand((unsigned)time(NULL));
    while(1)
    {
        mine_set();
        inner_set();
        button = 0;
        menu_print();
        button = choice_print();
        if(button == 0) break;
        else game();
    }
    return 0;
}

void menu_print(void)
{
    printf("============ 初 等 扫 雷 ============\n");
    printf("   9 x 9 棋盘,10 颗雷\n");
    printf("   1) 开始游戏\n");
    printf("   0) 退出\n");
    printf("=====================================\n");
}

int choice_print(void)
{
    while(1)
    {
        int button = 0;
        printf("请选择>>");
        if (scanf("%d",&button) != 1) return 0;
        if(button == 1) return button;
        else if(button == 0) { printf("退出游戏\n"); return 0; }
        else { printf("错误,请输入正确的选项\n"); continue; }
    }
}

void mine_set(void)
{
    int placed = 0;
    for(int i = 0;i < 11;i++)
        for(int j = 0;j < 11;j++)
            inner[i][j] = '0';

    while (placed < 10)
    {
        int r = rand() % 9 + 1;
        int c = rand() % 9 + 1;
        if (inner[r][c] == '1') continue;
        inner[r][c] = '1';
        placed++;
    }

    for(int i = 1;i <= 9;i++)
        for(int j = 1;j <= 9;j++)
            outer[i][j] = '#';
}

void inner_set(void)
{
    char copy[11][11];
    for(int i = 0;i < 11;i++)
        for(int j = 0;j < 11;j++)
            copy[i][j] = inner[i][j];

    for(int i = 1;i <= 9;i++)
    {
        int k = 0;
        for(int j = 1;j <= 9;j++)
        {
            if(copy[i][j] == '1') { inner[i][j] = '*'; continue; }
            k = (int)((copy[i - 1][j - 1] - '0')+ (copy[i][j - 1] - '0') + (copy[i + 1][j - 1] - '0') + (copy[i + 1][j] - '0') + (copy[i + 1][j + 1] - '0')+ (copy[i][j + 1] - '0') + (copy[i - 1][j + 1] - '0') + (copy[i - 1][j] - '0'));
            inner[i][j] = (char)('0' + k);
        }
    }
}

void chess_print(void)
{
    printf("  1 2 3 4 5 6 7 8 9\n");
    printf("  _ _ _ _ _ _ _ _ _\n");
    for(int i = 1;i <= 9;i++)
    {
        printf("%d|",i);
        for(int j = 1;j <= 9;j++) printf("%c ",outer[i][j]);
        printf("\n");
    }
    printf("\n");
}

void select_cell(void)
{
while(1)
{
    int row, col, c, opened;

    printf("请选择您要检查的格子( 行 列):");
    if (scanf("%d %d", &row, &col) != 2)      /* ★ 只有这一次 scanf */
    {
        while ((c = getchar()) != '\n' && c != EOF);
        if (c == EOF) return;
        printf("输入有误\n");
        continue;
    }
    if (row < 1 || row > 9 || col < 1 || col > 9)
    {
        printf("坐标非法！请输入 1~9\n");
        continue;
    }

    /* 已经翻过的格子 */
    if (outer[row][col] != '#')
    {
        printf("这一格已经翻开过了\n");
        continue;
    }

    outer[row][col] = inner[row][col];

    /* ① 先判踩雷 */
    if(outer[row][col] == '*')
    {
        printf("*******************boom!!!~~~~~*****************\n");
        printf("******************你被炸死了!!*******************\n");
        chess_print();
        break;
    }

    /* ② 再数进度 */
    opened = 0;
    for (int i = 1; i <= 9; i++)
        for (int j = 1; j <= 9; j++)
            if (outer[i][j] != '#') opened++;

    chess_print();

    /* ③ 最后判胜利 */
    if(opened >= 71)
    {
        printf("恭喜您找出了所有的雷！\n");
        break;
    }
}
}

void game(void)
{
    chess_print();
    select_cell();
}
