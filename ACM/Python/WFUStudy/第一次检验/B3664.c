/*
 * @Author: KasperFan && fanwlx@foxmail.com
 * @Date: 2023-10-23 08:50:32
 * @LastEditTime: 2023-10-23 23:33:25
 * @FilePath: /Python/WFUStudy/第一次检验/B3664.c
 * @describes: This file is created for learning Python to deal OJ problems.
 * Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved.
 */
#include <stdio.h>

int k, ans;  // k个售卖点，ans为输出答案（相邻两个售卖点最远距离）
int a[5050]; // 用以记录每个售卖点对应坐标

int main()
{
    scanf("%d", &k);             // 输入k
    for (int i = 1; i <= k; i++) // 输入k个售卖点对应的坐标位置（非升序读入）
        scanf("%d", &a[i]);

    // 因为输入的坐标可能是乱序，所以需要排序

    // 冒泡排序部分（从小到大/升序排序）
    for (int i = 1; i <= k; i++)         // 外部循环k次，每次将一个第 i 大的值移到倒数第 i 个位置
        for (int j = 1; j <= k - i; j++) // 数组内部从头作两两比较
            if (a[j] > a[j + 1])         // 如果左边的比右边的大，则交换两数位置
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
            // 准备比较[右边（左边）]和[右边的右边（右边）]

    for (int i = 2; i <= k; i++) // 遍历比较相邻两点的坐标差，找到最大坐标差
        ans = a[i] - a[i - 1] > ans ? a[i] - a[i - 1] : ans;
    printf("%d\n", ans);
    return 0;
}
