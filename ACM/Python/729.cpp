/*
 * @Author: KasperFan && fanwlx@foxmail.com
 * @Date: 2023-10-09 08:30:31
 * @LastEditTime: 2023-10-11 14:09:11
 * @FilePath: /Python/729.cpp
 * @describes: This file is created for learning Python to deal OJ problems.
 * Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved.
 */
#include <bits/extc++.h>
typedef long long ll;

using namespace std;

ll T, n, f[50];

ll F(ll n);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while (T--)
    {
        cin >> n;
        cout << F(n) << endl;
    }
    return 0;
}

ll F(ll n)
{
    if (n == 2 && f[n] == 0)
        f[n] = 1;
    else if (n != 1 && f[n] == 0)
        f[n] = 4 * F(n - 1) - 5 * F(n - 2);
    return f[n];
}