# -*- coding: utf-8 -*-
# @FileCreateTime    : 2024/6/13 17:43
# @Author            : kasperfan
# @Site              : 
# @File              : 4.1.py
# @Path              : 
# @Software          : PyCharm 
# @Comment           :
def insertList(L1, x):
    def __get_index(r, l=0):
        if r - l <= 1: return l
        return __get_index(l=(l + r) // 2, r=r) if L1[(l + r) // 2] < x else __get_index(l=l, r=(l + r) // 2)

    L1.insert(__get_index(len(L1)) + 1, x)


L1 = [1, 4, 6, 9, 13, 16, 28, 40, 100]
x = int(input('请输入一个要插入的整数：'))
insertList(L1, x)
print(L1)
