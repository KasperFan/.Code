'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-10-07 22:08:34
LastEditTime: 2023-10-08 06:23:08
FilePath: /Python/OJ/7121/#653.两个数比较.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''

import sys

def input() -> str: return sys.stdin.readline()

if __name__ == "__main__":
    N: int = int(input())
    while N > 0:
        print(max([int(i) for i in input().split()]))
