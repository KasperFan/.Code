'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-10-12 22:43:09
LastEditTime: 2023-10-12 22:50:41
FilePath: /Python/OJ/LuoGu/速刷(大一)/Goals_of_Victory.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''
import sys, io


def input(): return sys.stdin.readline()


buffer = io.StringIO()
t: int
n: int

if __name__ == "__main__":
    t = int(input())
    for i in range(t):
        n = int(input())
        buffer.write("%d\n" % (-sum([int(j) for j in input().split()])))
        # ans = sum([int(j) for j in input().split()])
    print(buffer.getvalue(), end="")
