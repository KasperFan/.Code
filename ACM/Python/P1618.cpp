/*
 * @Author: KasperFan && fanwlx@foxmail.com
 * @Date: 2023-11-14 23:51:14
 * @LastEditTime: 2023-11-15 01:24:23
 * @FilePath: /Python/P1618.cpp
 * @describes: This file is created for learning Python to deal OJ problems.
 * Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved.
 */
#include <iostream>

using namespace std;

double A, B, C;
int cnt;
int first, second, third;
int si, sj, sk; // second每位上的数（i,j,k）
int ti, tj, tk; // third每位上的数（i,j,k）
bool is_used[10];

bool check(int number)
{
    if (is_used[number] == true || number == 0)
        return false;
    is_used[number] = true;
    return true;
}

int main()
{
    // 输入输出速度优化
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> A >> B >> C;
    if (A == 0 || B == 0 || C == 0)
    {
        cout << "No!!!" << endl;
        return 0;
    }
    // i 为第一个数百位上的数
    // j 为第一个数十位上的数
    // k 为第一个数个位上的数
    // ijk
    for (int i = 1; i <= 9; i++)
    {
        is_used[i] = true;
        for (int j = 1; j <= 9; j++)
        {
            if (is_used[j])
                continue;
            is_used[j] = true;
            for (int k = 1; k <= 9; k++)
            {
                if (is_used[k])
                    continue;
                is_used[k] = true;
                first = i * 100 + j * 10 + k; // 第一个数的取值
                if (first > 1000 * (A * 1.0 / (A + B + C)))

                    second = (int)(first * (B / A)); // 第二个数的取值
                if (second >= 1000)
                {
                    is_used[k] = false;
                    continue;
                }
                si = second / 100;
                if (!check(si))
                {
                    is_used[k] = false;
                    continue;
                }
                sj = (second % 100) / 10;
                if (!check(sj))
                {
                    is_used[k] = is_used[si] = false;
                    continue;
                }
                sk = second % 10;
                if (!check(sk))
                {
                    is_used[k] = is_used[si] = is_used[sj] = false;
                    continue;
                }

                third = (int)(first * (C / A)); // 第三个数的取值 (300, 999]
                if (third >= 1000)
                {
                    is_used[k] = is_used[si] = is_used[sj] = is_used[sk] = false;
                    continue;
                }
                ti = third / 100;
                if (!check(ti))
                {
                    is_used[k] = is_used[si] = is_used[sj] = is_used[sk] = false;
                    continue;
                }
                tj = (third % 100) / 10;
                if (!check(tj))
                {
                    is_used[k] = is_used[si] = is_used[sj] = is_used[sk] = is_used[ti] = false;
                    continue;
                }
                tk = third % 10;
                if (!check(tk))
                {
                    is_used[k] = is_used[si] = is_used[sj] = is_used[sk] = is_used[ti] = is_used[tj] = false;
                    continue;
                }

                cout << first << " " << second << " " << third << endl;
                cnt++;
                is_used[si] = is_used[sj] = is_used[sk] = is_used[ti] = is_used[tj] = is_used[tk] = false;

                is_used[k] = false;
            }
            is_used[j] = false;
        }
        is_used[i] = false;
    }
    if (!cnt)
        cout << "No!!!" << endl;
    return 0;
}
