#include <stdio.h>
#ifdef _WIN32
#include <conio.h>
#endif
#ifdef _WIN32
// 定义一个函数，用于实现密码隐式输入
int input_password(char password[])
{
    // 定义一个整数变量，用于记录密码长度
    int i = 0;
    // 定义一个字符变量，用于实现密码隐式输入
    char c;
    // 使用while循环，不断读取用户输入的字符
    while (1)
    {
        // 使用_getch()函数输入，字符不会显示在屏幕上
        c = _getch();
        // 如果遇到回车，表明密码输入结束
        if (c == '\r')
        {
            break; // 跳出while循环
        }
        else if (c == '\b')
        {                    // 如果遇到退格，需要删除前一个星号
            printf("\b \b"); // 退格，打一个空格，再退格，实质上是用空格覆盖掉星号
            --i;             // 密码长度减一
        }
        else
        {
            password[i++] = c; // 将字符放入数组
            printf("*");       // 在屏幕上打印一个星号
        }
    }
    // 返回密码长度
    return i;
}
#endif
#include <stdio.h>
#ifdef __APPLE__
#include <locale.h>
#include <ncurses.h>
#endif
#ifdef __APPLE__
// 定义一个函数，用于实现密码隐式输入
int input_password(char password[])
{
    int late = 30;
    // 定义一个整数变量，用于记录密码长度
    int i = 0;
    // 定义一个字符变量，用于实现密码隐式输入
    char c;
    // 初始化 curses 库
    initscr();
    // 设置不回显输入的字符
    noecho();
    // 设置非阻塞模式
    // nodelay(stdscr, TRUE); // 添加这一行
    printw("         请输入数据库密码:");
    // 使用while循环，不断读取用户输入的字符
    while (late--)
    {
        // 使用 getch() 函数输入，字符不会显示在屏幕上
        c = getch();
        // 如果遇到回车，表明密码输入结束
        if (c == '\n')
        {
            break; // 跳出while循环
        }
        else if (c == '\b' || c == 127)
        {                    // 如果遇到退格或删除键，需要删除前一个星号
            printw("\b \b"); // 退格，打一个空格，再退格，实质上是用空格覆盖掉星号
            refresh();       // 刷新屏幕，添加这一行
            --i;             // 密码长度减一
        }
        else
        {
            password[i++] = c; // 将字符放入数组
            printw("*");       // 在屏幕上打印一个星号
            refresh();         // 刷新屏幕，添加这一行
        }
    }
    // 结束 curses 库
    endwin();
    // 返回密码长度
    return i;
}
#endif

int main()
{
    setlocale(LC_ALL, ""); // 添加这一行
    // 定义一个字符数组，用于存储密码
    char password[18] = {0};
    // 定义一个整数变量，用于存储密码长度
    int len;
    // 提示用户输入密码
    printf("请输入密码：");
    // 调用input_password函数，将用户输入的密码存储在password数组中，并获取密码长度
    len = input_password(password);
    // 输出换行符
    printf("\n");
    // 输出用户输入的密码和长度
    printf("你输入的密码是：%s\n", password);
    printf("密码的长度是：%d\n", len);
    return 0;
}
