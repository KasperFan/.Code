# -*- coding: utf-8 -*-
# @FileCreateTime    : 2024/6/13 17:46
# @Author            : kasperfan
# @Site              : 
# @File              : 7.1.py
# @Path              : 
# @Software          : PyCharm 
# @Comment           :
str1 = input('请输入字符串一：')
str2 = input('请输入字符串二：')
if len(str1) == len(str2):
    for i in range(len(str1)):
        if str1[i] == str2[i]: continue
        print(str1 if str1[i] < str2[i] else str2)
        break
else: print(str1 if len(str1) < len(str2) else str2)
