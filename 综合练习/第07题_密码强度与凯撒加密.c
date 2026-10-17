/* 第07题_密码强度与凯撒加密
   自测册第 7 题
   来源：D:\code\.vscode\new day.c（原为 main() 内的一段，提取时补了头文件和 main 外壳）
*/

#include <ctype.h>
#include <stdio.h>

int main(void)
{
int ch;
int pwnum = 0;//记录检查密码次数
int wpwnum = 0;//弱密码次数
int mpwnum = 0;//中密码次数
int spwnum = 0;//强密码次数
int pin = 0;//针,如果输入空格+换行的形式,负责触发提示
printf("请输入密码（直接回车结束）:\n");
while(ch != EOF )//最初的大循环
{
if(pin != 0 || pwnum != 0)//第二次循环之后输出
{
    printf("请输入密码:\n");
}
char password[100];//记录密码的数组
char alpha[100];//记录密码中的字母
int length = 0;//记录密码长度
int dalpha = 0;//记录大写字母长度
int xalpha = 0;//记录小写字母长度
int digits = 0;//记录数字长度
int punct = 0;//记录特殊符号长度
int strength = 5;//记录密码强度
int button = 0;//记录密码中间是否含有空格
int i = 0;//作为存放密码的char数组的下标
//开始输入密码
ch = getchar();
//直接回车结束
if(ch == '\n')
{
    break;//跳出循环
}
//允许开头输出空格
while(ch == ' ' || ch == '\t')
{
    ch = getchar();
}
//开头输入空格+换行,报错
if(ch == '\n')
{
    printf("错误,请输入正确格式的密码！\n");
    pin++;
    continue;
    //不需要清理缓冲区
}
//开始输入密码
while(ch != EOF)//密码输入
{
if(ch == ' ' || ch == '\t')//输入字符后再输入空格
{
    button++;//表明在密码后输入了空格
    //读空格之后下一个输入的是什么
    //如果是空格,在这个while里循环,直到输入其他字符
    //如果输入换行enter,跳出循环，说明密码输入完成
    //输入字母数字标号之类的,报错
}
if(isupper(ch) && button == 0)//是大写字母
{
    dalpha++;
    password[i] = ch;
    alpha[i] = ch;
}
else if(islower(ch) && button == 0)//小写字母
{
    xalpha++;
    password[i] = ch;
    alpha[i] = ch;
}
else if(isdigit(ch) && button == 0)//数字
{
    digits++;
    password[i] = ch;
}
else if(ispunct(ch) && ch != '\t' && ch != '\n' && button == 0)//除空格字母数字外的标号,也不包含换行
{
    punct++;
    password[i] = ch;
}
ch = getchar();
//如果在输入密码空格后再输入密码——即密码中间插入空格,直接跳出
if(button != 0 && ch != ' ' && ch != '\t' && ch != '\n')
{
    //清空缓冲区的字符
    while(ch != '\n' && ch != EOF) ch = getchar();
    break;//跳出这个小循环
}
if(ch == '\n')//输出换行符
{
    //进入这个的条件:1: abc(正常输入密码) 2:abc   (输入密码后输入空格+换行)
    //将button清零,防止影响判断
    button = 0;
    break;//跳出这个小循环
}
if(button == 0 && ch != ' ' && ch != '\t')//记录密码的长度,不记录空格(密码后输入第一个空格时button=0)
{
i++;//每循环一次i + 1
}
}//小循环结束
if(button != 0)//说明是密码+空格+密码的错误形式
{
    printf("错误,密码之间不能带空格,请输入正确格式的密码!\n");
    pin++;
    continue;//重新循环
}
//检查看密码是否存入数组中
// printf("密码是:");
// for(int j = 0;j <= i;j++)
// {
//     printf("%c",password[j]);
// }
// printf("\n");
//密码输入完毕,接下来该判断了
length = i + 1;//确定密码长度
//判断密码情况
if(length < 8)
{
    printf("长度不足 8 位; ");
    strength--;
}
if(dalpha == 0)
{
    printf("缺少大写字母; ");
    strength--;
}
if(xalpha == 0)
{
    printf("缺少小写字母; ");
    strength--;
}
if(digits == 0)
{
    printf("缺少数字; ");
    strength--;
}
if(punct == 0)
{
    printf("缺少特殊符号; ");
    strength--;
}
if(strength == 5)
{
    printf("- 长度 ≥ 8   - 大写字母   - 小写字母   - 数字   - 特殊符号");
}
printf("\n");
//判断强度
switch(strength)
{
    case 1:
    case 2:
        printf("强度:弱 (满足 %d / %d 项)",strength,5);
        wpwnum++;
        break;
    case 3:
    case 4:
        printf("强度:中 (满足 %d / %d 项)",strength,5);
        mpwnum++;
        break;
    case 5:
        printf("强度:强 (满足 %d / %d 项)",strength,5);
        spwnum++;
        break;
    default:
        printf("强度:弱 (满足 %d / %d 项)", strength, 5);
        wpwnum++;
        break;
}
printf("\n");
//加密
for(int j = 0;j <= i;j++)
{
    if(isalpha(password[j]))//是字母
    {
        if(password[j] == 'x' || password[j] == 'y' || password[j] == 'z' || password[j] == 'X' || password[j] == 'Y' || password[j] == 'Z')//是xyz的特殊情况
        {
            alpha[j] -= 23;
        }
        else
        {
        alpha[j] += 3;//将alpha数组中的对应字母转换
        }
    }
}
//打印加密后的密码
printf("加密后: ");
for(int j = 0;j <= i;j++)
{
    if(isalpha(password[j]))//当读到字母时
    {
        printf("%c",alpha[j]);//输出的是alpha数组的
    }
    else
    {
        printf("%c",password[j]);
    }
}
printf("\n");
pwnum++;//记录密码检查次数
}//大循环结束
printf("共检查 %d 个密码:强 %d 个，中 %d 个，弱 %d 个。再见~~",pwnum,spwnum,mpwnum,wpwnum);


return 0;
}
