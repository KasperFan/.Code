'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-10-11 15:51:28
LastEditTime: 2023-10-11 16:15:40
FilePath: /Python/OJ/7121/#722.歌德巴赫猜想的证明.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''
isPrime: list = [True]*100001

if __name__ == "__main__":
    n: int = int(input())
    cnt: int = 0
    for i in range(2, n):
        if not isPrime[i]:
            continue
        for j in range(2, n//i + 1):
            isPrime[i*j] = False
    for i in range(2, n):
        if isPrime[i] and isPrime[n-i]:
            print("%d %d" % (i, n-i))
            break
