'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-10-13 08:08:47
LastEditTime: 2023-10-13 08:30:12
FilePath: /Python/OJ/LuoGu/速刷(大一)/Triangle.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''
if __name__ == "__main__":
    maxcnt: int = 0
    stick: list = [int(i) for i in input().split()]
    stick.sort()
    for i in range(len(stick)):
        for j in range(i+1,len(stick)):
            for k in range(j+1,len(stick)):
                if stick[i] + stick[j] > stick[k]:
                    maxcnt = 2
                elif stick[i] + stick[j] == stick[k]:
                    maxcnt = 1 if maxcnt <= 1 else maxcnt
    if maxcnt > 0:
        print("TRIANGLE" if maxcnt == 2 else "SEGMENT")
    else:
        print("IMPOSSIBLE")
