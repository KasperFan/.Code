'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-10-28 16:35:13
LastEditTime: 2023-10-29 10:22:19
FilePath: /Python/OJ/LuoGu/搜索/P2036_PERKET.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''
import sys, math
def input(): return sys.stdin.readline()


n: int
# doses: list
S: int = 1
B: int = 0
ans: int = 0x4f4f4f4f
s: list
b: list


# class Dose:
#     def __init__(self, s: int, b: int) -> None:
#         self.s: int = s
#         self.b: int = b


def dfs(which: int):
    global ans, S, B
    # if which > n:
    #     return
    for i in range(which+1, n+1):
        S *= s[i]
        B += b[i]
        ans = int(math.fabs(S-B)) if int(math.fabs(S-B)) < ans else ans
        dfs(i)
        S //= s[i]
        B -= b[i]


if __name__ == "__main__":
    n = int(input())
    s = [0]*(n+1)
    b = [0]*(n+1)
    for i in range(1, n+1):
        s[i], b[i] = map(int, input().split())
        # doses = [0]+[Dose(*map(int, input().split())) for i in range(n)]
    dfs(0)
    print(ans)
