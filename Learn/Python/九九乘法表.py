'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-09-28 13:31:12
LastEditTime: 2023-09-28 14:07:05
FilePath: /Python/九九乘法表.py
describes: This file is created for learning Code.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''

if __name__ == "__main__":
    for i in range(1, 10):
        for j in range(9-i):
            print(end="\t")
        for j in range(i, 0, -1):
            print("%d*%d=%d" % (j, i, i*j), end="\t")
        print()
