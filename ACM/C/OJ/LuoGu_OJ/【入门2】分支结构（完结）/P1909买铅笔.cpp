/*
 * @Author: KasperFan && fanwlx@foxmail.com
 * @Date: 2023-08-24 17:54:16
 * @LastEditTime: 2023-08-24 19:49:12
 * @FilePath: /ACM/C/OJ/LuoGu_OJ/【入门2】分支结构（完结）/P1909买铅笔.cpp
 * @describes: This file is created for learning Code.
 * Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved.
 */
#include <bits/stdc++.h>
// #include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long n, num, value, cost = 1e10;
    cin >> n;
    for (int i = 0; i < 3; i++)
    {
        cin >> num >> value;
        long temp = ((n % num == 0) ? n / num : n / num + 1) * value;
        cost = cost > temp ? temp : cost;
    }
    cout << cost << endl;
    return 0;
}
