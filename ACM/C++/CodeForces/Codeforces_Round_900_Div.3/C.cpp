/*
 * @Author: KasperFan && fanwlx@foxmail.com
 * @Date: 2023-09-26 23:43:24
 * @LastEditTime: 2023-09-27 00:13:02
 * @FilePath: /C++/CodeForces/Codeforces_Round_900_Div.3/C.cpp
 * @describes: This file is created for learning Code.
 * Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved.
 */
#include <bits/stdc++.h>

using namespace std;

long long t, n, k, x;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    while (t--)
    {
        cin >> n >> k >> x;
        if (k * (k + 1) / 2.0 > x)
        {
            cout << "NO" << endl;
        }
        else if (k * (2 * n - k + 1) / 2.0 >= x)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
