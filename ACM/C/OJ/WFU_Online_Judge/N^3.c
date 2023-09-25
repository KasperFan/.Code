/*
 * @Author: KasperFan && fanwlx@foxmail.com
 * @Date: 2023-09-23 20:57:58
 * @LastEditTime: 2023-09-23 21:10:55
 * @FilePath: /ACM/C/OJ/WFU_Online_Judge/N^3.c
 * @describes: This file is created for learning Code.
 * Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved.
 */
#include <stdio.h>

int tow[10], N, ans;

int main(int argc, char const *argv[])
{
    for (int i = 0; i < 10; i++) tow[i] = i * i * i;
    scanf("%d", &N);
    N = N * N * N;
    while (N > 0) { ans += tow[N % 10]; N /= 10; }
    printf("%d\n", ans);
    return 0;
}
