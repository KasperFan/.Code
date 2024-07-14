'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2024-01-19 08:40:19
LastEditTime: 2024-01-19 08:57:48
FilePath: /Python/辅导/0123PC05.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2024 by KasperFan in WFU, All Rights Reserved. 
'''
from sys import stdin

input=lambda: stdin.readline().strip()

m, n = map(int, input().split(','))
volume = [0]+list(map(int, input().split(',')))
value = [0]+list(map(int, input().split(',')))
dp = [[0 for _ in range(m+1)] for _ in range(n+1)]
for i in range(1, n+1):
    for j in range(m, volume[i]-1, -1):
        dp[i][j] = max(dp[i-1][j], dp[i-1][j-volume[i]]+value[i])
print(dp[n][m])
