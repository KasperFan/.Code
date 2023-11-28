'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-11-26 19:45:33
LastEditTime: 2023-11-26 23:56:28
FilePath: /Python/WFUStudy/11-25大一测试/P9581「MXOI_Round_1」宝箱.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''
from io import StringIO
from sys import stdin


def input(): return stdin.readline().strip()

a, b = map(int, input().split())
if a > b:
    a ^= b
    b = a^b
    a ^= b
if 0 in range(a, b+1):
    print(min(abs(a), abs(b))+b-a)
elif a > 0:
    print(b)
else:
    print(abs(a))
