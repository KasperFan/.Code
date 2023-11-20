/*
 * @Author: KasperFan && fanwlx@foxmail.com
 * @Date: 2023-10-22 16:08:49
 * @LastEditTime: 2023-10-22 16:25:54
 * @FilePath: /Python/WFUStudy/第一次检验/P1003.cpp
 * @describes: This file is created for learning Python to deal OJ problems.
 * Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved.
 */
#include <bits/stdc++.h>

using namespace std;

int floors[(int)1e5 + 10][(int)1e5 + 10];
int n, a, b, g, k, x, y;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a >> b >> g >> k;
        for (int d = a; d <= g; d++)
            for (int e = b; e < k; e++)
                floors[d][e] = i;
    }
    cin >> x >> y;
    cout << (floors[x][y] == 0 ? -1 : floors[x][y]) << endl;
    return 0;
}
