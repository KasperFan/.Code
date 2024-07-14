# -*- coding: utf-8 -*-
# @FileCreateTime    : 2024/5/21 14:33
# @Author            : kasperfan
# @Site              : 
# @File              : test.py
# @Path              : 
# @Software          : PyCharm 
# @Comment           :

# if __name__ == "__main__": main()

# def main():
#     a, b = map(float, input("请输入两个用于比较的数a, b(eg: 5 8):").split())
#     print("两数中较大的数是{}".format(max(a, b)))

#from random import randint
#
# x: int
# k = randint(0, 9)
#
#
# def main():
#     global x
#     while True:
#         x = int(input("请输入一个0～9之间的数："))
#         if x > k:
#             print("太大")
#         elif x < k:
#             print("太小")
#         else:
#             print("恭喜！你猜中了！")
#             break

# year = int(input())
# print(f"年份{year}" + ("" if (not year % 4 and year % 100) or not year % 400 else "不") + "是闰年")

# x = ((3**4+5*6**7)/8)**0.5
# print("所求x的值为{:.3f}".format(x))

# from string import *
#
# lower = upper = digi = other = 0
# inp = input()
# for i in inp:
#     if i in ascii_lowercase: lower += 1
#     elif i in ascii_uppercase: upper += 1
#     elif i in digits: digi += 1
#     else: other += 1
# print("输入的字符串中有{}个小写字符，{}个大写字符，{}个数字字符和{}个其他字符".format(lower, upper, digi, other))
import time
#记录开始时间
start = time.time_ns()
#执行代码
for i in range(1,1001):
     print(i)
#记录结束时间
end = time.time_ns()
#打印上面代码执行的时间
print(f'执行时间为{end-start}秒')