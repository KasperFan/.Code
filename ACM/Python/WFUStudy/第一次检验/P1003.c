/*
 * @Author: KasperFan && fanwlx@foxmail.com
 * @Date: 2023-10-23 08:57:51
 * @LastEditTime: 2023-10-23 09:17:47
 * @FilePath: /Python/WFUStudy/第一次检验/P1003.c
 * @describes: This file is created for learning Python to deal OJ problems.
 * Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved.
 */
#include <stdio.h>

int n, ans = -1, x, y;
int a[(int)1e4 + 10], b[(int)1e4 + 10], g[(int)1e4 + 10], k[(int)1e4 + 10];

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d %d %d %d", &a[i], &b[i], &g[i], &k[i]);
    scanf("%d %d", &x, &y);
    for (int i = 1; i <= n; i++)
        if ((x >= a[i] && x <= a[i] + g[i] - 1) && (y >= b[i] && y <= b[i] + k[i] - 1))
            ans = i;
    printf("%d\n", ans);
    return 0;
}

