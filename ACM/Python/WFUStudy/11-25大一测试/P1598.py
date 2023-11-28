'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-11-26 20:04:02
LastEditTime: 2023-11-26 20:31:43
FilePath: /Python/WFUStudy/11-25大一测试/P1598.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''
import sys, io


def input(): return sys.stdin.readline().strip()


buffer = io.StringIO()


cnt = [0 for _ in range(30)]
max = 0
A = ord('A')
Z = ord('Z')

for _ in range(4):
    for ch in input():
        num = ord(ch)
        if num in range(A, Z+1):
            cnt[num-A] += 1
for i in cnt:
    max = i if i > max else max
for i in range(max, 0, -1):
    for j in range(26):
        if cnt[j] == i:
            buffer.write("*")
            cnt[j] -= 1
        else:
            buffer.write(" ")
        if j in range(25):
            buffer.write(" ")
    buffer.write("\n")
for i in range(26):
    buffer.write(f"{chr(i+A)}")
    if i in range(25):
        buffer.write(" ")
print(buffer.getvalue())
