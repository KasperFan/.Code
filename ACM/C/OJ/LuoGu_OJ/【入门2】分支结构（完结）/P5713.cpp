/*
 * @Author: KasperFan && fanwlx@foxmail.com
 * @Date: 2023-08-13 02:31:04
 * @LastEditTime: 2023-08-13 02:49:23
 * @FilePath: /C/OJ/LuoGu_OJ/【入门2】分支结构（完结）/P5713.cpp
 * @describes: This file is created for solving OJ problems.
 * Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved.
 */
#include <iostream>

using namespace std;

int main()
{
    int a;
    cin >> a;
    cout << (5 * a > (11 + 3 * a) ? "Luogu" : "Local") << endl;
    return 0;
}