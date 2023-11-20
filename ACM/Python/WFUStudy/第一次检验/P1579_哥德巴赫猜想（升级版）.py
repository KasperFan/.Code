'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-10-22 14:19:22
LastEditTime: 2023-10-22 14:30:47
FilePath: /Python/WFUStudy/第一次检验/P1579_哥德巴赫猜想（升级版）.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''
from math import sqrt

def isPrime(n: int) -> bool:
    root: float = sqrt(n)
    if root == int(root):
        return False
    for i in range(2, int(root)+1):
        if n % i == 0:
            return False
    return True

def ans(n: int) -> list:
    for i in range(2,n):
        if not isPrime(i):
            continue
        for j in range(2,n):
            if not isPrime(j):
                continue
            k: int = n-i-j
            if isPrime(k):
                return [i,j,k]
    return []

if __name__ == "__main__":
    n: int = int(input())
    res = ans(n)
    while len(res) > 1:
        print(res.pop(0), end=" ")
    print(res.pop())
