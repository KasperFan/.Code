'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-11-05 17:50:07
LastEditTime: 2023-11-05 17:55:35
FilePath: /Python/WFUStudy/摸底/P1216_数字三角形_Number_Triangles.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''

r: int
triangles: list[list[int]]
r = int(input())
triangles = [[int(i) for i in input().split()] for _ in range(r)]
for i in range(len(triangles) -2, -1, -1):
    for j in range(len(triangles[i])):
        triangles[i][j] += max(triangles[i+1][j],triangles[i+1][j+1])
print(triangles[0][0])