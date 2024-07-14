/*
 * @Author: KasperFan && fanwlx@foxmail.com
 * @Date: 2023-11-03 23:37:32
 * @LastEditTime: 2023-11-03 23:50:04
 * @FilePath: /Python/tianti_contest/L2-4_寻宝图.cpp
 * @describes: This file is created for learning Python to deal OJ problems.
 * Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved.
 */
#include <iostream>

using namespace std;

int n, m, nx, ny, island, tresure;
int map[(int)1e5 + 10][(int)1e5 + 10];
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
bool is_tresure = false; // false为假(0)，true为真(!0)

void dfs(int x, int y)
{
    if (map[x][y] > 1) // 如果找到宝藏点
    {
        // 如果之前在这个岛上没找到过宝藏点
        tresure += !is_tresure ? 1 : 0; // 则将这个岛列为宝藏岛
        is_tresure = true;              // 在这个岛上找到过宝藏，避免下次找到宝藏重复计数
    }
    map[x][y] = 0; // 标记为空，下次不会再找
    for (int i = 0; i < 4; i++)
    {
        nx = x + dx[i];
        ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m || map[nx][ny] == 0)
            continue;
        dfs(nx, ny);
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%1d", &map[i][j]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (map[i][j] > 0)
            {
                is_tresure = false;
                island++;
                dfs(i, j);
            }
    cout << island << " " << tresure << endl;
    return 0;
}
