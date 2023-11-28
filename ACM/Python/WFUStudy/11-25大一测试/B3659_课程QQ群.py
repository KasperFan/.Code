'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-11-26 20:00:26
LastEditTime: 2023-11-26 20:02:55
FilePath: /Python/WFUStudy/11-25大一测试/B3659_课程QQ群.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''
from sys import stdin


def input(): return stdin.readline().strip()


chk = [0 for _ in range(int(1e4)+10)]

n, k = map(int, input().split())
for _ in range(n):
    chk[int(input())] += 1
print(chk[k])
