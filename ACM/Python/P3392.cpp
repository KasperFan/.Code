/*
 * @Author: KasperFan && fanwlx@foxmail.com
 * @Date: 2023-11-28 11:05:22
 * @LastEditTime: 2023-11-28 17:46:56
 * @FilePath: /Python/P3392.cpp
 * @describes: This file is created for learning Python to deal OJ problems.
 * Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved.
 */
#include <stdio.h>

int n, m;
// ans;
int min = 100000;
char arr[60][60];

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
                scanf("%c", &arr[i][j]);
                continue;
            }
            scanf("%c\n", &arr[i][j]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%s\n", &arr[i][1]);
    }

    for (int i = 1; i <= n - 2; i++) // 白蓝边界（前面全白，后面蓝红各一）
    {
        for (int j = i + 1; j <= n - 1; j++) // 蓝红边界（红色只有一行）
        {
            int ans = 0;

            for (int k = 1; k <= i; k++) // 白色
            {
                for (int l = 1; l <= m; l++)
                {
                    if (arr[k][l] != 'W')
                    {
                        ans++;
                    }
                }
            }

            for (int k = i + 1; k <= j; k++) // 蓝色
            {
                for (int l = 1; l <= m; l++)
                {
                    if (arr[k][l] != 'B')
                    {
                        ans++;
                    }
                }
            }

            for (int k = j + 1; k <= n; k++) // 红色
            {
                for (int l = 1; l <= m; l++)
                {
                    if (arr[k][l] != 'R')
                    {
                        ans++;
                    }
                }
            }

            min = min < ans ? min : ans;
        }
    }
    printf("%d\n", min);
    return 0;
}