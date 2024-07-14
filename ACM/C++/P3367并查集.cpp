/*
 * @Author: KasperFan && fanwlx@foxmail.com
 * @Date: 2023-09-14 17:50:30
 * @LastEditTime: 2023-09-17 18:17:04
 * @FilePath: /C++/P3367并查集.cpp
 * @describes: This file is created for learning Code.
 * Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
 */
#include <bits/extc++.h>

using namespace std;

int find_parent(int i);
void merge_set(int x, int y);
bool is_same_set(int x, int y);

int N, M, P[(long)1e4 + 10];
int Z, X, Y;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) P[i] = i;

    for (int i = 1; i <= M; i++)
    {
        cin >> Z >> X >> Y;
        if (Z == 1) merge_set(X, Y);
        else cout << (is_same_set(X, Y) ? 'Y' : 'N') << endl;
    }
    return 0;
}

int find_parent(int i)
{
    if (P[i] == i) return i;
    else { P[i] = find_parent(P[i]); return P[i];}
}

void merge_set(int x, int y) { P[find_parent(x)] = P[find_parent(y)]; }

bool is_same_set(int x, int y) { return P[find_parent(x)] == P[find_parent(y)]; }
