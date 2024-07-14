'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2024-04-11 20:14:56
LastEditTime: 2024-04-11 20:15:01
FilePath: /Python/蓝桥杯/堆排序.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2024 by KasperFan in WFU, All Rights Reserved. 
'''
import os
import sys

import heapq


def solve():
    n = int(input())
    q = []
    for _ in range(n):
        op = input().split()
        if op[0] == "push":
            x = int(op[1])
            heapq.heappush(q, x)
        elif op[0] == "remove":
            if not q:
                print("empty")
            else:
                heapq.heappop(q)
        elif op[0] == "min":
            if not q:
                print("empty")
            else:
                print(q[0])
        else:
            k = int(op[1])
            res = []
            for _ in range(k):
                res.append(str(heapq.heappop(q)))
            print(" ".join(res))

# def main():
#     t = 1
#     for _ in range(t):
#         solve()


if __name__ == "__main__":
    solve()
