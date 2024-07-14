'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2024-04-15 08:22:40
LastEditTime: 2024-04-15 17:18:07
FilePath: /Python/tianti/L2-003_月饼.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2024 by KasperFan in WFU, All Rights Reserved. 
'''
import os, sys, math, io, heapq, queue

input = lambda: sys.stdin.readline().strip()

buffer = io.StringIO()

N, D = map(int, input().split())
ins = [[*map(float, input().split())] for _ in range(2)]
mooncakes = sorted(zip(map(float, input().split()), map(float, input().split())), key=lambda o: o[1]/o[0], reverse=True)
income = 0

for storage, value in mooncakes:
    if D >= storage:
        D -= storage
        income += value
    else:
        income += (value/storage) * D
        break

print(f'{income:.2f}')
