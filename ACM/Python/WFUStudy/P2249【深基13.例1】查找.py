'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-11-21 21:17:17
LastEditTime: 2023-11-22 17:31:06
FilePath: /Python/WFUStudy/P2249【深基13.例1】查找.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''

import sys, io


def input(): return sys.stdin.readline().strip()


# def foldSearch(element: int, l: int, r: int) -> int:
#     if l >= r:
#         if a[l] == element:
#             return l
#         else:
#             return -1
#     mid: int = (l+r)//2
#     if element >= a[mid] and :
#         return foldSearch(element, l, mid)
#     else:
#         return foldSearch(element, mid+1, r)


buffer = io.StringIO()

n, m = map(int, input().split())
a = [0] + [*map(int, input().split())]
for q in map(int, input().split()):
    try:
        indexq = a.index(q)
    except ValueError:
        indexq = -1
    buffer.write(F"{indexq} ")
    pass
print(buffer.getvalue())
