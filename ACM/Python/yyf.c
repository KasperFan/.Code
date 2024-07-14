/*
 * @Author: KasperFan && fanwlx@foxmail.com
 * @Date: 2023-11-28 23:51:15
 * @LastEditTime: 2023-12-02 12:56:12
 * @FilePath: /Python/yyf.c
 * @describes: This file is created for learning Python to deal OJ problems.
 * Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
 */
#include <stdio.h>
#include <stdlib.h>


int ans = 2500;
int n, m;
int sum;
char a[55][55];
int a1[55];
int a2[55];
int a3[55];
int main()
{
    freopen("./P3392.in", "r", stdin);
    freopen("./P3392.out", "w+", stdout);
    scanf("%d %d\n", &n, &m);
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (j != m)
            {
                scanf("%c", &a[i][j]);
            }
            else scanf("%c\n", &a[i][j]);
            // getchar();
            if (a[i][j] == 'W')
            {
                a1[i]++;
            }
            else if (a[i][j] == 'B')
            {
                a2[i]++;
            }
            else if (a[i][j] == 'R')
            {
                a3[i]++;
            }
        }
    }
    for (int w = 1; w <= n - 2; w++)
    {
        for (int b = 1; b <= n - w - 1; b++)
        {
            sum = 0;
            for (int i = 1; i <= w; i++)
            {
                sum += m - a1[i];
            }
            for (int i = w + 1; i <= w + b; i++)
            {
                sum += m - a2[i];
            }
            for (int i = w + b + 1; i <= n; i++)
            {
                sum += m - a3[i];
            }
            if (sum < ans)
            {
                ans = sum;
            }
        }
    }
    printf("%d", ans);
    return 0;
}