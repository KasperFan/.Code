'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-10-28 17:02:12
LastEditTime: 2023-10-28 17:25:58
FilePath: /Python/OJ/LuoGu/搜索/P1605迷宫.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''
from sys import stdin
def input(): return stdin.readline()


n: int
m: int
t: int
sx: int
sy: int
fx: int
fy: int
ans: int = 0
img: list = [[0]*7 for _ in range(7)]
is_visited: list = [[False]*7 for _ in range(7)]
dx: list = [-1, +1, 0, 0]
dy: list = [0, 0, -1, +1]


def dfs(x: int, y: int):
    global ans, is_visited
    if x == fx and y == fy:
        ans += 1
        return
    for i in range(4):
        nx = x+dx[i]
        ny = y+dy[i]
        if (nx < 1 or nx > m or ny < 1 or ny > n) or (img[nx][ny] != 0) or (is_visited[nx][ny]):
            continue
        is_visited[nx][ny] = True
        dfs(nx, ny)
        is_visited[nx][ny] = False
    return


if __name__ == "__main__":
    n, m, t = map(int, input().split())
    sx, sy, fx, fy = map(int, input().split())
    for i in range(t):
        zx, zy = map(int, input().split())
        img[zx][zy] = 1
    img[sx][sy] = 1
    dfs(sx, sy)
    print(ans)
