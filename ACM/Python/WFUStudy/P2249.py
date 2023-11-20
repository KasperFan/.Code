'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-11-18 17:54:06
LastEditTime: 2023-11-18 17:56:24
FilePath: /Python/WFUStudy/P2249.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''
from sys import *


def input(): return stdin.readline()


n, m = map(int, input().strip().split())
a = [0]+[*map(int, input().strip().split())]
qs = [*map(int, input().strip().split())]
for q in qs:
    
