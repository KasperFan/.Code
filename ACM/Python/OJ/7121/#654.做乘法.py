'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-10-08 06:31:18
LastEditTime: 2023-10-08 06:35:35
FilePath: /Python/OJ/7121/#654.做乘法.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''

import sys


def input(): return sys.stdin.readline()
def print(data): return sys.stdout.write(data)


if __name__ == "__main__":
    N: int = int(input())
    for i in range(1, N+1):
        print("%d*%d=%d\n" % (N, i, N*i))
