# -*- coding: utf-8 -*-
# @FileCreateTime    : 2024/6/13 17:40
# @Author            : kasperfan
# @Site              : 
# @File              : 2.3.py
# @Path              : 
# @Software          : PyCharm 
# @Comment           :
def gcd(a, b):
    if a == b: return a
    sub = max(a, b) - min(a, b)
    while sub != min(a, b):
        a, b = min(a, b), sub
        sub = max(a, b) - min(a, b)
    return sub


def lcm(a, b):
    return a * b // gcd(a, b)


a = int(input('请输入整数a:'))
b = int(input('请输入整数b:'))
print(f"最大公约数：{gcd(a, b)}")
print(f"最小公倍数：{lcm(a, b)}")