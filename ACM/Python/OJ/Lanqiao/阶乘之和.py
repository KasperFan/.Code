'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-04-13 14:31:59
LastEditTime: 2023-04-13 15:07:43
FilePath: /ACM/Python/Lanqiao/阶乘之和.py
describes: This file is created for learning Code.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''
ans = 0
mod = 1e9
temp = 1
k = 1
while k <= 2:
    temp *= k
    # temp %= mod
    ans += temp
ans %= mod
print(ans)
