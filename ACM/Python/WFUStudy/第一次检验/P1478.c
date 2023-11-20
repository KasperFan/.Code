/*
 * @Author: KasperFan && fanwlx@foxmail.com
 * @Date: 2023-10-23 08:03:54
 * @LastEditTime: 2023-10-23 23:21:36
 * @FilePath: /Python/WFUStudy/第一次检验/P1478.c
 * @describes: This file is created for learning Python to deal OJ problems.
 * Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved.
 */
#include <stdio.h>

int n, s, a, b, cnt;
int x[5050], y[5050], indexs[5050];

int main()
{
    scanf("%d %d", &n, &s);
    scanf("%d %d", &a, &b);
    for (int i = 1; i <= n; i++)
    {
        indexs[i] = i;
        scanf("%d %d", &x[i], &y[i]);
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n - i; j++)
            if (y[indexs[j]] > y[indexs[j + 1]])
            {
                int temp = indexs[j];
                indexs[j] = indexs[j + 1];
                indexs[j + 1] = temp;
            }
    for (int i = 1; i <= n; i++)
    {
        if (x[indexs[i]] <= a + b && y[indexs[i]] <= s)
        {
            cnt++;
            s -= y[indexs[i]];
        }
        else if (y[indexs[i]] > s)
            break;
    }
    printf("%d\n", cnt);
    return 0;
}
