/*
 * @Author: KasperFan && fanwlx@foxmail.com
 * @Date: 2023-05-15 16:56:19
 * @LastEditTime: 2023-05-15 17:10:48
 * @FilePath: /.Code/帮忙文档/wjh.c
 * @describes: This file is created for learning Code.
 * Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved.
 */
#include <stdio.h>
#include <string.h>

int main()
{
    char arr1[] = "msn\t\0\\1\\\t";
    // char arr2[] = {'m', 's', 'n', '\t', '\0', '1', '\\', '\t', '\0'};
    int num = strlen(arr1);
    printf("%d\n%s\n", num,arr1);
    return 0;
}