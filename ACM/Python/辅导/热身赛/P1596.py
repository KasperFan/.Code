'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2024-01-28 14:27:29
LastEditTime: 2024-01-28 15:43:21
FilePath: /Python/辅导/热身赛/P1596.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2024 by KasperFan in WFU, All Rights Reserved. 
'''
from sys import stdin

input = lambda: stdin.readline().strip()

flag = False

def dfs(x, y, depth):
    global graph, flag
    if depth > 500: flag = True; return # 避免爆栈
    graph[x][y] = 's'
    for i in range(8):
        nx, ny = x+dx[i], y+dy[i]
        if nx not in range(0, N) or ny not in range(0, M): continue
        if graph[nx][ny] != 'W': continue
        dfs(nx, ny, depth+1)
        if flag: return

dx = [-1, -1, -1, 0, 0, +1, +1, +1]; dy = [-1, 0, +1, -1, +1, -1, 0, +1]
ans = 0
N, M = map(int, input().split())
graph = [[*input()] for _ in range(N)]
for i in range(N):
    for j in range(M):
        flag = False
        if graph[i][j] == 'W': ans+=1; dfs(i, j, 1)
        elif graph[i][j] == 's': dfs(i, j, 1)
print(ans)
