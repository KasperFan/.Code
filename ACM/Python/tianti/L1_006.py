'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-08-06 15:39:59
LastEditTime: 2024-04-15 18:58:37
FilePath: /Python/tianti/L1_006.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2024 by KasperFan in WFU, All Rights Reserved. 
'''
import os, sys, math, io, heapq, queue

input = lambda: sys.stdin.readline().strip()

buffer = io.StringIO()

q = []

def dfs(start, mul):
    for i in range(start+1, int(math.sqrt(N))):
        if N // (mul*i) > start:
            dfs(i)
    pass

N = int(input())