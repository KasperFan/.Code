/*
 * @Author: KasperFan && fanwlx@foxmail.com
 * @Date: 2023-05-06 12:49:26
 * @LastEditTime: 2023-05-06 13:50:48
 * @FilePath: /LuoGu_OJ/【入门4】数组/P2615神奇的幻方.c
 * @describes: This file is created for learning Code.
 * Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved.
 */
#include <stdio.h>

int map[40][40];
int x, y;

void solve()
{
    int n;
    scanf("%d", &n);
    x = 1, y = (1 + n) / 2;
    map[x][y] = 1;
    for (int K = 2; K <= n * n; K++)
    {
        if (x == 1 && y != n)
        {
            x = n, y += 1;
            map[x][y] = K;
        }
        else if (y == n && x != 1)
        {
            y = 1, x--;
            map[x][y] = K;
        }
        else if (x == 1 && y == n)
        {
            x++;
            map[x][y] = K;
        }
        else if (x != 1 && y != n)
        {
            if (map[x - 1][y + 1] == 0)
            {
                x--, y++;
                map[x][y] = K;
            }
            else
            {
                x++;
                map[x][y] = K;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            printf("%d ", map[i][j]);
        printf("\n");
    }
}

int main()
{
    solve();
    return 0;
}
