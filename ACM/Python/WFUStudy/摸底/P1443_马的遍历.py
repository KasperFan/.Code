'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-11-05 18:01:22
LastEditTime: 2023-11-05 18:29:26
FilePath: /Python/WFUStudy/摸底/P1443_马的遍历.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''
import sys, io
def input(): return sys.stdin.readline()


buffer = io.StringIO()
n: int
m: int
x: int
y: int
step: int = 0
queue: list = []
image: list = [[-1 for i in range(410)] for _ in range(410)]
is_visited: list = [[False for i in range(410)] for _ in range(410)]
dx: list = [-2, -2, -1, +1, +2, +2, +1, -1]
dy: list = [-1, +1, +2, +2, +1, -1, -2, -2]


def bfs():
    global step, queue, image, is_visited
    while len(queue) != 0:
        size: int = len(queue)
        for _ in range(size):
            nodex, nodey = queue.pop(0)
            image[nodex][nodey] = step
            is_visited[nodex][nodey] = True
            for j in range(8):
                nx: int = nodex+dx[j]
                ny: int = nodey+dy[j]
                if nx < 1 or nx > n or ny < 1 or ny > m:
                    continue
                if not is_visited[nx][ny]:
                    is_visited[nx][ny] = True
                    queue.append((nx, ny))
        step += 1


if __name__ == "__main__":
    n, m, x, y = map(int, input().split())
    queue.append((x, y))
    is_visited[x][y] = True
    bfs()
    for i in range(1, n+1):
        for j in range(1, m+1):
            buffer.write("%-5d " % image[i][j])
        buffer.write("\n")
    print(buffer.getvalue(), end="")
