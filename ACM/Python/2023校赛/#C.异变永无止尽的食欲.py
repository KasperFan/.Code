'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-12-07 21:06:49
LastEditTime: 2023-12-07 21:28:28
FilePath: /Python/2023校赛/#C.异变永无止尽的食欲.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''
import sys


def input(): return sys.stdin.readline().strip()

ans = cnt = 0

def dfs(start: int, step: int):
    global ans, cnt
    if step > n: ans += cnt; return
    for i in range(step+1, n+1):
        cnt += a[step]
        dfs(start, i)
        cnt -= a[step]
    ans+=cnt

n = int(input())
a = [0]+list(map(int, input().split()))+[0]
for i in range(1, n+1):
    dfs(i,i)
print(ans)