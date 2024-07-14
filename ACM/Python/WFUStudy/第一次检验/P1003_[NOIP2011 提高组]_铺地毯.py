'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-10-22 15:51:19
LastEditTime: 2023-10-22 16:51:58
FilePath: /Python/WFUStudy/第一次检验/P1003_[NOIP2011 提高组]_铺地毯.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''
from sys import stdin
def input(): return stdin.readline()


ans = -1
blankets = [[0]]

if __name__ == "__main__":
    n: int = int(input())
    for i in range(n):
        a, b, g, k = map(int, input().split())
        blankets.append([a, b, g, k])
    x, y = map(int, input().split())
    for i in range(1, n+1):
        if (x >= blankets[i][0] and x <= blankets[i][0]+blankets[i][2]-1) and (y >= blankets[i][1] and y <= blankets[i][1]+blankets[i][3]-1):
            ans = i
    print(ans)
