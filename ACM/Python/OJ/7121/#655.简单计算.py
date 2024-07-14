'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-10-08 06:39:19
LastEditTime: 2023-10-08 06:43:53
FilePath: /Python/OJ/7121/#655.简单计算.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''

import sys


def input(): return sys.stdin.readline()
def print(data): return sys.stdout.write(data)

if __name__ == "__main__":
    n: int = int(input())
    a:list = [int(i) for i in input().split()]
    print("%d %d %d\n" % (max(a), min(a), sum(a)//n))