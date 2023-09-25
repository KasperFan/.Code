/*
 * @Author: KasperFan && fanwlx@foxmail.com
 * @Date: 2023-06-12 20:52:09
 * @LastEditTime: 2023-06-13 15:53:06
 * @FilePath: /Data_Structure/课程设计/func.c
 * @describes: This file is created for learning Code.
 * Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved.
 */
// #include <stdio.h>
// #include <stdlib.h>
// int main(int argc, char const *argv[])
// {
//     char ch;
//     scanf(" %c", &ch);
//     printf("2311");
//     return 0;
// }

// // 包含unistd.h头文件
// #include <unistd.h>
// // 包含stdio.h头文件，用于输出
// #include <stdio.h>
// // 包含termios.h头文件，用于控制终端
// #include <termios.h>

// int main()
// {
//     // 声明两个termios结构体，用于存储终端属性
//     struct termios term, old_term;
//     // 使用tcgetattr()函数获取当前的终端属性，并存储在term和old_term中
//     tcgetattr(STDIN_FILENO, &term);
//     tcgetattr(STDIN_FILENO, &old_term);
//     // 修改term的属性，关闭回显和规范模式
//     term.c_lflag &= ~(ECHO | ICANON);
//     // 使用tcsetattr()函数设置新的终端属性
//     tcsetattr(STDIN_FILENO, TCSANOW, &term);
//     // 打印一条信息
//     printf("The program will pause.\n");
//     // 调用pause()函数，使进程暂停，直到收到一个信号
//     pause();
//     // 打印一条信息
//     printf("The program resumes.\n");
//     // 使用tcsetattr()函数恢复原始的终端属性
//     tcsetattr(STDIN_FILENO, TCSANOW, &old_term);
//     return 0;
// }


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    FILE *fp1,*fp2;
    char *name = "test.txt";
    fp1 = fopen("test.min", "w");
    fprintf(fp1, "halskdbf\n");
    fclose(fp1);
    fp2 = fopen("test.min", "r");
    if (fp2 == NULL)
    {
        perror("fopen");
        return 1;
    }

    return 0;
}
