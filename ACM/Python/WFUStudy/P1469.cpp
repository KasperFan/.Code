/*
 * @Author: KasperFan && fanwlx@foxmail.com
 * @Date: 2023-11-18 15:15:16
 * @LastEditTime: 2023-11-29 14:28:41
 * @FilePath: /Python/WFUStudy/P1469.cpp
 * @describes: This file is created for learning Python to deal OJ problems.
 * Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved.
 */
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, pair<int, int>> triple;
typedef tuple<int, int, int> triples;

int len[(int)1e9 + 10];
int have_len[(int)1e9 + 10];
int all_lengs[(int)5e6 + 10];
int idx, n, i;

int main()
{
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &i);
        if (!have_len[i])
        {
            have_len[i] = 1;
            all_lengs[idx++] = i;
        }
        len[i]++;
    }
    for (int k = 0; k < idx; k++)
    {
        if (len[all_lengs[k]] % 2)
        {
            printf("%d\n", all_lengs[k]);
            return 0;
        }
    }

    return 0;
}


void example(){
    gets();
    fgets(str, 12, stdin);
}