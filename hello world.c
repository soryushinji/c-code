/* =====================================================================
   题 02  双指针三招（相向 / 快慢 / 滑动窗口）—— 我的解答
   ---------------------------------------------------------------------
   约束遵守情况：
     1) 主数组 / 字符串的遍历全部用指针，没有任何 a[i] / s[i]；
     2) 计数数组用下标 cnt[c - 97]（这是"辅助数组"，不参与主遍历）；
     3) 两数之和固定输出下标 0 和 5（从左端逼近，第一个成立的组合）；
     4) abba 那组必须输出 2（窗口用 while 连续收缩）。
   ===================================================================== */
#include <stdio.h>

/* ---------- 招式一：相向双指针 —— 有序数组两数之和 ---------- */
/* 关键帧（target=10，数组 1 3 4 6 8 9）：
   l→1        r→9   和 10 == target，第一步就命中 → 下标 0 和 5
   （若和 < target：和太小，l 右移让和变大；和 > target：r 左移让和变小）
   遍历只用指针，下标靠 p - a 算出来。 */
static void two_sum(const int *a, int n, int target)
{
    const int *l = a;              /* 左指针指向首元素 */
    const int *r = a + n - 1;      /* 右指针指向末元素 */

    while (l < r) {
        int sum = *l + *r;         /* 只看两个指针当前指的值 */
        if (sum == target) {
            printf("两数之和: 下标 %d 和 %d（%d + %d）\n",
                   (int)(l - a), (int)(r - a), *l, *r);
            return;
        }
        if (sum < target) l++;     /* 和太小 → 左指针右移 */
        else              r--;     /* 和太大 → 右指针左移 */
    }
    printf("两数之和: -1 -1\n");   /* 找不到 */
}

/* ---------- 招式二：快慢双指针 —— 原地删除所有等于 x 的元素 ---------- */
/* 关键帧（数组 1 3 1 4 1 5，x=1）：
   slow 只在"遇到不等于 x 的元素"时才写并前进；fast 每个元素都前进一次。
   最后 slow - a 就是新长度，前 slow-a 个位置就是删除后的结果。 */
static int remove_value(int *a, int n, int x)
{
    int *slow = a;                 /* 写指针 */
    int *fast = a;                 /* 读指针 */

    while (fast < a + n) {
        if (*fast != x) {          /* 不等于 x 才保留 */
            *slow = *fast;         /* 写指针只在这里移动 */
            slow++;
        }
        fast++;                    /* 读指针永远前进 */
    }
    return (int)(slow - a);        /* 新长度 */
}

/* ---------- 招式三：滑动窗口 —— 最长无重复字符子串 ---------- */
/* 关键帧（abba）：
   r 走到第二个 b 时，cnt['b'-97] == 2（重复）→ 左指针连续收缩：
     先跳过第一个 b（cnt b→1，仍重复），再跳过 a（cnt a→0）→ 窗口变成 "b"
   所以收缩必须写 while，不能写 if（写 if 只缩一次，abba 会算成 3）。
   计数数组用下标 cnt[c - 97]：它只是 26 个计数桶，不涉及"主数组遍历"，
   用下标更直观且没有指针别名问题，所以这里放宽。 */
static int longest_unique(const char *s)
{
    int cnt[26] = {0};             /* 窗口内每个字母出现次数 */
    const char *l = s;             /* 窗口左端 */
    const char *r = s;             /* 窗口右端 */
    int best = 0;

    while (*r) {                   /* 右指针扩展窗口 */
        int idx = *r - 'a';
        cnt[idx]++;                /* 新字符进窗 */
        while (cnt[idx] > 1) {     /* 出现重复 → 连续收缩（while！） */
            cnt[*l - 'a']--;       /* 移出窗口的字符计数减 1 */
            l++;
        }
        if ((int)(r - l + 1) > best) best = (int)(r - l + 1);
        r++;
    }
    return best;
}

/* ---------- 拓展（不计入 diff）：三数之和 ---------- */
/* 思路：先用指针 k 固定第一个数，剩下两个数就变成"两数之和 = target - *k"，
   直接复用招式一的逼近逻辑。O(n^2)。 */
static int three_sum_exists(const int *a, int n, int target)
{
    const int *k = a;                       /* 固定第一个数，用指针走 */
    for (; k < a + n - 2; k++) {
        const int *l = k + 1, *r = a + n - 1;
        int need = target - *k;
        while (l < r) {
            int sum = *l + *r;
            if (sum == need) return 1;
            if (sum < need) l++; else r--;
        }
    }
    return 0;
}

int main(void)
{
    int a1[6] = {1, 3, 4, 6, 8, 9};
    int a2[6] = {1, 3, 1, 4, 1, 5};
    int target = 10;
    int x = 1;
    int newlen;

    printf("数组: 1 3 4 6 8 9，target=%d\n", target);
    two_sum(a1, 6, target);
    putchar('\n');

    printf("数组: 1 3 1 4 1 5，x=%d\n", x);
    newlen = remove_value(a2, 6, x);
    printf("删除后:");
    { const int *p = a2; int k;
      for (k = 0; k < newlen; k++) printf(" %d", *p++); }
    printf("，新长度 %d\n", newlen);
    putchar('\n');

    printf("字符串: abcabcbb -> 最长无重复子串 %d\n", longest_unique("abcabcbb"));
    printf("字符串: abba -> 最长无重复子串 %d（窗口收缩两次）\n", longest_unique("abba"));
    printf("字符串: bbbbb -> 最长无重复子串 %d\n", longest_unique("bbbbb"));

    /* 拓展自检（不打印，避免破坏 diff）：1+6+8=15，存在三数和为 15 */
    if (three_sum_exists(a1, 6, 15) != 1) return 1;
    return 0;
}