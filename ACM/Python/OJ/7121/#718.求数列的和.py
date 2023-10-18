'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-10-11 14:30:46
LastEditTime: 2023-10-11 14:51:15
FilePath: /Python/OJ/7121/#718.求数列的和.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''
import sys, math, io

n: int
m: int
ans: float = 0.0
buffer = io.StringIO()

def getSum(n: float, m: int) -> float:
    if m == 1:
        return n
    else:
        return n + getSum(math.sqrt(n), m-1)


if __name__ == "__main__":
    for line in sys.stdin:
        try:
            n, m = map(int, line.split())
            buffer.write("%.6f\n" % getSum(n, m))
        except ValueError:
            break
    print(buffer.getvalue())
