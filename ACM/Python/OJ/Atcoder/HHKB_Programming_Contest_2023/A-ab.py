'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-11-04 20:20:18
LastEditTime: 2023-11-04 20:26:12
FilePath: /Python/OJ/Atcoder/HHKB_Programming_Contest_2023/A-ab.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''

N: int = int(input())
S: str = input()
for i in range(len(S)):
    if S[i] == 'a':
        if i+1 >= N:
            break
        elif S[i+1] == 'b':
            print("Yes")
            exit()
    elif S[i] == 'b':
        if i+1 >= N:
            break
        elif S[i+1] == 'a':
            print("Yes")
            exit()
print("No")
