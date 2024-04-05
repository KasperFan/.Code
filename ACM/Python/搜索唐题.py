'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2024-03-31 11:14:32
LastEditTime: 2024-03-31 11:58:06
FilePath: /Python/搜索唐题.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2024 by KasperFan in WFU, All Rights Reserved. 
'''
direction = {'p':'y', 'y':'t', 't':'h', 'h':'o', 'o':'n', 'n':'p'}

n = int(input())
ans = 0
is_visited = [[False for _ in range(n)] for _ in range(n)]
graph = ['']+[['']+[*input()] for _ in range(n)]
for i in graph:
    print(i)
x, y = map(int, input().split())
dx = [0, 0, +1, -1]
dy = [+1, -1, 0, 0]

def dfs(kx, ky, step):
    global is_visited, ans
    is_visited[kx][ky] = True
    for i in range(4):
        nx, ny = kx+dx[i], ky+dy[i]
        if nx not in range(n) or ny not in range(n): continue
        if graph[nx][ny] != direction[graph[kx][ky]]: continue
        if is_visited[nx][ny]: continue
        dfs(nx, ny, step+1)
    is_visited[kx][ky] = False
    ans = step if step > ans else ans

dfs(x, y, 1)

print(ans)