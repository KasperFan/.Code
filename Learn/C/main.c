/*
 * @Author: KasperFan && fanwlx@foxmail.com
 * @Date: 2023-09-18 19:10:10
 * @LastEditTime: 2023-10-31 12:04:53
 * @FilePath: /C/main.c
 * @describes: This file is created for learning Code.
 * Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved.
 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // int arr[10];
    int *arr = (int *)malloc(sizeof(int) * 10);
    for (int i = 0; i < 10; i++)
    {
        arr[i] = 10 - i;
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", arr[i]);
    }
    printf("\n");
    int *narr = (int *)realloc(arr, sizeof(int) * 20);
    printf("%#x\n", narr);
    printf("%p\n", narr);
    char *p = narr;
    printf("%#x\n", p);
    printf("%p\n", p);
    printf("%d\n", *(narr + 3));
    printf("%d\n", *(p + 3));
    free(narr);
    free(arr);
    return 0;
}
