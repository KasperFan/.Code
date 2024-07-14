/*
 * @Author: KasperFan && fanwlx@foxmail.com
 * @Date: 2023-11-16 01:13:03
 * @LastEditTime: 2023-11-16 02:15:13
 * @FilePath: /Python/WFUStudy/摸底/P1068.cpp
 * @describes: This file is created for learning Python to deal OJ problems.
 * Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved.
 */
#include <bits/stdc++.h>

using namespace std;

typedef struct Competitor
{
    int k, s;
    int method() {
        printf("Hello,World\n");
    }
} Competitor;

// 依次对应选手人数、录取人数、选手序号、选手成绩、绑定顺序
int n, m;
Competitor competitors[5010], temp;

int main()
{
    // 输入输出速度优化
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    // 更新录取人数
    m = (int)(m * 1.5);
    // 读入选手信息，按输入顺序排index编号
    for (int i = 1; i <= n; i++) cin >> competitors[i].k >> competitors[i].s;
    // 按照选手序号对其排序（冒泡）
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n - i; j++)
            if (competitors[j].k < competitors[j].k)
            {
                temp = competitors[j];
                competitors[j] = competitors[j + 1];
                competitors[j+1] = temp;
            }
    // 按照选手成绩对其排序（冒泡）
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n - i; j++)
            if (competitors[j].s < competitors[j+1].s)
            {
                temp = competitors[j];
                competitors[j] = competitors[j + 1];
                competitors[j + 1] = temp;
            }
    // 如果第m+1位选手的成绩与第m位选手成绩一致，则m++
    while (competitors[m + 1].s == competitors[m].s) m++;
    // 输出最终末位选手的成绩和名次
    cout << competitors[m].s << " " << m << endl;
    // 依次输出
    for (int i = 1; i <= m; i++)
        cout << competitors[i].k << " " << competitors[i].s << endl;
    return 0;
}
