/*
 * @Author: KasperFan && fanwlx@foxmail.com
 * @Date: 2023-11-28 23:51:15
 * @LastEditTime: 2024-03-08 14:24:48
 * @FilePath: /C/Data_Structure/第1章_概论/1.1_引子/tempCodeRunnerFile.c
 * @describes: This file is created for learning Code.
 * Copyright (c) 2024 by KasperFan in WFU, All Rights Reserved.
 */
// void PrintN(int N)
// { /* 打印从1到N的全部正整数 */
//     if (N > 0)
//     {
//         PrintN(N - 1);
//         printf("%d\n", N);
//     }
// }

#include <stdio.h>
#include <string.h>
#include <time.h>
// #include <windows.h>
#include <unistd.h>

int main() {
    clock_t start = clock();
    char str[] = "Hello,World!";
    for (int i = 0; str[i]; i++)
    {
        printf("%c", str[i]);
        // fflush(stdout);
        usleep(70000);
    }
    printf("\n");
    return 0;
}
