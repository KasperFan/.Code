'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-10-08 06:54:45
LastEditTime: 2023-10-08 06:59:26
FilePath: /Python/OJ/7121/#656.猜糖块.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''

import sys


def input(): return sys.stdin.readline()
def print(data): return sys.stdout.write(data)


if __name__ == "__main__":
    N: int = int(input())
    total: int = 0
    days: int = 0
    while total <= N:
        days += 1
        total += days*days
    days -= 1
    print("%d\n" % days)
