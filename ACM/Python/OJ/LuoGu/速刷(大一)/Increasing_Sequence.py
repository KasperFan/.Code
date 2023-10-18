'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-10-12 23:44:41
LastEditTime: 2023-10-13 00:02:24
FilePath: /Python/OJ/LuoGu/速刷(大一)/Increasing_Sequence.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''
import sys
def input(): return sys.stdin.readline()


if __name__ == "__main__":
    n, d = map(int, input().split())
    ans: int = 0
    b = [0] + [int(i) for i in input().split()]
    for i in range(2, len(b)):
        if b[i] > b[i-1]:
            continue
        # while b[i] <= b[i-1]:
        #     b[i] += d
        #     ans += 1
        else:
            step: int = (b[i-1]-b[i])//d + 1
            b[i] += step*d
            ans += step
    print(ans)
