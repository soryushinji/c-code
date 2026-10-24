#include <stdio.h>

#define ROW 19
#define COL 19

int button = 0;
int ch;
char chess[ROW][COL];
int move = 0;
int black_move = 0;

void print_menu(void);
int read_chosen(void);
void Gobang(void);
void print_chess(void);
void show_chess(void);
int read_move(int move,int row,int col);
int g_row = 0;
int g_col = 0;
int read_undo(int g_row,int g_col);
int is_win(int move);

int main(void)
{
    do
    {
        print_chess();
        print_menu();
        button = read_chosen();
        if(button == 1) Gobang();
    } while (button != 0);
    return 0;
}

void print_menu(void)
{
    printf("================ 五 子 棋 ================\n");
    printf("  1) 开始新局\n");
    printf("  0) 退出\n");
    printf("==========================================\n");
}

int read_chosen(void)
{
    while(1)
    {
        int chosen, ret;
        printf("请选择 >> ");
        ret = scanf("%d",&chosen);
        if(ret == EOF) return -1;
        if(ret == 0) { printf("错误\n"); while((ch=getchar())!='\n'&&ch!=EOF); continue; }
        if(chosen >= 2 || chosen < 0) { printf("错误\n"); while((ch=getchar())!='\n'&&ch!=EOF); continue; }
        if(((ch = getchar()) < '0' || ch > '9') && ch != '\n')
        { printf("错误\n"); while(ch!='\n'&&ch!=EOF) ch=getchar(); continue; }
        return chosen;
    }
}

void print_chess(void)
{
    for(int i = 0;i < ROW;i++)
        for(int j = 0;j < COL;j++)
            chess[i][j] = '.';
}

void show_chess(void)
{
    printf("      1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19\n ");
    printf("  -----------------------------------------------------------\n");
    for(int i = 0;i < ROW;i++)
    {
        if(i + 1 < 10) printf("%d  |",i + 1);
        else           printf("%d |",i + 1);
        for(int j = 0;j < COL;j++) printf("  %c",chess[i][j]);
        printf("\n");
    }
    printf("\n  . 空   * 黑   O 白   \n\n");
}

int read_move(int move,int row,int col)
{
    while(1)
    {
        int ret;
        ret = scanf("%d %d",&row,&col);
        if(ret == EOF) return -1;
        if(ret == 0) { printf("错误\n"); while((ch=getchar())!='\n'&&ch!=EOF); continue; }
        if(row > 19 || row < 1 || col > 19 || col < 1)
        { printf("错误,范围\n"); while((ch=getchar())!='\n'&&ch!=EOF); continue; }
        if(chess[row-1][col-1] == '*' || chess[row-1][col-1] == 'O')
        { printf("错误,有子\n"); while((ch=getchar())!='\n'&&ch!=EOF); continue; }
        g_row = row;
        g_col = col;
        if(move % 2 == 0) chess[row-1][col-1] = '*';
        else              chess[row-1][col-1] = 'O';
        break;
    }
    return 0;
}

int read_undo(int g_row,int g_col)
{
    while(1)
    {
        int n = 0, ret;
        ret = scanf("%d",&n);
        if(ret == EOF) return -1;
        if(ret == 0) { printf("错误\n"); while((ch=getchar())!='\n'&&ch!=EOF); continue; }
        if(n > 1 || n < 0) { printf("错误\n"); while((ch=getchar())!='\n'&&ch!=EOF); continue; }
        if(((ch = getchar()) < '0' || ch > '9') && ch != '\n')
        { printf("错误\n"); while(ch!='\n'&&ch!=EOF) ch=getchar(); continue; }
        if(n == 0) chess[g_row-1][g_col-1] = '.';
        return n + 1;
    }
}

/* ===== 学生的 is_win（最新版，边界已补齐）===== */
int is_win(int move)
{
    int num = 0;
    if(chess[g_row-1][g_col-1]=='.') return 0;
    if(move % 2 == 1)
    {
        for(int i=1;i<=4;i++){ if((g_row-1+i)>18) break; if(chess[g_row-1+i][g_col-1]=='*') num++; else break; }
        for(int i=1;i<=4;i++){ if((g_row-1-i)<0) break; if(chess[g_row-1-i][g_col-1]=='*') num++; else break; }
        if(num==4) return -1; else num=0;
        for(int i=1;i<=4;i++){ if((g_col-1+i)>18) break; if(chess[g_row-1][g_col-1+i]=='*') num++; else break; }
        for(int i=1;i<=4;i++){ if((g_col-1-i)<0) break; if(chess[g_row-1][g_col-1-i]=='*') num++; else break; }
        if(num==4) return -1; else num=0;
        for(int i=1;i<=4;i++){ if(((g_row-1+i)>18)||((g_col-1+i)>18)) break; if(chess[g_row-1+i][g_col-1+i]=='*') num++; else break; }
        for(int i=1;i<=4;i++){ if(((g_row-1-i)<0)||((g_col-1-i)<0)) break; if(chess[g_row-1-i][g_col-1-i]=='*') num++; else break; }
        if(num==4) return -1; else num=0;
        for(int i=1;i<=4;i++){ if(((g_row-1+i)>18)||((g_col-1-i)<0)) break; if(chess[g_row-1+i][g_col-1-i]=='*') num++; else break; }
        for(int i=1;i<=4;i++){ if(((g_row-1-i)<0)||((g_col-1+i)>18)) break; if(chess[g_row-1-i][g_col-1+i]=='*') num++; else break; }
        if(num==4) return -1; else num=0;
        return 0;
    }
    else
    {
        for(int i=1;i<=4;i++){ if((g_row-1+i)>18) break; if(chess[g_row-1+i][g_col-1]=='O') num++; else break; }
        for(int i=1;i<=4;i++){ if((g_row-1-i)<0) break; if(chess[g_row-1-i][g_col-1]=='O') num++; else break; }
        if(num>=4) return -2; else num=0;
        for(int i=1;i<=4;i++){ if((g_col-1+i)>18) break; if(chess[g_row-1][g_col-1+i]=='O') num++; else break; }
        for(int i=1;i<=4;i++){ if((g_col-1-i)<0) break; if(chess[g_row-1][g_col-1-i]=='O') num++; else break; }
        if(num>=4) return -2; else num=0;
        for(int i=1;i<=4;i++){ if(((g_row-1+i)>18)||((g_col-1+i)>18)) break; if(chess[g_row-1+i][g_col-1+i]=='O') num++; else break; }
        for(int i=1;i<=4;i++){ if(((g_row-1-i)<0)||((g_col-1-i)<0)) break; if(chess[g_row-1-i][g_col-1-i]=='O') num++; else break; }
        if(num>=4) return -2; else num=0;
        for(int i=1;i<=4;i++){ if(((g_row-1+i)>18)||((g_col-1-i)<0)) break; if(chess[g_row-1+i][g_col-1-i]=='O') num++; else break; }
        for(int i=1;i<=4;i++){ if(((g_row-1-i)<0)||((g_col-1+i)>18)) break; if(chess[g_row-1-i][g_col-1+i]=='O') num++; else break; }
        if(num>=4) return -2; else num=0;
        return 0;
    }
}

void Gobang(void)
{
    move = 0;
    black_move = 0;
    while(1)
    {
        int draw = 0;
        show_chess();
        int row,col;
        int note = 0;
        if(move % 2 == 0)
        {
            printf("黑棋第 %d 步\n",black_move + 1);
            printf("轮到 黑棋,请输入 行 列 >> ");
            if(read_move(move,row,col) == -1) { printf("\n输入结束,退出\n"); return ; }
            note = read_undo(g_row,g_col);
            if(note == -1) { printf("\n输入结束,退出\n"); return ; }
            if(note == 2) { move++; black_move++; }
        }
        else
        {
            printf("白棋第 %d 步\n",move - black_move + 1);
            printf("轮到 白棋,请输入 行 列 >> ");
            if(read_move(move,row,col) == -1) { printf("\n输入结束,退出\n"); return ; }
            note = read_undo(g_row,g_col);
            if(note == -1) { printf("\n输入结束,退出\n"); return ; }
            if(note == 2) { move++; }
        }
        for(int i = 0;i < 19;i++)
            for(int j = 0;j < 19;j++)
                if(chess[i][j] == '.') draw++;
        if(draw == 0) { printf("平局\n"); break; }
        draw = is_win(move);
        if(draw == -1) { printf("\n*** 黑方获胜! ***\n"); break; }
        else if(draw == -2) { printf("\n*** 白方获胜! ***\n"); break; }
    }
    return ;
}