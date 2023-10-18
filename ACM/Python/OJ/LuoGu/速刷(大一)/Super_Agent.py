'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-10-13 00:22:13
LastEditTime: 2023-10-13 01:02:22
FilePath: /Python/OJ/LuoGu/速刷(大一)/Super_Agent.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''
import sys
def input(): return sys.stdin.readline()


matrix = []
ans: bool = True
dx: list = [-1, -1, -1, 0]
dy: list = [-1, 0, 1, -1]

if __name__ == "__main__":
    try:
        matrix: list = [[0, 0, 0, 0, 0]] + \
            [([0] + [i for i in input()]) for n in range(3)]
            # [([0] + [i for i in line]) for line in sys.stdin]
    except ValueError:
        pass
    for i in range(len(dx)):
        ans = matrix[2+dx[i]][2+dy[i]] == matrix[2-dx[i]][2-dy[i]]
        if not ans:
            break
    print(('YES' if ans else "NO"))
