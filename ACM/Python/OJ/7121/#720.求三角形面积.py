'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-10-11 15:27:44
LastEditTime: 2023-10-11 15:36:08
FilePath: /Python/OJ/7121/#720.求三角形面积.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''
import math


def getArea(a: float, b: float, c: float) -> float:
    p: float = (a+b+c)/2
    return math.sqrt(p*(p-a)*(p-b)*(p-c))


if __name__ == "__main__":
    a, b, c = map(float, input().split())
    print("%.4f" % getArea(a, b, c))
