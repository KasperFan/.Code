'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2024-03-10 14:14:21
LastEditTime: 2024-03-10 16:03:48
FilePath: /Python/WFUStudy/新学期新气象/P9240.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2024 by KasperFan in WFU, All Rights Reserved. 
'''
import gc
from sys import stdin
from io import StringIO

input = lambda: stdin.readline().strip()
buffer = StringIO()

class Lian():
    def __init__(self, A, B) -> None:
        self.A, self.B = A, B
        self.low, self.high = A//(B+1)+1, A//B+1

min_ans = 0x4f4f4f4f4f

gc.enable()
N = int(input())
lians = [Lian(*map(int, input().split())) for _ in range(N)]
ans_set = lians[0].V
for i in range(1, len(lians)):
    ans_set = ans_set & lians[i].V
lians = None
gc.collect()
ans = [i for i in ans_set]
ans.sort()
print(ans[0], ans[-1])
