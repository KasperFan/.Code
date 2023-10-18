'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-10-11 20:57:23
LastEditTime: 2023-10-12 22:28:52
FilePath: /Python/OJ/7121/#833.【模板】前缀和.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''
import sys
import io


def input(): return sys.stdin.readline()


buffer = io.StringIO()
n: int
m: int
l: int
r: int

if __name__ == "__main__":
    n, m = map(int, input().split())
    num = [0] + [int(i) for i in input().split()]
    sum = [0] * len(num)
    for i in range(1, len(num)):
        sum[i] = num[i]+sum[i-1]
    for i in range(m):
        l, r = map(int, input().split())
        if l <= r:
            buffer.write("%d\n" % (sum[r]-sum[l-1]))
        else:
            buffer.write("%d\n" % (sum[l]-sum[r-1]))
    print(buffer.getvalue(), end="")
