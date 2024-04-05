# -*- coding: utf-8 -*-
# @FileCreateTime    : 2024/3/5 18:08
# @Author            : kasperfan
# @Site              : 
# @File              : str_util.py
# @Path              : 
# @Software          : PyCharm 
# @Comment           :

# 接受传入字符串，将字符串反转返回
def str_reverse(s):
    return s[-1::-1]


# 按照下标x和y，对字符串进行切片
def substr(s, x, y):
    return s[x:y]
