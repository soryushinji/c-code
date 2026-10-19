/* ⚠ 危险示范：头文件里定义 static 函数 + static 变量 */
static int s_counter = 0;

static int bump(void)
{
    return ++s_counter;
}
