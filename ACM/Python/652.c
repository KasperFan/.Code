/*
 * @Author: KasperFan && fanwlx@foxmail.com
 * @Date: 2023-10-07 21:51:52
 * @LastEditTime: 2023-10-09 10:37:35
 * @FilePath: /Python/652.c
 * @describes: This file is created for learning Python to deal OJ problems.
 * Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved.
 */
#include <stdio.h>

int n, cnt, a[(int)1e5 + 1];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        if (i % 2) cnt += a[i];
        else cnt -= a[i];
    }
    if (cnt > 0) printf("Greater than\n");
    else if (cnt < 0) printf("Less than\n");
    else printf("Equal\n");
    return 0;
}

