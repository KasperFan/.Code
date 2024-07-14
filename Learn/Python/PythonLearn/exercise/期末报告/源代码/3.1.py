# -*- coding: utf-8 -*-
# @FileCreateTime    : 2024/6/13 17:41
# @Author            : kasperfan
# @Site              : 
# @File              : 3.1.py
# @Path              : 
# @Software          : PyCharm 
# @Comment           :
def gcd(a, b):
    return b if a % b == 0 else gcd(b, a % b)


def lcm(a, b):
    return a * b // gcd(a, b)


a = int(input('请输入第一个整数：'))
b = int(input('请输入第二个整数：'))
print(gcd(a, b), lcm(a, b))