'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2024-03-09 21:04:55
LastEditTime: 2024-03-09 21:26:24
FilePath: /Python/ATCoder/24.3.9/E.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2024 by KasperFan in WFU, All Rights Reserved. 
'''
from sys import stdin
from io import StringIO

input = lambda: stdin.readline().strip()

buffer = StringIO()

def remove(x):
    global A, indexs
    A.pop(indexs[x])
    indexs[x] = -1

def insert(x, y):
    global A, indexs
    A.insert(indexs[x]+1, y)
    indexs[y] = indexs[x]+2
    for i in range(indexs[x], len(A)):
        indexs[A[i]] = i

N = int(input())
A = [*map(int, input().split())]
indexs = {A[i]:i for i in range(len(A))}
Q = int(input())
for _ in range(Q):
    temp = [*map(int, input().split())]
    if len(temp) == 2:
        x = temp[-1]
        remove(x)
    else:
        x, y = tuple(temp[1:])
        insert(x, y)
for i in A: buffer.write("%d " % i)
print(buffer.getvalue())