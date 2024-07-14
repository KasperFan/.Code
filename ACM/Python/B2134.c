/*
 * @Author: KasperFan && fanwlx@foxmail.com
 * @Date: 2023-10-12 23:01:04
 * @LastEditTime: 2023-10-12 23:02:26
 * @FilePath: /Python/B2134.c
 * @describes: This file is created for learning Python to deal OJ problems.
 * Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved.
 */
#include <stdio.h>
#include <math.h>

int zhiShu(int m)
{
    int sk = (int)sqrt(m);
    for (int i = 2; i <= sk; i++)
        if (m % i == 0) return 0;
    return 1;
}

void qiuHe(int k)
{
    for (int i = k / 2; i >= 1; i--)
        if (zhiShu(i) && zhiShu(k - i)) 
        { 
            printf("%d\n", i * (k - i));
            return;
        }
}

int main()
{
    int S;
    scanf("%d", &S);
    qiuHe(S);
    return 0;
}