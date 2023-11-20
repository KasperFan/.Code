'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-11-04 20:54:34
LastEditTime: 2023-11-04 21:10:23
FilePath: /Python/OJ/Atcoder/HHKB_Programming_Contest_2023/C-Number_Place.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''
c: list = [1, 4, 7]
dx: list = [-1, -1, -1, 0, 0, +1, +1, +1]
dy: list = [-1, 0, +1, -1, +1, -1, 0, +1]
grid = [[int(i) for i in input().split()] for _ in range(9)]
sets: set
for i in range(9):
    sets = set(grid[i])
    if len(sets) != 9:
        print("No")
        exit()
for i in range(9):
    sets = set()
    for j in range(9):
        sets.add(grid[j][i])
    if len(sets) != 9:
        print("No")
        exit()
for i in c:
    for j in c:
        sets = set()
        sets.add(grid[i][j])
        for k in range(8):
            sets.add(grid[i+dx[k]][j+dy[k]])
        if len(sets) != 9:
            print("No")
            exit()
print("Yes")
