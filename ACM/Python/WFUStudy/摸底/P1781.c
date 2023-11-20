/*
 * @Author: KasperFan && fanwlx@foxmail.com
 * @Date: 2023-11-06 22:40:14
 * @LastEditTime: 2023-11-06 23:37:42
 * @FilePath: /Python/WFUStudy/摸底/P1781.c
 * @describes: This file is created for learning Python to deal OJ problems.
 * Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved.
 */
#include <stdio.h>
#include <string.h>

int n, win = 1;
char chk[21][110];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%s", chk[i]);
    for (int i = 1; i <= n; i++)
    {
        if (strlen(chk[i]) > strlen(chk[win]))
        {
            win = i;
        }
        else if (strlen(chk[i]) == strlen(chk[win]))
        {
            for (int j = 0; j < strlen(chk[win]); j++)
            {
                if (chk[i][j] > chk[win][j])
                {
                    win = i;
                    break;
                }
                else if (chk[i][j] < chk[win][j]) // 加上这个条件，来判断两个字符串的第j个字符是否相等
                {
                    break;
                }
            }
        }
    }
    printf("%d\n%s\n", win, chk[win]);
    return 0;
}
