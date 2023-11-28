/*
 * @Author: KasperFan && fanwlx@foxmail.com
 * @Date: 2023-11-18 15:15:16
 * @LastEditTime: 2023-11-28 21:07:24
 * @FilePath: /Python/WFUStudy/P1469.c
 * @describes: This file is created for learning Python to deal OJ problems.
 * Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved.
 */
#include <stdio.h>

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