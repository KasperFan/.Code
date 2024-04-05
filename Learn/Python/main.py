# -*- coding: utf-8 -*-
# @FileCreateTime    : 2024/1/14 12:58
# @Author            : kasperfan
# @Site              : 
# @File              : main.py
# @Path              : 
# @Software          : PyCharm 
# @Comment           :
'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2024-01-06 14:38:09
LastEditTime: 2024-01-14 12:55:48
FilePath: /Python/main.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2024 by KasperFan in WFU, All Rights Reserved.
'''
# 快读，快写导入
import sys, io


def input(): return sys.stdin.readline().strip()


buffer = io.StringIO()  # 输出缓冲区buffer

n: int; m: int; x: int; y: int
# 步数变量step，队列queue，地图image，访问标记is_visited和坐标偏移列表dx，dy
step: int = 0
queue: list = []
# 若某个点走不到，则它不会被遍历到，仍为-1
image: list = [[-1 for _ in range(410)] for _ in range(410)]
is_visited: list = [[False for _ in range(410)] for _ in range(410)]
dx: list = [-2, -2, -1, +1, +2, +2, +1, -1]
dy: list = [-1, +1, +2, +2, +1, -1, -2, -2]


def main():
    global n, m, x, y, buffer
    n, m, x, y = map(int, input().split())  # 棋盘大小和起点坐标
    bfs()  # 开搜
    # 搜完后遍历整个棋盘
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            buffer.write("%-5d" % image[i][j])  # 将第i行中每一列的值按照要求写入buffer
        buffer.write("\n")  # 写完一行后再写入一个换行符
    print(buffer.getvalue(), end="")  # 最后将整个结果直接输出


def bfs():
    global step, queue, image, is_visited
    # 将起点置入队列
    is_visited[x][y] = True
    queue.append((x, y))
    # 只要队列不为空就一直处理
    while len(queue) != 0:
        size: int = len(queue)  # 记录当前阶段所有点的个数size
        for _ in range(size):  # 循环size次
            # 每次取出队列中的第一个点(nodex, nodey)
            nodex, nodey = queue.pop(0)
            # 在地图上当前点的记录更新（因为只会遍历到该点一次，所以该点的值就是从起点到它的最少步数）
            image[nodex][nodey] = step
            is_visited[nodex][nodey] = True
            for j in range(8):  # 枚举8个方向的下一阶段新点
                nx: int = nodex + dx[j]
                ny: int = nodey + dy[j]
                # 边界判断
                if nx < 1 or nx > n or ny < 1 or ny > m: continue
                # 访问标记判断，如果没有走过，修改其访问标记并将其置入队列末
                if not is_visited[nx][ny]:
                    is_visited[nx][ny] = True
                    queue.append((nx, ny))
        step += 1  # 处理完当前步的点，步数+1


if __name__ == "__main__":
    main()
