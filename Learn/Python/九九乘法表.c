/*
 * @Author: KasperFan && fanwlx@foxmail.com
 * @Date: 2023-09-28 13:43:17
 * @LastEditTime: 2023-09-28 14:18:15
 * @FilePath: /Python/九九乘法表.c
 * @describes: This file is created for learning Code.
 * Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved.
 */
#include <stdio.h>

int main(int argc, char const *argv[])
{
    for (int i = 1; i < 10; i++)
    {
        for (int j = 0; j < 9 - i; j++)
        {
            printf("\t");
        }
        for (int j = i; j > 0; j--)
        {
            printf("%d*%d=%d\t", j, i, i * j);
        }
        printf("\n");
    }
    return 0;
}
