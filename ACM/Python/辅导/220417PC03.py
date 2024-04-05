'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2024-01-19 13:06:01
LastEditTime: 2024-01-19 13:08:30
FilePath: /Python/辅导/220417PC03.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2024 by KasperFan in WFU, All Rights Reserved. 
'''
from sys import stdin

input = lambda: stdin.readline().strip()

ans = 0
N = int(input())
blocks = list(map(int, input().split(',')))
blocks.sort()
while N > 0: N -= blocks.pop(); ans += 1
print(ans)
