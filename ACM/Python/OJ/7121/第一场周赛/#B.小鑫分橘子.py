'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-11-04 09:50:36
LastEditTime: 2023-11-04 10:02:26
FilePath: /Python/OJ/7121/第一场周赛/#B.小鑫分橘子.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''
import io

buffer = io.StringIO()
T: int = int(input())
for i in range(T):
    oranges = list(map(int, input().split()))
    oranges.sort()
    most = (oranges[2] // oranges[0])
    mid = (oranges[1] // oranges[0]) - 1
    if most + mid > 3:
        buffer.write("%s\n" % "NO")
    else:
        buffer.write("%s\n" % "YES")
print(buffer.getvalue(), end="")