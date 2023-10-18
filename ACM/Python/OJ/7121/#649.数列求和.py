'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-10-07 20:13:48
LastEditTime: 2023-10-07 20:13:58
FilePath: /Python/OJ/7121/#649.数列求和.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''

if __name__ == "__main__":
    a: int = int(input())
    n: int = int(input())
    temp: int = a
    ans: int = 0
    for i in range(n):
        ans += temp
        temp = temp * 10 + a
    print(ans)
