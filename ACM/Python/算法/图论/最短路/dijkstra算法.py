'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2024-04-12 14:51:38
LastEditTime: 2024-04-12 15:42:57
FilePath: /Python/算法/图论/dijkstra最短路.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2024 by KasperFan in WFU, All Rights Reserved. 
'''
import os
import sys

from math import inf

N = 100

e = [[] for _ in range(N)]  # e[u]存节点u的所有出边和权值
d = [inf for _ in range(N)]  # d[u]存节点u到原点s的最短距离
vis = [False for _ in range(N)]  # vis[u]标记u是否出圈

n:int
m:int
s:int

def dijkstra(s: int) -> None:
    global n
    d[s] = 0
    for i in range(1, n):  # 枚举次数
        u = 0
        for j in range(1, n+1):  # 枚举点
            if (not vis[j]) and d[j] < d[u]: u = j
        vis[u] = True # 标记u已出圈
        for ed in e[u]: # 枚举u所有出边
            v, w = ed
            if d[v] > d[u]+w: d[v] = d[u]+w


def main():
    global n, m, s, d
    n, m, s = map(int, input().split())
    for _ in range(m):
        a, b, c = map(int, input().split())
        e[a].append((b, c))
    dijkstra(s)
    print(d[1:n+1])

if __name__ == "__main__":
    main()