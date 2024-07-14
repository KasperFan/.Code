# -*- coding: utf-8 -*-
# @FileCreateTime    : 2024/5/13 20:53
# @Author            : kasperfan
# @Site              : 
# @File              : quadratic.py
# @Path              : 
# @Software          : PyCharm 
# @Comment           :
import math
import sys

print(sys.argv)
b = float(sys.argv[1])
c = float(sys.argv[2])
discriminamt = b**2 - 4.0 * c
if discriminamt >= 0:
    delta = math.sqrt(discriminamt)
    print("x1 =", (-b + delta)/2.0)
    print("x2 =", (-b - delta)/2.0)
else:
    print("此方程无实数解")
