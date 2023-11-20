'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-10-22 14:50:17
LastEditTime: 2023-10-23 23:36:57
FilePath: /Python/WFUStudy/第一次检验/P1478_陶陶摘苹果（升级版）.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''
from sys import stdin


class Apple:
    def __init__(self, x: int, y: int) -> None:
        self.x = x
        self.y = y


if __name__ == "__main__":
    cnt: int = 0
    n, s = map(int, input().split())
    a, b = map(int, input().split())
    data = stdin.readlines()
    apples = [Apple(*map(int, line.split())) for line in data]
    apples.sort(key=lambda x: x.y)
    for apple in apples:
        if apple.x <= a+b and apple.y <= s:
            cnt += 1
            s -= apple.y
        elif apple.y > s:
            break
    print(cnt)
