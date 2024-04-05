'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2024-01-28 15:44:20
LastEditTime: 2024-01-29 10:31:01
FilePath: /Python/辅导/热身赛/P1598.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2024 by KasperFan in WFU, All Rights Reserved. 
'''
# from sys import stdin

# input = lambda: stdin.readline().strip()

# data = "".join(*[input().split() for _ in range(4)])
# print(data)
# bucket = [0 for _ in range(26)]
# for i in data:
#     bucket[ord(i)]
# print(bucket)

from sys import stdin


def input(): return stdin.readline().strip()


ans = 0
graph = [[0 for _ in range(7)] for _ in range(7)]
is_visited = [[False for _ in range(7)] for _ in range(7)]
dx = [-1, +1, 0, 0]
dy = [0, 0, -1, +1]


def dfs(x, y):
    global ans, is_visited
    if x == fx and y == fy:
        ans += 1
        return
    is_visited[x][y] = True
    for i in range(4):
        nx, ny = x+dx[i], y+dy[i]
        if nx not in range(1, m+1) or ny not in range(1, n+1)\
                or graph[nx][ny] != 0 or is_visited[nx][ny]:
            continue
        dfs(nx, ny)
    is_visited[x][y] = False
    return


n, m, t = map(int, input().split())
sx, sy, fx, fy = map(int, input().split())
for i in range(t):
    zx, zy = map(int, input().split())
    graph[zx][zy] = 1
dfs(sx, sy)
print(ans)
