'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-10-11 14:54:49
LastEditTime: 2023-10-11 15:10:31
FilePath: /Python/OJ/7121/#719.一元二次方程Ⅰ.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''
import math


def getRoot(a: int, b: int, c: int) -> tuple:
    delta: int = b**2-4*a*c
    if delta == 0:
        return ((-b)/(2*a), (-b)/(2*a))
    else:
        return ((-b+math.sqrt(delta))/(2*a), (-b-math.sqrt(delta))/(2*a))


if __name__ == "__main__":
    a, b, c = map(int, input().split())
    first: bool = True
    for i in getRoot(a, b, c):
        print("%.6f" % i, end=(" " if first else "\n"))
        first = not first
