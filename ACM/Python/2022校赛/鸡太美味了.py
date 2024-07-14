'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-12-05 11:37:07
LastEditTime: 2023-12-05 15:24:38
FilePath: /11.22晚大一速刷/2022校赛/鸡太美味了.py
describes: This file is created for learning Code.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''
from sys import stdin
from io import StringIO
from math import *

def input(): return stdin.readline().strip()

buffer = StringIO()

def is_prime(num: int) -> bool:
    if num == 1: return False
    if num == 2 or num == 3 or num == 5 or num == 7: return True
    if num % 2 == 0 or num % 3 == 0 or num % 5 == 0 or num % 7 == 0: return False
    for i in range(11, int(sqrt(num))+1, 2):
        if num % i == 0: return False
    return True

def main():
    n = int(input())
    x = list(map(int, input().split()))
    print(x)
    for i in x:
        froot = sqrt(i)
        iroot = int(froot)
        if (froot - iroot == 0) and is_prime(iroot):
            buffer.write("YES\n")
        else: buffer.write("NO\n")
    print(buffer.getvalue(), end="")

if __name__ == "__main__":
    main()
