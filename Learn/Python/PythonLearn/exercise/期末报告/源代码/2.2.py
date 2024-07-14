# -*- coding: utf-8 -*-
# @FileCreateTime    : 2024/6/13 17:39
# @Author            : kasperfan
# @Site              : 
# @File              : 2.2.py
# @Path              : 
# @Software          : PyCharm 
# @Comment           :
import turtle as t

r = 10
head = 90
t.seth(head)
for i in range(4):
    t.circle(r + i * 40)
t.done()
