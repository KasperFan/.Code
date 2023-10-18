'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-10-14 14:07:03
LastEditTime: 2023-10-14 14:10:22
FilePath: /Python/OJ/LuoGu/速刷(大一)/B2147_求f(x,n).py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''
from math import sqrt


def f(x: float, n: int) -> float:
    if n == 1:
        return sqrt(n + x)
    else:
        return sqrt(n+f(x, n-1))


if __name__ == "__main__":
    x, n = input().split()
    x = float(x)
    n = int(n)
    print("%.2f" % f(x, n))
