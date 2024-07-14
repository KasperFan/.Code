'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-11-04 10:04:55
LastEditTime: 2023-11-04 10:29:26
FilePath: /Python/OJ/7121/第一场周赛/#C.小鑫赛马.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''
from io import StringIO

buffer = StringIO()
cnt = [0]
ans = 0
chk = [[] for _ in range(110)]
min: int = 0x4f4f4f4f

N: int = int(input())
for i in range(1, N+1):
    cnt.append(int(input()))
    chk[i] = list(map(int, input().split()))
X: int = int(input())
for i in range(1, N+1):
    if X in chk[i]:
        if cnt[i] < min:
            min = cnt[i]
            buffer.truncate(0)
            ans = 1
            buffer.write("%d " % i)
        elif cnt[i] == min:
            buffer.write("%d " % i)
            ans += 1
print(ans)
print(buffer.getvalue())
