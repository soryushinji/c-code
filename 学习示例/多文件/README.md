# C 语言：多个文件中函数的声明与定义

对应《C Primer Plus》**第 9 章 9.4《编译多源代码文件的程序》**

---

## 一、三个角色

| 文件 | 放什么 | 类比 |
|---|---|---|
| **`xxx.h`** | 函数的**声明**（原型）+ 宏 + extern 变量声明 | 菜单 / 说明书 |
| **`xxx.c`** | 函数的**定义**（函数体）+ 变量定义 | 厨房 / 实现 |
| **`main.c`** | `#include "xxx.h"` 然后调用 | 点菜的顾客 |

---

## 二、正确示例（本目录的 calc.h / calc.c / main.c）

### calc.h —— 只放声明

```c
#ifndef CALC_H              /* 头文件保护：防止重复展开 */
#define CALC_H

int add(int a, int b);      /* 只有分号，没有函数体 */
int sub(int a, int b);

extern int g_count;         /* 变量的【声明】：加 extern */

#define MAX_A 10000         /* 宏放头文件里，谁包含谁能用 */

#endif
```

### calc.c —— 放定义

```c
#include "calc.h"           /* 包含自己的头文件，保证声明定义一致 */

int g_count = 0;            /* 变量的【定义】：不带 extern，有初值 */

int add(int a, int b)       /* 带函数体 */
{
    g_count++;
    return a + b;
}
```

### main.c —— 调用

```c
#include <stdio.h>
#include "calc.h"           /* 双引号：先找当前目录 */

int main(void)
{
    printf("%d\n", add(1, 2));
    printf("%d\n", g_count);
    return 0;
}
```

---

## 三、怎么编译

### 最常用：一次编译全部 .c

```bash
gcc main.c calc.c -o app
```

### 分步编译（工程大了才需要）

```bash
gcc -c calc.c -o calc.o      # 只编译，不链接
gcc -c main.c -o main.o
gcc main.o calc.o -o app     # 链接
```

好处：改一个 .c 只重编那个 .o，不用全编。

---

## 四、四种典型错误（本目录都有可复现的例子）

### 错误 1：把【定义】写进头文件 ✗

```c
/* bad.h */
int add(int a, int b) { return a + b; }   /* ✗ 带函数体！ */
```

被 `a.c` 和 `b.c` 同时包含 →

```
multiple definition of `add'
a.c:(.text+0x0): first defined here
collect2.exe: error: ld returned 1 exit status
```

**这是【链接】错误，不是编译错误** ✓ —— 每个 .c 编译都成功，链接时发现 `add` 有两份 ✗

**规则**：头文件里**只能有声明**（末尾分号），**不能有函数体** ✗

---

### 错误 2：忘了 #include 头文件 ✗

```c
/* main.c */
int main(void) { printf("%d\n", add(1, 2)); return 0; }   /* 没包含 calc.h */
```

GCC 8.1 只给**警告**：

```
warning: implicit declaration of function 'add' [-Wimplicit-function-declaration]
```

**而且运行居然输出正确结果 3** ⚠️ —— 这才是最坑的地方 ✗

**为什么危险**：
- 隐式声明默认函数返回 `int`
- 如果实际函数返回 `double` / 指针 / 结构体 → **返回值得垃圾** ✗
- 参数个数、类型也完全不检查 ✗

**C99 起这是"违反约束"** —— GCC 14 / Clang 16+ **直接报错** ✗
**建议**：编译时加 `-Werror=implicit-function-declaration` 让它变成错误 ✓

---

### 错误 3：只声明、没定义 ✗

```c
/* calc.h */
int sub(int a, int b);      /* 声明了 */

/* calc.c */
/* ✗ 忘了实现 sub */
```

```
undefined reference to `sub'
collect2.exe: error: ld returned 1 exit status
```

**同样只在【链接】阶段报错** ✓ —— 编译能过 ✓

**判断口诀**：
| 报错 | 阶段 | 意思 |
|---|---|---|
| `implicit declaration` | 编译 | 缺**声明**（缺 include）|
| `multiple definition` | 链接 | 有**多份定义**（定义写进头文件）|
| `undefined reference` | 链接 | 缺**定义**（声明了没实现）|

---

### 错误 4：头文件里放 `static` ⚠️

```c
/* shared.h */
static int s_counter = 0;
static int bump(void) { return ++s_counter; }
```

**不会报错** ✗ —— 但**每个 .c 各拿一份独立副本** ✗：

```
a.c 看到 s_counter = 0
b.c 看到 s_counter = 0     ← 不是 1！各是各的
a.c 看到 s_counter = 1
```

**原因**：`static` = **内部链接**（internal linkage）✓ —— 只在本编译单元可见 ✓
头文件被多个 .c 包含 → 每个 .c 都有自己的那份 ✓

**结论**：头文件里**不要**定义 `static` 变量 ✗
（`static` 函数可以放头文件，但每个 .c 都会有一份副本，浪费空间 ✓）

---

## 五、`extern` 关键字：声明 vs 定义变量

| 写法 | 是什么 | 放哪 |
|---|---|---|
| `int g_count;` | **定义**（分配内存）| 一个 .c 里 |
| `int g_count = 0;` | **定义**（带初值）| 一个 .c 里 |
| `extern int g_count;` | **声明**（不分配内存）| 头文件里 / 想用的 .c 里 |

**规则**：**一个变量只能定义一次** ✓，但可以声明无数次 ✓

---

## 六、头文件保护（include guard）

```c
#ifndef CALC_H
#define CALC_H

/* 内容 */

#endif
```

**为什么需要**：同一个头文件可能被**间接包含多次** ✗
（`a.h` 包含 `c.h`，`b.h` 也包含 `c.h`，`main.c` 同时包含 a.h 和 b.h → `c.h` 被展开两次 ✗ → 里面的定义重复 ✗）

保护后：第二次展开时 `CALC_H` 已定义 → 整段跳过 ✓

**现代写法**（GCC/Clang 支持，但不是标准 C）：
```c
#pragma once
```

---

## 七、双引号 vs 尖括号

| 写法 | 查找顺序 |
|---|---|
| `#include "calc.h"` | **先当前目录** → 再系统目录 ✓ 自己写的用这个 |
| `#include <stdio.h>` | **只找系统目录** ✓ 标准库用这个 |

---

## 八、把这个用到你的第 10 题上

你的 `new day.c` 现在 **3765 行**，全在 `main()` 里 ✗

**可以这样拆**（第 9 章最好的练习 ✓）：

```
数字分析工具箱/
├── tools.h          ← 声明 9 个函数
├── io.c             ← input_data() / show_all() / clear_input()
├── stat.c           ← show_stats() / sort_asc() / find_value()
├── analyze.c        ← dedup() / histogram() / reverse()
└── main.c           ← 只有菜单循环
```

每个 `.c` 只干一类事 ✓ —— 这才是工程化的写法 ✓

---

## 九、编译命令速查

```bash
# 一个 .c
gcc main.c -o app

# 多个 .c
gcc main.c calc.c -o app

# 分步
gcc -c calc.c -o calc.o
gcc -c main.c -o main.o
gcc main.o calc.o -o app

# 严格检查（推荐）
gcc -Wall -Wextra -std=c11 -Werror=implicit-function-declaration main.c calc.c -o app

# 中文注释不乱码（Windows）
gcc -finput-charset=UTF-8 -fexec-charset=GBK main.c calc.c -o app
```