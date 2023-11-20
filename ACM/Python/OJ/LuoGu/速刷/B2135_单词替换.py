'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-10-19 00:06:10
LastEditTime: 2023-10-20 00:28:18
FilePath: /Python/OJ/LuoGu/速刷/B2135_单词替换.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''
s: str = input()
a: str = input()
b: str = input()
temp = s.split()
ans = []
for i in temp:
    ans.append(i if i != a else b)
for i in ans:
    print(i, end=" ")

# I want someone to help you
# I
# You
