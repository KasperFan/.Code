'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2024-04-19 20:45:55
LastEditTime: 2024-04-20 10:31:40
FilePath: /Python/算法/图论/最近公共祖先LCA/倍增算法.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2024 by KasperFan in WFU, All Rights Reserved. 
'''
import os, sys, io

input = lambda : sys.stdin.readline().strip()

def dfs(u: int, father:int) -> None:
    global dep, fa
    dep[u] = dep[father]+1
    # 向上跳1, 2, 4...步的祖先节点
    fa[u][0]=father
    for i in range(1, 20): fa[u][i] = fa[fa[u][i-1]][i-1]
    for v in e[u]:
        if v != father: dfs(v, u)

def lca(u: int, v: int) -> int:
    if dep[u] < dep[v]: u, v = v, u
    # 先跳到同一层
    for i in range(19, -1, -1):
        if dep[fa[u][i]] >= dep[v]: u = fa[u][i]
    if u == v: return v
    # 再跳到LCA的下一层
    for i in range(19, -1, -1):
        if fa[u][i] != fa[v][i]: u = fa[u][i]; v = fa[v][i]
    return fa[u][0]


N = int(5e5+10)
n: int; m: int; s: int; a: int; b: int
e: list[list[int]] = [[] for _ in range(N)]
dep: list[int] = [0 for _ in range(N)] # dep[u]存 u 点的深度
fa: list[list[int]] = [[0 for _ in range(20)] for _ in range(N)] 
# fa[u][i]存从 u 点向上跳2^{i}层的祖先节点。i=0,1,2,3...


