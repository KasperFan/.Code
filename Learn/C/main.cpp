/*
 * @Author: KasperFan && fanwlx@foxmail.com
 * @Date: 2023-11-28 23:51:15
 * @LastEditTime: 2023-12-22 21:25:57
 * @FilePath: /C/main.cpp
 * @describes: This file is created for learning Code.
 * Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved.
 */
#include <stdio.h>
#define ll long long
const ll kmod = 1e9 + 7;
const int kmax = 1e6 + 5;

ll _max(ll m, ll n)
{
    if (m > n)
        return m;
    return n;
}

ll _C(ll m, ll n) // down: m;  up:n;
{
    // return (k == 1ll ? x : x * (x - 1ll) / 2ll) % kmod;
    ll i = 1;
    ll up = 1;
    ll down = 1;

    for (i = n; i > 0; i--)
    {
        down *= i % kmod;
        up *= (m - i + 1) % kmod;
    }

    return (up / down) % kmod;
}

int main()
{
    freopen("./P3799_4.in", "r", stdin);
    ll n, arr, temp[kmax] = {0}, i, max = 0, j;
    ll lgc = 1, ans = 0, s = 0;

    scanf("%lld", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%lld", &arr);
        max = _max(max, arr) % kmod;
        temp[arr]++;
    }

    for (i = 2; i <= max; i++)
    {
        if (temp[i] >= 2)
        {
            lgc = _C(temp[i], 2) % kmod;
        }
        else
        {
            continue;
        }

        for (j = 1; j <= i / 2; j++)
        {
            if (j + j == i && temp[j] >= 2)
            {
                ans += _C(temp[j], 2) % kmod;
            }
            if (j + j != i && temp[j] >= 1 && temp[i - j] >= 1)
            {
                ans += _C(temp[j], 1) * _C(temp[i - j], 1) % kmod;
            }
        }
        ans %= kmod;
        s += lgc * ans % kmod;
        ans = 0;
        lgc = 0;
    }
    s %= kmod;

    printf("%lld\n", s);
    return 0;
}