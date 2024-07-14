'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2024-03-31 11:48:41
LastEditTime: 2024-03-31 11:54:12
FilePath: /Python/搜索唐题（字符串版）.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2024 by KasperFan in WFU, All Rights Reserved. 
'''
direction = 'python'
n = int(input())
ans = 0
is_visited = [[False for _ in range(n+1)] for _ in range(n+1)]
graph = ['']+[['']+[*input()] for _ in range(n)]
# print(graph)
x, y = map(int, input().split())
dx = [0, 0, +1, -1]
dy = [+1, -1, 0, 0]


def dfs(kx, ky, step, head):
    global is_visited, ans
    is_visited[kx][ky] = True
    for i in range(4):
        nx, ny = kx+dx[i], ky+dy[i]
        if nx not in range(1, n+1) or ny not in range(1, n+1): continue
        if graph[nx][ny] != direction[(step+head)%6]: continue
        if is_visited[nx][ny]: continue
        dfs(nx, ny, step+1, head)
    is_visited[kx][ky] = False
    ans = step if step > ans else ans


dfs(x, y, 1, direction.index(graph[x][y]))

print(ans)
