'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-11-05 15:07:17
LastEditTime: 2023-11-05 15:23:58
FilePath: /Python/WFUStudy/摸底/P1068_分数线划定.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''
from io import StringIO


class Competiter:
    def __init__(self, k: int, s: int) -> None:
        self.k = k
        self.s = s


buffer: StringIO = StringIO()
n: int
m: int
competiters: list

n, m = map(int, input().split())
m = int(m * 1.5)
competiters = [Competiter(*map(int, input().split())) for _ in range(n)]
competiters.sort(key=lambda o: o.k)
competiters.sort(key=lambda o: o.s, reverse=True)
while competiters[m-1].s == competiters[m].s:
    m += 1
buffer.write("%d %d\n" % (competiters[m-1].s, m))
for i in range(m):
    buffer.write("%d %d\n" % (competiters[i].k, competiters[i].s))
print(buffer.getvalue(), end='')
