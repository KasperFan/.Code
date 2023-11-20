'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-11-04 20:28:51
LastEditTime: 2023-11-04 20:50:21
FilePath: /Python/OJ/Atcoder/HHKB_Programming_Contest_2023/B-A^A.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''
B: int = int(input())
for A in range(1, 16):
    if A**A == B:
        print(A)
        exit()
print(-1)
