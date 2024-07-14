'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2024-01-19 14:14:12
LastEditTime: 2024-01-20 19:37:32
FilePath: /Python/辅导/T0123PC02.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2024 by KasperFan in WFU, All Rights Reserved. 
'''
from sys import stdin


def input(): return stdin.readline().strip()


chk = dict(zip([1, 2, 3, 4], ['A', 'B', 'C', 'D']))
print(chk.get(int(input())))
