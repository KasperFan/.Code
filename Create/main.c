/*
 * @Author: KasperFan && fanwlx@foxmail.com
 * @Date: 2023-06-16 04:39:12
 * @LastEditTime: 2023-06-16 04:39:17
 * @FilePath: /bulid/main.c
 * @describes: This file is created for learning Code.
 * Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved.
 */
#include <stdio.h>

int main(int argc, char const *argv[])
{
    for (size_t i = 1; i < 3; i++)
    {
        printf("Hello CMake,this is %s\n", __func__);
    }
    return 0;
}

