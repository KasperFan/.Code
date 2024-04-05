'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2024-01-19 15:33:42
LastEditTime: 2024-01-19 15:39:58
FilePath: /Python/辅导/0123PC03.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2024 by KasperFan in WFU, All Rights Reserved. 
'''
from sys import stdin
from math import log10


input = lambda: stdin.readline().strip()


n = int(input())
print("Y" if int(n ** 2) % (10 ** int(log10(n)+1)) == n else "N")
