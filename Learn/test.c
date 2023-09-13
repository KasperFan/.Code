/*
 * @Author: KasperFan && fanwlx@foxmail.com
 * @Date: 2023-08-06 15:39:59
 * @LastEditTime: 2023-09-08 23:51:21
 * @FilePath: /.Code/Learn/test.c
 * @describes: This file is created for learning Code.
 * Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved.
 */
#include <stdio.h>

int max(int a,int b){
    return a > b ? a : b;
}

int min(int a, int b)
{
    return a < b ? a : b;
}

int (*funcs[2])(int, int) = {max, min}; // 函数指针数组

int main(int argc, char const *argv[])
{
    printf("%d\n", funcs[0](12, 67));
    printf("%d\n", funcs[1](12, 67));
    return 0;
}
