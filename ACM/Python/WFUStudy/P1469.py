'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-11-18 15:48:44
LastEditTime: 2023-11-21 14:54:57
FilePath: /Python/WFUStudy/P1469.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''
import sys, os


def input(): return sys.stdin.readline()


n: int
ans: int = 0
i = 0
s = ''

n = int(input())
fr = os.dup(0)
os.set_blocking(fr, False)
while i < n:
    c = os.read(fr, 1).decode('utf-8')
    if c in [" ", "\n"]:
        x = int(s)
        ans ^= x
        s = ""
        i += 1
    else:
        s += c

print(ans)
