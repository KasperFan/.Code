'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-11-05 14:46:14
LastEditTime: 2023-11-05 15:37:59
FilePath: /Python/WFUStudy/摸底/P1426_小鱼会有危险吗.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''
s: float
x: float
now: float = 0
left: float
right: float
meter: float = 7

s, x = map(float, input().split())
left = s-x
right = s+x
while now < left:
    now += meter
    meter *= 0.98
if now + meter > right:
    print('n')
else:
    print('y')
