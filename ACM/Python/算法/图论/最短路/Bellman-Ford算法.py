'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2024-04-12 15:55:33
LastEditTime: 2024-04-13 08:26:34
FilePath: /Python/算法/图论/Bellman-Ford算法.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2024 by KasperFan in WFU, All Rights Reserved. 
'''
from math import inf
import queue
N = 100000

n: int

e = [[] for _ in range(N)]
d = [inf for _ in range(N)]
cnt = [0 for _ in range(N)]
vis = [True for _ in range(N)]

q = queue.Queue()

def spfa(s: int) -> bool:
    while q:
        u = q.get()
        vis[u] = False
        for ed in e[u]:
            v, w = ed
            if d[v] > d[u]+w:
                d[v] = d[u] + w
                cnt[v] = cnt[u] + 1 # 记录边数
                if cnt[v] >= n: return True
                if not vis[v]: q.put(v); vis[v]=True
    return False


def main()
