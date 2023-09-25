'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-09-10 19:40:56
LastEditTime: 2023-09-12 20:36:20
FilePath: /Python/WFUStudy/Day9.5虚衷/B3725:M_Function_G.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''


def floor(x: float) -> int:
    return int(x)


def amax(l: int, r: int) -> int:
    global a
    a_max = 0
    for i in range(l, r+1):
        a_max = a_max if a_max > a[i] else a[i]
    return a_max


def M(l: int, r: int) -> int:
    global a
    if abs(r-l) <= 5:
        return amax(l, r)
    else:
        return (M(l, floor((l+r)/2)) % max(M(floor((l+r)/2)+1, r), 7))+(a[floor((l+r)/2)]-1)


if __name__ == "__main__":
    n = int(input())
    a = []
    a.append("")
    for i in input().split():
        a.append(int(i))
    print(M(1, n))
