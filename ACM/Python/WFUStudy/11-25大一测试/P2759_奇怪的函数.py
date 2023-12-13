'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-11-28 19:11:27
LastEditTime: 2023-11-29 14:37:30
FilePath: /Python/WFUStudy/11-25大一测试/P2759_奇怪的函数.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''
from math import log10


def len(x: int) -> int:
    return int(x * log10(x) + 1)


def main() -> None:
    n: int = int(input())
    if n == 1: print(n); return
    low: int = 0
    high: int = n
    while low < high:
        mid = (low+high)//2
        if len(mid) < n: low = mid + 1
        else: high = mid
    print(low)


if __name__ == "__main__":
    main()
