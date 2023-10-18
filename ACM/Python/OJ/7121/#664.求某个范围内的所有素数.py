'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-10-10 14:59:13
LastEditTime: 2023-10-10 15:21:36
FilePath: /Python/OJ/7121/#664.求某个范围内的所有素数.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''
import io
buffer = io.StringIO()
isPrime: list = [True]*10001

if __name__ == "__main__":
    n: int = int(input())
    cnt: int = 0
    for i in range(2, n):
        if not isPrime[i]:
            continue
        for j in range(2, n//i + 1):
            isPrime[i*j] = False
    for i in range(2, n):
        if isPrime[i]:
            buffer.write("%d" % i)
            cnt += 1
            if cnt % 10 != 0:
                buffer.write(" ")
            else:
                buffer.write("\n")
    print(buffer.getvalue())
    buffer.close()
