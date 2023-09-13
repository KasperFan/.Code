'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-03-18 01:31:37
LastEditTime: 2023-03-18 01:37:19
FilePath: /ACM/Python/CodeForces/4A_Watermelon.py
Description: This file is created for learning Code.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''
w = int(input())
if w % 2 == 0 and w//2 >= 2:
    print("YES")
else:
    print("NO")
