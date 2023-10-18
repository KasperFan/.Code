'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-10-09 07:40:35
LastEditTime: 2023-10-10 07:50:54
FilePath: /Python/OJ/7121/#46.圆柱体计算.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''
PI: float = 3.1415926  # 定义π大小

# 实数包括整数和浮点数(小数)，浮点数2.00000的大小也可以表示整数2
r: float
h: float
r, h = map(float, input().split()) # 输入r、n
print("%.2f %.2f %.2f %.2f" % (2*PI*r, PI*r*r, h*2*PI*r, h*PI*r*r))