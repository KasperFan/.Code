/*
 * @Author: KasperFan && fanwlx@foxmail.com
 * @Date: 2023-10-10 14:33:54
 * @LastEditTime: 2023-10-10 16:52:25
 * @FilePath: /Python/664.c
 * @describes: This file is created for learning Python to deal OJ problems.
 * Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved.
 */
#include <stdio.h>
typedef enum{false, true} bool;
typedef long long ll;

bool is_prime(int n);

int main()
{
    int n, cnt = 0;
    scanf("%d", &n);
    for (int i = 2; i < n; i++)
    {
        if (is_prime(i))
        {
            printf("%d", i); cnt++;
            if (cnt % 10) printf(" ");
            else printf("\n");
        }
    }
    return 0;
}

bool is_prime(int n)
{
    for (int i = 2; i * i <= n; i++)
        if (!(n % i)) return false;
    return true;
}
