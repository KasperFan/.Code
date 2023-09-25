/*
 * @Author: KasperFan && fanwlx@foxmail.com
 * @Date: 2023-08-10 14:16:57
 * @LastEditTime: 2023-08-11 21:16:10
 * @FilePath: /C/OJ/LuoGu_OJ/【入门1】顺序结构（完结）/P5707.cpp
 * @describes: This file is created for solving OJ problems.
 * Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved.
 */
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int s, v, hour, minute = 480;
    scanf("%d %d", &s, &v);
    minute -= 10;
    int time = s % v == 0 ? s / v : s / v + 1;
    minute -= time;
    minute += 24 * 60;
    minute %= 24 * 60;
    hour = minute / 60;
    minute %= 60;
    printf("%02d:%02d\n", hour, minute);
    return 0;
}
