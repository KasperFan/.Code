'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-10-13 12:01:14
LastEditTime: 2023-10-13 12:07:20
FilePath: /Python/OJ/LuoGu/速刷(大一)/B2129_最大数_max(x,y,z).py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''


def max(a: int, b: int, c: int) -> int:
    if a > b:
        if a > c:
            return a
        else:
            return c
    else:
        if b > c:
            return b
        else:
            return c


a, b, c = map(int, input().split())
m: float = max(a, b, c)/(max(a+b, b, c)*max(a, b, b+c))
print("%.3f" % m)
