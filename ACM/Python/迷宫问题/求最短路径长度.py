'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2024-01-30 15:05:06
LastEditTime: 2024-01-30 15:35:51
FilePath: /Python/迷宫问题/求最短路径长度.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2024 by KasperFan in WFU, All Rights Reserved. 
'''
from sys import stdin


def input(): return stdin.readline().strip()


def bfs():
    global book, q
    step = 1
    q.append((SX, SY))
    while len(q):
        size = len(q) # 记录下一阶段取几个点开搜
        for _ in range(size):
            nodex, nodey = q.pop(0)
            if nodex == FX and nodey == FY: return step
            book[nodex][nodey] = True
            for i in range(4):
                nx, ny = nodex+dx[i], nodey+dy[i]
                if nx not in range(0, N) or ny not in range(0, M)\
                    or graph[nx][ny] == 1 or book[nx][ny]: continue
                q.append((nx, ny))
        step += 1
    return -1



dx = [-1, +1, 0, 0]; dy = [0, 0, -1, +1]
graph = [[0 for _ in range(5)] for _ in range(5)]
book = [[False for _ in range(5)] for _ in range(5)]
q = []


N, M, T = map(int, input().split())
SX, SY, FX, FY = map(int, input().split())
for i in range(T):
    DX, DY = map(int, input().split())
    graph[DX][DY] = 1
print(bfs())

# def dfs(x, y):
#     global book
#     if x == FX and y == FY: pass
#     book[x][y] = True
#     ''' nx, ny ... check,dfs(nx,ny)'''
#     book[x][y] = False
