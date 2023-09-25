/*
 * @Author: KasperFan && fanwlx@foxmail.com
 * @Date: 2023-08-08 18:43:17
 * @LastEditTime: 2023-08-09 10:39:35
 * @FilePath: /C/OJ/LuoGu_OJ/【入门1】顺序结构（完结）/P5705.c
 * @describes: This file is created for learning Code.
 * Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved.
 */
#include <stdio.h>

int main()
{
    double num, ans = 0.0;
    scanf("%lf", &num);
    num *= 10;
    while ((int)num > 0)
    {
        ans = ans * 10 + (int)num % 10;
        num /= 10;
    }
    ans /= 1000;
    printf("%.3lf\n", ans);
    return 0;
}
