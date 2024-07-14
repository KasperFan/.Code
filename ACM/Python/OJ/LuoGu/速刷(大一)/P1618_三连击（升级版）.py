'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-10-13 09:25:26
LastEditTime: 2023-10-13 19:08:05
FilePath: /Python/OJ/LuoGu/速刷(大一)/P1618_三连击（升级版）.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''
import io

buffer = io.StringIO()

if __name__ == "__main__":
    A, B, C = map(int, input().split())
    if A == 0:
        print("No!!!")
    else:
        for i in range(1, 4):
            for j in range(1, 10):
                if j == i:
                    continue
                for k in range(1, 10):
                    if j == k or i == k:
                        continue
                    ochk = {i, j, k}
                    origin: int = 100*i+10*j+k
                    double: int = int(origin*(B/A))
                    triple: int = int(origin*(C/A))
                    if triple > 987:
                        break
                    dchk = {double//100, (double % 100)//10, double % 10}
                    tchk = {triple//100, (triple % 100)//10, triple % 10}
                    if len(ochk) != 3 or len(dchk) != 3 or len(tchk) != 3:
                        continue
                    elif len(ochk & dchk) != 0 or len(ochk & tchk) != 0 or len(dchk & tchk) != 0:
                        continue
                    elif 0 in ochk or 0 in dchk or 0 in tchk:
                        continue
                    buffer.write("%d %d %d\n" % (origin, double, triple))
        ans: str = buffer.getvalue()
        print("No!!!\n" if len(ans) == 0 else ans, end="")
