'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2024-01-06 15:49:41
LastEditTime: 2024-01-14 10:57:01
FilePath: /Python/P2895_Meteor_Shower_S.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2024 by KasperFan in WFU, All Rights Reserved. 
'''
from sys import stdin
# import numpy as np


def input() -> str: return stdin.readline().strip()


img: list = [[-1 for _ in range(350)] for _ in range(350)]
is_visited: list = [[False for _ in range(350)] for _ in range(350)]
dx: list[int] = [-1, +1, 0, 0, 0]
dy: list[int] = [0, 0, -1, +1, 0]


def main() -> int:
    M: int = int(input())
    for _ in range(M):
        X, Y, T = map(int, input().split())
        for i in range(5):
            nx = X + dx[i]
            ny = Y + dy[i]
            if (nx < 0 or ny < 0):
                continue
            img[nx][ny] = T if (img[nx][ny] == -1 or img[nx]
                                [ny]) > T else img[nx][ny]
    print(bfs())
    return 0


def bfs() -> int:
    step = 0
    queue = []
    is_visited[0][0] = True
    queue.append((0, 0))
    while len(queue) > 0:
        size = len(queue)
        for _ in range(size):
            nodex, nodey = queue.pop(0)
            if img[nodex][nodey] == -1:
                return step
            elif img[nodex][nodey] <= step:
                continue
            for i in range(4):
                nx = nodex+dx[i]
                ny = nodey+dy[i]
                if nx < 0 or ny < 0:
                    continue
                if not is_visited[nx][ny]:
                    is_visited[nx][ny] = True
                    queue.append((nx, ny))
        step += 1
    return -1


if __name__ == "__main__":
    main()
