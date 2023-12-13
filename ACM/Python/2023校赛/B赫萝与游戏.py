'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-12-07 18:58:01
LastEditTime: 2023-12-08 00:14:53
FilePath: /Python/2023校赛/B赫萝与游戏.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''
import sys, io


def input(): return sys.stdin.readline().strip()


buffer = io.StringIO()

T = int(input())
for _ in range(T):
    n, k = map(int, input().split())
    inpu = input()
    cnk = 0
    for i in range(n//2):
        if inpu[i] != inpu[n-1-i]: cnk += 1
    if k < cnk: buffer.write("No\n")
    else: buffer.write("Yes\n")
print(buffer.getvalue(), end="")
