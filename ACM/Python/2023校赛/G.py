'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-12-07 20:51:20
LastEditTime: 2023-12-10 14:49:35
FilePath: /Python/2023校赛/G.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''
from math import gcd
from io import StringIO


with StringIO() as buffer:
    T = int(input())
    for _ in range(T):
        x, y = map(int, input().split())
        allcnt = (x+y)*(x+y-1)//2
        cocnt = x*(x-1)//2
        gc = gcd(allcnt, cocnt)
        buffer.write("%d/%d\n" % (cocnt/gc, allcnt/gc))
    print(buffer.getvalue(), end="")
