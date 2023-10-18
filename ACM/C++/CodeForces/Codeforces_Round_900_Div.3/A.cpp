/*
 * @Author: KasperFan && fanwlx@foxmail.com
 * @Date: 2023-09-26 22:47:33
 * @LastEditTime: 2023-09-26 23:01:56
 * @FilePath: /C++/CodeForces/Codeforces_Round_900(Div.3)/A.How_Much_Does_Daytona_Cost?.cpp
 * @describes: This file is created for learning Code.
 * Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved.
 */
#include <bits/stdc++.h>

using namespace std;

int a[110], t, n, k;
bool is_common = false;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    while (t--)
    {
        is_common = false;
        cin >> n >> k;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] == k)
            {
                is_common = true;
            }
        }
        cout << (is_common ? "YES" : "NO") << endl;
    }

    return 0;
}
