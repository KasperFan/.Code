'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-11-18 16:00:09
LastEditTime: 2023-11-18 16:26:39
FilePath: /Python/WFUStudy/AT_abc328_c.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''
import sys
import io


def input(): return sys.stdin.readline()


buffer = io.StringIO()

ranges = [0 for _ in range(int(3e5)+10)]
N, Q = map(int, input().strip().split())
inputstr = f"_{input().strip()}"
print(inputstr)
for i in range(1, len(inputstr)-1):
    ranges[i+1] += ranges[i] + (1 if inputstr[i+1] == inputstr[i] else 0)

for i in range(Q):
    l, r = map(int, input().strip().split())
    buffer.write(f"{ranges[r]-ranges[l]}\n")
print(buffer.getvalue(), end="")
