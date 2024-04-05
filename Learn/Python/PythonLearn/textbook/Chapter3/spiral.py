# -*- coding: utf-8 -*-
# @FileCreateTime    : 2024/2/20 10:28
# @Author            : kasperfan
# @Site              : 
# @File              : spiral.py.py
# @Path              : 
# @Software          : PyCharm 
# @Comment           :
import turtle as t
from time import sleep

p = t.Turtle()
p.speed(100)
colors = ["red", "blue", "green", "yellow"]
for i in range(100):
    p.pencolor(colors[i % 4])
    p.circle(i)
    p.left(91)

sleep(60)

