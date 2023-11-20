/*
 * @Author: KasperFan && fanwlx@foxmail.com
 * @Date: 2023-10-15 21:26:25
 * @LastEditTime: 2023-11-04 10:45:31
 * @FilePath: /Python/main.c
 * @describes: This file is created for learning Python to deal OJ problems.
 * Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved.
 */
#include <stdio.h>

char pinyin[10][5] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
int main()
{
    for (int i = 0; i < 10; i++)
    {
        printf("%s\n", pinyin[i]);
    }
    return 0;
}
