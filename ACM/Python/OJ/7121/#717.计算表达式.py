'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-10-11 14:21:20
LastEditTime: 2023-10-11 14:28:31
FilePath: /Python/OJ/7121/#717.计算表达式.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''
import math

x: float
n: int


def f(x: float, n: int) -> float:
    if n == 1:
        return math.sqrt(n+x)
    else:
        return math.sqrt(n+f(x, n-1))


if __name__ == "__main__":
    li = [i for i in input().split()]
    x = float(li[0])
    n = int(li[1])
    print("%.6f" % f(x, n))
