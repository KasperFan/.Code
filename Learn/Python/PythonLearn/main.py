# -*- coding: utf-8 -*-
# @FileCreateTime    : 2024/5/7 21:40
# @Author            : kasperfan
# @Site              : 
# @File              : main.py
# @Path              : 
# @Software          : PyCharm 
# @Comment           :
# import time
#
# # 记录开始时间
# start = time.time_ns()
# # 执行代码
# for i in range(1, 1001):
#     print(i)
# # 记录结束时间
# end = time.time_ns()
# # 打印上面代码执行的时间
# print(f'执行时间为{(end - start) // 1000}微秒')
#
# import time
#
#
# def find_sum1(n):
#     sum = 0
#     for i in range(1, n + 1):
#         sum += i
#     return sum
#
#
# def find_sum2(n):
#     return n * (n + 1) / 2
#
#
# # 按下面注释的要求补全程序
# # 1.获取用户输入的自然数
# n = int(input("请输入一个自然数："))
# # 2,调用求和函数find_sum1(),输出函数开始执行和结束的时间戳，以及执行消耗时间。
# start = time.time_ns()
# print(f"find_sum1({n}) 开始执行的时间戳:{start}")
# print(f"求和结果是{find_sum1(n)}")
# end = time.time_ns()
# print(f"find_sum1({n}) 结束的时间戳:{end}")
# print(f"find_sum1({n}) 耗时:{(end-start)//1000}毫秒")
# print()
# # 3.调用求和函数fid_sUm2(),输出函数开始执行和结束的时间戳，以及执行消耗时间。
# start = time.time_ns()
# print(f"find_sum2({n}) 开始执行的时间戳:{start}")
# print(f"求和结果是{find_sum2(n)}")
# end = time.time_ns()
# print(f"find_sum2({n}) 结束的时间戳:{end}")
# print(f"find_sum2({n}) 耗时:{(end-start)//1000}毫秒")

# import os, sys
#
# title = "22022402430樊宗豪"
# li1 = ['-', '一', '二', '三', '四', '五', '六', '七', '八', '九']
# li2 = ['-', 'Python程序的编辑运行', '简单程序设计（一）', '简单程序设计（二）', '控制结构程序设计', '函数设计：模拟时钟',
#        '组合和数据：列表', '中文分词', '自定义列表的设计', 'Python文件读写与模块化操作']
# os.chdir("./exercise")
#
# for i in range(1, 10):
#     os.mkdir(title + "实验" + li1[i] + li2[i])
#     os.chdir(title + "实验" + li1[i] + li2[i])
#     with open("实验"+str(i)+".py", mode='w') as f: pass
#     os.chdir("..")

# li = [input, print]
# li[1](li[0]("faklsjdfg"))

# 阅读下面Python程序，请问输出结果是什么？
# print("T",end=' ') if not 0 else print('F',end=' ')
# print("T",end=' ') if 6 else print('F',end=' ')
# print("T",end=' ') if "" else print('F',end=' ')
# print("T",end=' ') if "abc" else print('F',end=' ')
# print("T",end=' ') if () else print('F',end=' ')
# print("T",end=' ') if (1,2) else print('F',end=' ')
# print("T",end=' ') if [] else print('F',end=' ')
# print("T",end=' ') if [1,2] else print('F',end=' ')
# print("T",end=' ') if {} else print('F',end=' ')
# print("T",end=' ') if {1,2} else print('F',end=' ')

# 下列Python语句的程序运行结果为。
# x = True; y = False; z = True;
# if not x or y: print(1)
# elif not x or not y and z: print(2)
# elif not x or y or not y and x: print(3)
# else: print(4)

# a = 10
#
# a //= a - 3
# print(a)
"""
import turtle as t

r = 10
head = 90
t.seth(head)
for i in range(4):
    t.circle(r + i * 40)
t.done()
"""

"""
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
"""

"""
def gcd(a, b):
    return b if a % b == 0 else gcd(b, a % b)


def lcm(a, b):
    return a * b // gcd(a, b)


a = int(input('请输入第一个整数：'))
b = int(input('请输入第二个整数：'))
print(gcd(a, b), lcm(a, b))
"""

"""
def get_birthday(id_num: str) -> list[int]:
    year = int(id_num[6:10])
    month = int(id_num[10:12])
    day = int(id_num[12:14])
    return [year, month, day]


id_nums = ['310101199005052115', '310104199607076128', '310117199309235133']
for id_num in id_nums:
    print("{}的生日为：{}-{}-{}".format(id_num, *get_birthday(id_num)))
"""

"""
def getMaxPos(L: list[int]) -> tuple[int, int]:
    return max(L), L.index(max(L)) + 1


def main():
    citys: list
    with open("rainfall.txt", mode='r') as f:
        citys = [[tokens[0]] + [int(i) for i in tokens[1:]] for tokens in (line.split() for line in f.readlines()[1:])]
    print("地区", "最大月降水量（mm）", "对应降水月份", sep="\t")
    print(*("{}\t{:8}\t{:6}月".format(city[0], *getMaxPos(city[1:])) for city in citys), sep="\n")


if __name__ == '__main__':
    main()
"""

"""
def insertList(L1, x):
    def __get_index(r, l=0):
        if r-l <= 1: return l
        return __get_index(l=(l+r)//2, r=r) if L1[(l+r)//2] < x else __get_index(l=l, r=(l+r)//2)

    L1.insert(__get_index(len(L1))+1, x)


L1 = [1,4,6,9,13,16,28,40,100]
x = int(input('请输入一个要插入的整数：'))
insertList(L1,x)
print(L1)
"""

# d = {1:'a', 2:'b', 3:'c'};
# print(d)
# del d[1]
# d[1] = 'x'
# del d[2]
# print(d)

# import random, sys
#
# with open("score1.txt", mode='w') as f:
#     sys.stdout = f
#     for i in range(51):
#         id_num, ping, end = random.randint(1000000, 10000000 - 1), random.randint(30, 100), random.randint(30, 80)
#         print(id_num, ping, end, sep="\t")
#


"""
import sys

score2: list
with open("score1.txt", mode='r') as f:
    score2 = [[tokens[0]] + [int(tokens[1]) * 0.4 + int(tokens[2]) * 0.6] for tokens in
              (line.split() for line in f.readlines()[1:])]
with open("score2.txt", mode='w') as f:
    sys.stdout = f
    print("学号", "总评成绩", sep="\t")
    print(*("{}\t{:.1f}".format(i[0], i[1]) for i in score2), sep="\n")
sys.stdout = sys.__stdout__
seq = [0 for _ in range(5)]
total = 0
for i in score2:
    if i[1] < 60: total += i[1]; seq[0] += 1
    elif 60 <= i[1] < 70: total += i[1]; seq[1] += 1
    elif 70 <= i[1] < 80: total += i[1]; seq[2] += 1
    elif 80 <= i[1] < 90: total += i[1]; seq[3] += 1
    elif 90 <= i[1]: total += i[1]; seq[4] += 1
print(f"学生总人数为{len(score2)}。按总评成绩统计各成绩档学生的人数：",
      f"90以上{seq[4]}人、80～89有{seq[3]}人、70～79有{seq[2]}人、60～69有{seq[1]}人、60分以下{seq[0]}人。",
      "班级总平均分为{:.1f}分。".format(total / len(score2)), sep="\n")
"""

"""
import random, string, sys

random.seed(0x1010)
chars = string.ascii_letters+string.digits+"!@#$%^&*"
pwds = []
exclude = set()
while len(pwds) < 10:
    pwd = ""
    while len(pwd) < 10:
        pwd+=random.choice(chars)
    if pwd[0] in exclude: continue
    exclude.add(pwd[0])
    pwds.append(pwd)
with open("随机密码.txt", mode="w") as f:
    sys.stdout = f
    print(*pwds, sep="\n")
sys.stdout = sys.__stdout__
# """

"""
str1 = input('请输入字符串一：')
str2 = input('请输入字符串二：')
if len(str1) == len(str2):
    for i in range(len(str1)):
        if str1[i] == str2[i]: continue
        print(str1 if str1[i] < str2[i] else str2)
        break
else: print(str1 if len(str1) < len(str2) else str2)

# s1 = "QQ"
# s2 = "Wechat"
# print("{:*<10}{:=>10}".format(s1, s2))


class Course:
    def __init__(self, number, name, teacher, location):
        self.number, self.name, self.teacher, self.__location = number, name, teacher, location

    def show_info(self):
        print(f"课程编号：{self.number}",
              f"课程名称：{self.name}",
              f"任课教师：{self.teacher}",
              f"上课地点：{self.__location}", sep="\n")


course1 = Course("CS101", "计算机科学导论", "张磊", "天一楼7212")
course1.show_info()
print(course1.name)
print(course1.number)
print(course1.teacher)
print(course1.__location)
"""

import turtle as t

t.bgcolor("black")

pen = t.Turtle()

pen.showturtle()
pen.speed(2)
pen.color("white")
pen.begin_fill()
for i in range(5):
    pen.forward(50*(36/180))
    pen.right(72)
pen.end_fill()


t.done()
