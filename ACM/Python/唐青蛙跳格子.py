'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2024-03-31 10:40:17
LastEditTime: 2024-04-01 08:13:43
FilePath: /Python/唐青蛙跳格子.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2024 by KasperFan in WFU, All Rights Reserved. 
'''
import torch 

print(torch.backends.mps.is_available())
N = int(input())
heye = [*map(int, input().split())]
heye.sort()
avalible = {*heye}
x = int(input())
gezi = [0 for _ in range(71)]
gezi[0] = 1

def fib(n):
    global gezi
    if n in avalible:
        for i in range(1, x+1):
            if n-i in range(len(gezi)): gezi[n] += gezi[n-i]
            else: break
    else: gezi[n] = 0

for i in range(1, 71):
    fib(i)

print(gezi[heye[-1]])