'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-11-18 17:32:32
LastEditTime: 2023-11-18 17:51:30
FilePath: /Python/WFUStudy/P1135.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''
from sys import *


def input(): return stdin.readline()


def bfs():
    global Q
    step = 0
    size: int
    while len(Q) > 0:
        size = len(Q)
        for _ in range(size):
            point = Q.pop(0)
            if point == B:
                return step
            for j in range(len(dx)):
                npoint = point+dx[j]*K[point]
                if npoint in range(1, N+1) and not is_visited[npoint]:
                    is_visited[npoint] = True
                    Q.append(npoint)
        step += 1
    return -1


dx = [+1, -1]
Q = []
is_visited = [False for _ in range(210)]
N, A, B = map(int, input().strip().split())
K = [0]+[*map(int, input().strip().split())]
is_visited[A] = True
Q.append(A)
print(bfs())
