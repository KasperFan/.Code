'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-11-03 22:42:05
LastEditTime: 2023-11-03 23:08:27
FilePath: /Python/tianti_contest/L2-4 寻宝图.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''
img: list
dx: list = [-1, 1, 0, 0]
dy: list = [0, 0, -1, 1]
island: int = 0
tresure: int = 0
is_tresure: bool = False


def dfs(x: int, y: int) -> None:
    global img, tresure, is_tresure
    if img[x][y] > 1:
        tresure += 1 if not is_tresure else 0
        is_tresure = True
    img[x][y] = 0
    for i in range(4):
        nx = x+dx[i]
        ny = y+dy[i]
        if nx < 0 or nx >= n or ny < 0 or ny >= m or img[nx][ny] == 0:
            continue
        dfs(nx, ny)


n, m = map(int, input().split())
img = [list(map(int, input())) for _ in range(n)]
for i in range(n):
    for j in range(m):
        if img[i][j] > 0:
            is_tresure = False
            island += 1
            dfs(i, j)
print(island, tresure)
