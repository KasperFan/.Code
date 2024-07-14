'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2024-04-12 22:52:48
LastEditTime: 2024-04-12 23:04:06
FilePath: /Python/算法/快速幂/P1226_快速幂.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2024 by KasperFan in WFU, All Rights Reserved. 
'''
import os, sys

input = lambda: sys.stdin.readline().strip()

def FastMi(a: int, b: int, p: int) -> int:
    r = 1
    while b:
        if b & 1 : r = (r * a) % p
        a = (a * a) % p
        b >>= 1
    return r


a, b, p = map(int, input().split())
print("%d^%d mod %d=%d" % (a, b, p, FastMi(a, b, p)))
