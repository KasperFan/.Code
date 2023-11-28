'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-11-26 17:02:42
LastEditTime: 2023-11-26 17:40:18
FilePath: /Python/WFUStudy/P3799妖梦拼木棒.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''
import sys

sys.stdin = open("./P3799_4.in", mode="r")
sys.stdout = open("./P3799.out", mode="w+")

def input(): return sys.stdin.readline().strip()


num = [0 for _ in range(int(5e3)+1)]
mod = int(1e9 + 7)
maxLength = 0
ans = 0

n = int(input())
for line in sys.stdin.readlines():
    i = int(line.strip())
    num[i]+=1
    maxLength = i if i > maxLength else maxLength
for long in range(2, maxLength+1):
    if num[long] >= 2:
        condi_1 = num[long] * (num[long]-1) // 2
        for short in range(1, int(long/2+1)):
            if short == long/2 and num[short] >= 2:
                ans += condi_1 * (num[short] * (num[short]-1)//2)
            elif short != long/2 and num[short] > 0 and num[long-short] > 0:
                ans += condi_1 * num[short] * num[long-short]
print(ans % mod)
