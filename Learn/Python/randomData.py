'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-09-11 17:05:44
LastEditTime: 2023-09-11 17:55:04
FilePath: /Python/randomData.py
describes: This file is created for learning Code.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''
import random as r

a, b, c, d, e = map(int, input().split())

fileIn = open("./data/test_4.in", mode="w+")
fileIn.write("%d %d %d %d %d\n" % (a, b, c, d, e))
for i in range(b):
    u = r.randint(1, a)
    v = r.randint(1, a)
    w = r.randint(1, 1e7*(a/100000))
    fileIn.write("%d %d %d\n" % (u, v, w))
fileIn.close()
