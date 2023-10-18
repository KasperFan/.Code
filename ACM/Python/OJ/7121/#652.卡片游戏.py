'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-10-07 20:36:21
LastEditTime: 2023-10-07 21:40:51
FilePath: /Python/OJ/7121/#652.卡片游戏.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''
import sys


def input() -> str: return sys.stdin.readline()


if __name__ == "__main__":
    n: int = int(input())
    a = [int(i) for i in input().split()]
    cnt: int = 0
    for i in range(n):
        if i % 2 == 0:
            cnt += a[i]
        else:
            cnt -= a[i]
    if cnt > 0:
        print("Greater than")
    elif cnt < 0:
        print("Less than")
    else:
        print("Equal")
