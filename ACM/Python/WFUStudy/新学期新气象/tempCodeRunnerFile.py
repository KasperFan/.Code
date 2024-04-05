'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2024-03-10 15:04:32
LastEditTime: 2024-03-10 15:35:56
FilePath: /Python/WFUStudy/新学期新气象/P1048.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2024 by KasperFan in WFU, All Rights Reserved. 
'''
import numpy as np
from array import array
from sys import stdin
from io import StringIO

input = lambda: stdin.readline().strip()
buffer = StringIO()


class Perl():
    def __init__(self, time , value) -> None:
        self.time, self.value = time, value
        pass

T, M = map(int, input().split())
dp = array('i', [0]*(T+1))
perls = [Perl(*map(int, input().split())) for _ in range(M)]
for i in range(M):
    for j in range(perls[i].time, T+1):
        dp[j] = max(dp[j], dp[j-perls[i].time]+perls[i].value)
print(dp[T])

