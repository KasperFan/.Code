'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2024-04-19 19:51:46
LastEditTime: 2024-04-19 20:34:47
FilePath: /Python/OJ/LuoGu/P3366_【模板】最小生成树.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2024 by KasperFan in WFU, All Rights Reserved. 
'''
import os, sys, io

input = lambda: sys.stdin.readline().strip()

buffer = io.StringIO()

class Edge:
    def __init__(self, u, v, w) -> None:
        self.u, self.v, self.w = u, v, w
        pass

def find_fa(x: int) -> int:
    global fa
    if fa[x] != x: fa[x] = find_fa(fa[x])
    return fa[x]

def kruskal() -> bool:
    global e, cnt, ans
    e.sort(key=lambda o: o.w)
    for i in range(M):
        x, y = find_fa(e[i].u), find_fa(e[i].v)
        if x != y:
            fa[x] = y
            ans += e[i].w
            cnt += 1
    return cnt == N-1

cnt = 0; ans = 0
N, M = map(int, input().split())
e = [Edge(*map(int, input().split())) for _ in range(M)]
fa = [i for i in range(N+1)]
if kruskal(): print(ans)
else: print('orz')

