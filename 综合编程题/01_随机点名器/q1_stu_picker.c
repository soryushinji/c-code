#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int button = 0;
int sum = 0;
int num = 0;
int ch;
int ID[50] = {0};
int picked_ID[50] = {0};

void print_menu(void);
int read_chosen(void);
int read_people(void);
void read_list(int num);
void show_lisr(int sum);
void choice_N(int n);
int total = 0;
void clear_choice(void);
int picked_note = 0;
void print_num(void);

int main()
{
    srand((unsigned)time(NULL));
    print_menu();
    do
    {
        num = 0;
        button = read_chosen();
        switch(button)
        {
            case 1:
            {
                num = read_people();
                sum += num;
                read_list(num);
                break;
            }
            case 2:
            {
                show_lisr(sum);
                break;
            }
            case 3:
            {
                choice_N(1);
                break;
            }
            case 4:
            {
                int N;
                while(1)
                {
                    int ret;
                    printf("请输入人数 > ");
                    ret = scanf("%d",&N);
                    if(ret == EOF)
                    {
                        printf("错误\n");
                        return -1;
                    }
                    if(ret == 0)
                    {
                        printf("错误,一个合适的正整数!\n");
                        while((ch = getchar()) != '\n'&& ch != EOF);
                        continue;
                    }
                    if(N > sum || N < 1)
                    {
                        printf("错误,请输入范围内的数字!\n");
                        continue;
                    }
                    break;
                }
                choice_N(N);
                break;
            }
            case 5: { clear_choice(); break; }
            case 6: { print_num(); break; }
            case 0: { break; }
        }
        if(num == -1) break;
    }while(button != 0);
    return 0;
}

void print_menu(void)
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
}

int read_chosen(void)
{
while(1)
{
    int button = 0;
    int ret;
    printf("请选择 >> ");
    ret = scanf("%d",&button);
    if(ret == EOF) { printf("错误\n"); return 0; }
    if(ret == 0)
    {
        printf("错误,请输入选项提供的数字!\n");
        while((ch = getchar()) != '\n'&& ch != EOF);
        continue;
    }
    if(button > 6 || button < 0)
    {
        printf("错误,请输入选项提供的数字!\n");
        continue;
    }
    return button;
}
}

int read_people(void)
{
while(1)
{
    int ret;
    printf("请输入人数 > ");
    ret = scanf("%d",&num);
    if(ret == EOF) { printf("错误\n"); return -1; }
    if(ret == 0)
    {
        printf("错误,请输入选项提供的数字!\n");
        while((ch = getchar()) != '\n'&& ch != EOF);
        continue;
    }
    if(num > 50 || num < 1)
    {
        printf("错误,请输入选项提供的数字!\n");
        continue;
    }
    return num;
}
}

void read_list(int num)
{
    printf("请依次输入 %d 个学号\n",num);
    for(int i = sum - num;i < sum;i++)
    {
        int stunum = 0;
        printf("第 %d 个 > ",i + 1);
        while(1)
        {
            int ret;
            ret = scanf("%d",&stunum);
            if(ret == EOF) { printf("错误\n"); return; }
            if(ret == 0)
            {
            printf("错误,请输入选项提供的数字!\n");
            while((ch = getchar()) != '\n'&& ch != EOF);
            continue;
            }
            if(stunum < 1)
            {
            printf("错误,请输入选项提供的数字!\n");
            continue;
            }
            break;
        }
        ID[i] = stunum;
        printf("\n");
    }
    printf("已录入 %d 人\n",num);
}

void show_lisr(int sum)
{
    printf("  序号        学号          状态\n");
    printf("  ----     ---------     ----------\n");
    for(int i = 0;i < sum;i++)
    {
        if(i + 1 < 10)
        {
        printf("  %d         %d              ",i + 1,ID[i]);
        if(ID[i] == picked_ID[i]) printf("已选中");
        else printf("未选中");
        printf("\n");
        }
        else
        {
        printf("  %d        %d              ",i + 1,ID[i]);
        if(ID[i] == picked_ID[i]) printf("已选中");
        else printf("未选中");
        printf("\n");
        }
    }
}

void choice_N(int n)
{
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
        if (!picked_ID[i])
            left++;

    /* ③ 全抽过了 */
    if (left == 0)
    {
        printf("[提示] 所有人都抽过了，请先选 5 重置\n");
        return;
    }

    /* ④ 要抽的比剩下的多 -> 改成抽剩下的 */
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
        } while (picked_ID[j]);

        picked_ID[j] = ID[j];
        printf("第 %d 个: %d 号\n", i + 1, ID[j]);
    }
}

void clear_choice(void)
{
    for(int i = 0;i < sum;i++) picked_ID[i] = 0;
    picked_note++;
    printf("重置完成\n");
}

void print_num(void)
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
}
