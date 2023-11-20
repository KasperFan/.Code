/*
 * @Author: KasperFan && fanwlx@foxmail.com
 * @Date: 2023-10-29 11:35:55
 * @LastEditTime: 2023-10-29 11:46:15
 * @FilePath: /Python/OJ/LuoGu/搜索/P2036.c
 * @describes: This file is created for learning Python to deal OJ problems.
 * Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved.
 */
#include <stdio.h>
#include <math.h>

int n, S = 1, B, ans = (int)1e9, s[11], b[11];

void dfs(int which)
{
    for (int i = which + 1; i <= n; i++)
    {
        S *= s[i];
        B += b[i];
        ans = ((int)fabs(S - B) < ans ? (int)fabs(S - B) : ans);
        dfs(i);
        S /= s[i];
        B -= b[i];
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d %d", &s[i], &b[i]);
    }
    dfs(0);
    printf("%d\n", ans);
    return 0;
}
