'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-10-07 20:00:08
LastEditTime: 2023-10-07 20:12:07
FilePath: /Python/OJ/7121/#648.圆周率.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''

if __name__ == "__main__":
    n:int = int(input())
    π:float = 0
    cnt:int = 1
    for i in range(1, 4*n, 2):
        π += 1.0/i * (-1 if cnt % 2 == 0 else 1)
        cnt += 1
    π *= 4
    print("%.6f" % π)