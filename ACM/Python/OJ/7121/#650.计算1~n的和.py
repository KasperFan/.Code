'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-10-07 20:17:04
LastEditTime: 2023-10-07 20:34:58
FilePath: /Python/OJ/7121/#650.计算1~n的和.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''

if __name__ == "__main__":
    n: int = int(input())
    print("%.0f" % (n * ((n+1) / 2) % (1e9+7)))