'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2024-01-19 09:18:49
LastEditTime: 2024-01-19 15:27:54
FilePath: /Python/辅导/2208PC05.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2024 by KasperFan in WFU, All Rights Reserved. 
'''
from sys import stdin

input=lambda: stdin.readline().strip()

dp = [[0 for _ in range(100)] for _ in range(100)]
N, M = map(int, input().split(','))
grid = [list(map(int, input().split(','))) for _ in range(N)]
for i in range(N):
    for j in range(M):
        if i == 0 and j == 0: dp[i][j] = grid[i][j]
        elif i == 0: dp[i][j] = grid[i][j] + dp[i][j-1]
        elif j == 0: dp[i][j] = grid[i][j] + dp[i-1][j]
        else: dp[i][j] = grid[i][j] + min(dp[i][j-1], dp[i-1][j])
print(dp[N-1][M-1])
