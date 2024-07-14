'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-12-07 19:30:02
LastEditTime: 2023-12-07 20:47:45
FilePath: /Python/2023校赛/I-连一刻都没有猫雷而哀悼.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''
import sys

def input(): return sys.stdin.readline().strip()


n, m = map(int, input().split())
img = [list(map(int, input().split())) for _ in range(n)]
ans = 0
chk = [-1 for _ in range(1010)]
minist = [10010 for _ in range(1010)]
check = 0
for i in range(n):
    cy = -1
    for j in range(m):
        if minist[i] == img[i][j]: check += 1
        elif minist[i] > img[i][j]: minist[i] = img[i][j]; cy = j; check = 1
    if check == 1: chk[i] = cy

for i in range(n):
    if chk[i] == -1: continue
    check = 0
    for j in range(n):
        if check >= 2: break
        if minist[i] == img[j][chk[i]]: check += 1
        elif minist[i] > img[j][chk[i]]: break
    if check == 1: ans += 1
print(ans)