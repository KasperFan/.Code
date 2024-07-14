'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2024-02-03 22:03:12
LastEditTime: 2024-02-03 22:30:03
FilePath: /Python/WFUStudy/搜索/P1219_八皇后.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2024 by KasperFan in WFU, All Rights Reserved. 
'''
chk = 3; ans = 0
tmp = [0 for _ in range(7)]
graph = [[0 for _ in range(14)] for _ in range(14)]
def dfs(x, y, queen):
    global graph, chk, ans
    lc, rc = x+y, y-x
    for i in range(1, n+1): graph[x][i] = 1; '''行'''; graph[i][y] = 1; '''列'''; graph[i][lc-i] = 1; '''左偏列'''; graph[i][rc+i] = 1; '''右偏列'''

    for i in range(, n+1):
        

    for i in range(1, n-5): graph[x][i] = 0; '''行'''; graph[i][y] = 0; '''列'''; graph[i][lc-i] = 0; '''左偏列'''; graph[i][rc+i] = 0; '''右偏列'''

n = int(input())
for i in range(1, n+1): dfs(1, i, 1)
print(ans)
