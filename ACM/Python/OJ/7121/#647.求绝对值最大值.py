'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-10-07 19:38:19
LastEditTime: 2023-10-11 09:38:10
FilePath: /Python/OJ/7121/#647.求绝对值最大值.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''
if __name__ == "__main__":
    n: int = int(input())
    max: int = 0
    index: int = -1
    arr = [int(i) for i in input().split()]
    for i in range(n):
        if max < abs(arr[i]):
            index = i
            max = abs(arr[i])
    print(arr[index])
