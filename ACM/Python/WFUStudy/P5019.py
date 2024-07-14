'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-11-18 17:24:06
LastEditTime: 2023-11-18 17:31:33
FilePath: /Python/WFUStudy/P5019.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''
from sys import *


def input(): return stdin.readline()


ans: int = 0
n: int = int(input())
a: list[int] = [int(i) for i in input().strip().split()]
for i in range(1, len(a)):
    if a[i] > a[i-1]:
        ans += a[i]-a[i-1]
print(f"{ans+a[1]}")
