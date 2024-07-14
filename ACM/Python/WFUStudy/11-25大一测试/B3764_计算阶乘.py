'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-11-26 16:02:36
LastEditTime: 2023-11-26 19:40:09
FilePath: /Python/WFUStudy/11-25大一测试/B3764_计算阶乘.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''
from io import StringIO
from sys import stdin


def input(): return stdin.readline().strip()


def cal(n: int) -> int:
    global n_multy
    if n in (0, 1, 2):
        return n_multy[n]
    if n_multy[n] != 0:
        return n_multy[n]
    else:
        n_multy[n] = (n-1)*cal(n-1)
        return n_multy[n]


buffer = StringIO()

n_multy = [0 for _ in range(35)]
n_multy[1] = n_multy[2] = 1


if __name__ == "__main__":
    T = int(input())
    for i in range(T):
        # buffer.write("%d\n" % (2 * cal(int(input()))))
        print("%d" % (2 * cal(int(input()))))
    # print(buffer.getvalue(), end="")
