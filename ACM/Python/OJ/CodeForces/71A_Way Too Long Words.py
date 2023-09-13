'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-03-18 01:40:58
LastEditTime: 2023-03-18 01:45:54
FilePath: /ACM/Python/CodeForces/71A_Way Too Long Words.py
Description: This file is created for learning Code.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''
n = int(input())
words = []

for i in range(n):
    words.append(input())
    if len(words[i]) > 10:
        words[i] = (
            f"{words[i][0]}{len(words[i])-2}{words[i][len(words[i])-1]}")

for i in words:
    print(i)
