'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-10-22 16:55:15
LastEditTime: 2023-10-22 17:19:10
FilePath: /Python/WFUStudy/第一次检验/P1042_[NOIP2003普及组]_乒乓球.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''
import sys, io, math


data = sys.stdin.readlines()
buffer = io.StringIO()


def compete(score: int):
    global data
    global buffer
    cntW = cntL = 0
    for i in data:
        for j in i:
            if j == "E":
                buffer.write("%d:%d\n" % (cntW, cntL))
                cntW = cntL = 0
                break
            if j == "W":
                cntW += 1
            elif j == "L":
                cntL += 1
            if (cntL >= score or cntW >= score) and int(math.fabs(cntL-cntW)) >= 2:
                buffer.write("%d:%d\n" % (cntW, cntL))
                cntW = cntL = 0


if __name__ == "__main__":
    compete(11)
    buffer.write("\n")
    compete(21)
    print(buffer.getvalue(), end="")
