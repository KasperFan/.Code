'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-10-08 20:40:38
LastEditTime: 2023-10-09 08:28:45
FilePath: /Python/OJ/7121/#729.高中数学？.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''

import sys


def input(): return sys.stdin.readline()
def print(data): return sys.stdout.write(data)


T: int
n: int
f = [0]*50


def F(n: int) -> int:
    global f
    if n == 2 and f[n] == 0:
        f[n] = 1
    elif n != 1 and f[n] == 0:
        f[n] = 4*F(n-1)-5*F(n-2)
    return f[n]


if __name__ == "__main__":
    T = int(input())
    for i in range(T):
        n = int(input())
        print("%d\n" % F(n))
