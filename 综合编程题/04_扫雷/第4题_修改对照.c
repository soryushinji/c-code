/* ============================================================================
   第 4 题　全能文本分析器
   ----------------------------------------------------------------------------
   这是【在你的原代码基础上修改】的版本：
     · 你原来写的部分，用  #if 0 ... #endif  原样包起来保留
     · 紧接着是  ✅ 修正后的写法
     · 没改动的部分（分类 if-else 等）保持原样，不重复贴

   为什么用 #if 0 而不是块注释来注释旧代码？
     因为你旧代码里面本身就有块注释，而 C 语言【不允许块注释嵌套】。
     外层块注释会被内层的结束符号提前截断，后面的代码就变成"活代码"，编译报错。
     #if 0 ... #endif 是预处理指令，可以安全地包住任何内容 —— 包括注释。
   ============================================================================ */
#include <stdio.h>
#include <ctype.h>          /* ★ 你用了 islower/isupper/isdigit/ispunct/isspace
                                  就必须包含 ctype.h（原代码里漏了） */

int main(void)
{
/* ────────────────────────────────────────────────────────────────────────────
   ① 分类计数器  —— 这一段你写对了，一字未改
   ──────────────────────────────────────────────────────────────────────────── */
int totalnum = 0;
int digits = 0;
int blank = 0;          /* 32 */
int punctuation = 0;    /* 32~64  91~96  123~126 */
int others = 0;
int dalpha = 0;         /* 65~90 */
int xalpha = 0;         /* 97~122 */
int yalpha = 0;         /* 65 69 73 79 85 97 101 105 111 117 */

#if 0
/* ========== 你原来的写法开始（存"字符序列"，n 不可控会越界） ========== */

char ch1[128];
int ch1num[128];
int i = 0;
int num = 0;

/* ========== 你原来的写法结束 ========== */
#endif

/* ✅ 改成：大小为 128 的计数数组，下标就是 ASCII 码
      —— 题册提示的就是这个。= {0} 不能省，否则初值是随机数。          */
int count[128] = {0};

int ch;

printf("请输入文本（以 # 结束）:");

/* ────────────────────────────────────────────────────────────────────────────
   ② 读取循环
   ──────────────────────────────────────────────────────────────────────────── */
#if 0
/* ========== 你原来的 do-while 开始 ==========
   问题：totalnum++ 写在判断之前，所以 # 和 EOF 也被算进总数；
         ch1[i]=ch 把 \n、空格、# 全部存进数组，后面统计会混入。

do
{
    ch = getchar();
    totalnum++;
    // 不用ctype.h
    // （这里是你那段被注释掉的 ASCII 范围判断版本，共约 45 行，略）
    // （这里是你后来启用的 ctype.h 版本：islower/isupper/isdigit/
    //   ispunct/isspace，逻辑正确，下面新循环里原样保留）
    ch1[i] = ch;
    i++;
} while(ch != '#' && ch != EOF);   // #35

   ========== 你原来的 do-while 结束 ========== */
#endif

/* ✅ 改成：while 的"条件成立才进循环体"
      所以 # 和 EOF 根本不会被执行到 → 后面所有的 "- 1" 补丁都能删掉   */
while ((ch = getchar()) != EOF && ch != '#')
{
    totalnum++;                    /* ← 只有真字符才计数 */

    /* ── 你的分类逻辑：一字未改（注意 isupper 里原来是双引号 "I"，已改回 'I'）── */
    if (islower(ch))
    {
        xalpha++;
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        {
            yalpha++;
        }
    }
    else if (isupper(ch))
    {
        dalpha++;
        if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
        {
            yalpha++;
        }
    }
    else if (isdigit(ch))
    {
        digits++;
    }
    else if (ispunct(ch))
    {
        punctuation++;
    }
    else if (isspace(ch))
    {
        blank++;
    }
    else
    {
        others++;
    }

    /* ── ★ 新增：只统计可打印字符（ASCII 33~126）──
          \n(10)、空格(32) 自动被排除；下标锁在 33~126，不可能出界。 */
    if (ch >= 33 && ch <= 126)
    {
        count[ch]++;
    }
}

/* ────────────────────────────────────────────────────────────────────────────
   ③ 频率统计：整段删除（约 20 行）
      它的问题是：只有字符"第一次出现"的位置才等于真实次数，
      第二、三次出现的位置会少算；而且 i 没有上限 → 越界写内存。
   ──────────────────────────────────────────────────────────────────────────── */
#if 0
/* ========== 你原来的写法开始 ========== */

for(int j = 0;j < i;j++)
{
    num = 0;
    for(int k = j + 1;k < i;k++)
    {

        if(ch1[j] == ch1[k])
        {
            num++;
        }
    }
    if(num != 0)
    {
        num += 1;
    }
    ch1num[j] = num;
}

/* ========== 你原来的写法结束 ========== */
#endif

/* ────────────────────────────────────────────────────────────────────────────
   ④ 排序：整段删除（它只是想把最大频字符挪到下标 0，用计数数组后不需要了）
   ──────────────────────────────────────────────────────────────────────────── */
#if 0
/* ========== 你原来的写法开始 ========== */

int max = 0;
char max1;
for(int j = 0;j < i;j++)
{
    for(int k = j;k < i;k++)
    {
        if(ch1num[k] >= ch1num[j])
        {
            max = ch1num[j];
            ch1num[j] = ch1num[k];
            ch1num[k] = max;
            max1 = ch1[j];
            ch1[j] = ch1[k];
            ch1[k] = max1;
        }
    }
}
// 检验数组是否成功选出最大频字符和出现次数
// for(int j = 0;j <= i;j++)
// {
//     printf("%d ",ch1num[j]);
// }

/* ========== 你原来的写法结束 ========== */
#endif

/* ────────────────────────────────────────────────────────────────────────────
   ⑥ 百分比：删掉所有 "- 1"，改成"分母为 0 时给 0.0"
   ──────────────────────────────────────────────────────────────────────────── */
#if 0
/* ========== 你原来的写法开始 ==========
   问题 1：只输入 # 时 totalnum-1 = 0 → 除以 0 → 打印出 -1.$% 这种乱码
   问题 2：以 EOF 结束时没有 #，punctuation-1 会变成负数

double alphacent = ((double)(dalpha + xalpha) / (totalnum - 1)) * 100;
double digitscent = ((double)digits / (totalnum - 1)) * 100;
double blankcent = ((double)blank / (totalnum - 1)) * 100;
double punctuationcent = ((double)(punctuation - 1) / (totalnum - 1)) * 100;
double otherscent = ((double)others / (totalnum - 1)) * 100;

printf("总字符数: %d 个\n",totalnum - 1);
printf("字母: %d 个(%.1f%%)\n",dalpha + xalpha,alphacent);
printf("数字: %d 个(%.1f%%)\n",digits,digitscent);
printf("空白: %d 个(%.1f%%)\n",blank,blankcent);
printf("标点: %d 个(%.1f%%)\n",punctuation - 1,punctuationcent);
printf("其他: %d 个(%.1f%%)\n",others,otherscent);

   ========== 你原来的写法结束 ========== */
#endif

/* ✅ 改成 */
double alphacent = 0.0, digitscent = 0.0, blankcent = 0.0;
double punctuationcent = 0.0, otherscent = 0.0;

if (totalnum > 0)
{
    alphacent       = (double)(dalpha + xalpha) / totalnum * 100;
    digitscent      = (double)digits            / totalnum * 100;
    blankcent       = (double)blank             / totalnum * 100;
    punctuationcent = (double)punctuation       / totalnum * 100;
    otherscent      = (double)others            / totalnum * 100;
}

printf("\n总字符数: %d 个\n", totalnum);
printf("字母: %d 个(%.1f%%)\n", dalpha + xalpha, alphacent);
printf("数字: %d 个(%.1f%%)\n", digits, digitscent);
printf("空白: %d 个(%.1f%%)\n", blank, blankcent);
printf("标点: %d 个(%.1f%%)\n", punctuation, punctuationcent);
printf("其他: %d 个(%.1f%%)\n", others, otherscent);
printf("\n");
printf("大写字母: %d 个    小写字母: %d 个\n", dalpha, xalpha);
printf("元音字母: %d 个\n", yalpha);

/* ────────────────────────────────────────────────────────────────────────────
   ⑤ 出现最多的可打印字符 —— 换成"正序扫描计数数组"
   ──────────────────────────────────────────────────────────────────────────── */
#if 0
/* ========== 你原来的写法开始 ==========
   问题：1) 输出了所有并列的字符，不是"ASCII 最小的那一个"
         2) 没有说明规则（验收标准④明确要求）
         3) m 可能越界读内存

printf("出现最多的字符:");
int m = 0;
while(ch1num[m] == ch1num[0])
{
    printf("'%c'(%d次)",ch1[m],ch1num[m]);
    printf("   ");                 // 隔开
    if((m + 1) % 4 == 0)           // 每四个换行
    {
        printf("\n");
        printf("              ");
    }
    m++;
}
printf("\n");

   ========== 你原来的写法结束 ========== */
#endif

/* ✅ 改成：从 33 正序扫到 126，用 > 而不是 >=
      为什么这样就实现了"并列取 ASCII 最小"？
        先到的（ASCII 小的）已经占住 maxChar；
        后面的因为用 >，"等于"不算 → 不会覆盖它。
      一个额外判断都不用加。                                        */
int maxCount = 0;
int maxChar  = 0;
for (int c = 33; c <= 126; c++)
{
    if (count[c] > maxCount)
    {
        maxCount = count[c];
        maxChar  = c;
    }
}

if (maxCount == 0)
{
    printf("出现最多的字符：没有可打印字符\n");
}
else
{
    printf("出现最多的字符：'%c'（%d 次）\n", maxChar, maxCount);
    printf("（规则：只统计 ASCII 33~126 的可打印字符，空格与结束符 # 不计入；\n");
    printf("　　　　若有多个字符并列最多，取 ASCII 码最小的那个）\n");
}

/* ────────────────────────────────────────────────────────────────────────────
   ⑦ 柱状图：cent[] 排序 + 标签
   ──────────────────────────────────────────────────────────────────────────── */
#if 0
/* ========== 你原来的 cent[] 排序开始 ==========
   你已经把 cent[j] = cent[k] 改成 cent[j] = maxcent，交换是对的、排序也对了。
   但它只是"把值排好"，名字没跟着走 —— 所以下面打印时只能靠
   "值相等"反推名字。一旦两个分类百分比相同（如空白 11.8% 和标点 11.8%），
   第 4 行就会被印成"空白"。
   所以这里换成"值和下标一起排"的标准选择排序。

double cent[5] = {alphacent,digitscent,blankcent,punctuationcent,otherscent};
double maxcent = 0;
for(int j = 0;j < 5;j++)
{
    maxcent = cent[j];
    for(int k = j;k < 5;k++)
    {
        if(maxcent <= cent[k])
        {
            maxcent = cent[k];
            cent[k] = cent[j];
            cent[j] = maxcent;
        }
    }
}

   ========== 你原来的 cent[] 排序结束 ========== */
#endif

/* ✅ 改成：选择排序，cent 和 idx 一起换 */
const char *label[5] = {"字母", "数字", "空白", "标点", "其他"};
double cent[5] = {alphacent, digitscent, blankcent, punctuationcent, otherscent};
int    idx[5]  = {0, 1, 2, 3, 4};      /* ★ 记住每一项原来是谁 */

for (int j = 0; j < 5; j++)
{
    int m = j;                          /* 假设 j 是最大的 */
    for (int k = j + 1; k < 5; k++)     /* ★ 从 j+1 开始，不和自己比 */
    {
        if (cent[k] > cent[m])
        {
            m = k;                      /* 找真正最大的下标 */
        }
    }
    if (m != j)                         /* 一次交换到位 */
    {
        double t = cent[j];  cent[j] = cent[m];  cent[m] = t;
        int    u = idx[j];   idx[j]  = idx[m];   idx[m]  = u;   /* ★ 名字一起换 */
    }
}

printf("\n占比柱状图（每 2%% 一格）：\n");

#if 0
/* ========== 你原来的柱状图开始（整段删除）==========
   两处问题：
     · 标签用 cent[j] == alphacent 这种"浮点相等"反推 → 并列时认错行
     · 补空格用 (int)(cent[0]/2) - (int)(xxxcent/2) —— 你已经加了 (int)，
       对齐是对的，保留这个思路，但换成"补到固定宽度"更稳

for(int j = 0;j < 5;j++)
{
    if(cent[j] == alphacent)
    {
        printf("字母  |");
        for(int k = 1;k <= (cent[j] / 2);k++) { printf("#"); }
        for(int k = 1;k <= (int)((cent[0]) / 2) - (int)((alphacent) / 2);k++) { printf(" "); }
        printf("  %.1f%%",cent[j]);
        printf("\n");
    }
    else if(cent[j] == digitscent)
    {
        printf("数字  |");
        for(int k = 1;k <= (cent[j] / 2);k++) { printf("#"); }
        for(int k = 1;k <= (int)((cent[0]) / 2) - (int)((digitscent) / 2);k++) { printf(" "); }
        printf("  %.1f%%",cent[j]);
        printf("\n");
    }
    else if(cent[j] == blankcent)
    {
        printf("空白  |");
        for(int k = 1;k <= (cent[j] / 2);k++) { printf("#"); }
        for(int k = 1;k <= (int)((cent[0]) / 2) - (int)((blankcent) / 2);k++) { printf(" "); }
        printf("  %.1f%%",cent[j]);
        printf("\n");
    }
    else if(cent[j] == punctuationcent)
    {
        printf("标点  |");
        for(int k = 1;k <= (cent[j] / 2);k++) { printf("#"); }
        for(int k = 1;k <= (int)((cent[0]) / 2) - (int)((punctuationcent) / 2);k++) { printf(" "); }
        printf("  %.1f%%",cent[j]);
        printf("\n");
    }
    else
    {
        printf("其他  |");
        for(int k = 1;k <= (cent[j] / 2);k++) { printf("#"); }
        for(int k = 1;k <= (int)((cent[0]) / 2) - (int)((otherscent) / 2);k++) { printf(" "); }
        printf("  %.1f%%",cent[j]);
        printf("\n");
    }
}

   ========== 你原来的柱状图结束 ========== */
#endif

/* ✅ 改成：先用 idx 取名字，条长算一次、再补到固定宽度 maxLen */
int maxLen = (int)(cent[0] / 2);        /* 最长条的格数 */

for (int j = 0; j < 5; j++)
{
    int barLen = (int)(cent[j] / 2);    /* 本行实际画几格 */

    printf("%s  |", label[idx[j]]);     /* ★ 直接用名字，不做浮点比较 */

    for (int k = 0; k < barLen;  k++) printf("#");
    for (int k = barLen; k < maxLen; k++) printf(" ");   /* ★ 补到固定宽度 */

    printf("  %.1f%%\n", cent[j]);
}

return 0;
}
