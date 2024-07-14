'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-10-11 15:37:37
LastEditTime: 2023-10-11 15:44:14
FilePath: /Python/OJ/7121/#721.求实数绝对值.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''
import sys, io, math

buffer = io.StringIO()

if __name__ == "__main__":
    for line in sys.stdin:
        x=float(line)
        buffer.write("%.2f\n" % math.fabs(x))
    print(buffer.getvalue())