'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2024-04-19 17:26:13
LastEditTime: 2024-04-19 19:39:47
FilePath: /Python/算法/图论/最小生成树Kruskal算法.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2024 by KasperFan in WFU, All Rights Reserved. 
'''
class edge:
    def __init__(self, u, v, w) -> None:
        self.u, self.v, self.w = u, v, w

def findfa(x: int) -> int:
    global fa
    if fa[x] != x: fa[x]=findfa(fa[x])
    return fa[x]

def kruskal() -> bool:
    global e, ans, cnt
    e.sort(key=lambda o: o.w) # 将所有的边按边权从小到大排序（贪心思想）
    for i in range(m): # 按顺序枚举每一条边
        x, y = findfa(e[i].u), findfa(e[i].v)
        if x != y: # 如果这条边连接的两个点不在同一集合
            fa[x] = y  # 就把这条边加入最小生成树，并合并这两个集合
            ans += e[i].w
            cnt += 1
    return cnt == n-1 # 重复执行，直到选取了n-1条边为止

ans: int; cnt: int

n, m = map(int, input().split())
e = [edge(*map(int, input().split())) for _ in range(m)]
fa = [i for i in range(n+1)] # 初始化并查集，把n个点放在n个独立的集合