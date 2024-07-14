'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-11-05 14:55:29
LastEditTime: 2023-11-05 14:59:18
FilePath: /Python/WFUStudy/摸底/P1781_宇宙总统.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''
n = int(input())
max = 0
id = 0
tik = [0]+[int(input()) for _ in range(n)]
for i in range(1, n+1):
    if tik[i] > max:
        max = tik[i]
        id = i
print("%d\n%d" % (id, max))
