# -*- coding: utf-8 -*-
# @FileCreateTime    : 2024/5/13 17:20
# @Author            : kasperfan
# @Site              : 
# @File              : randomfile.py
# @Path              : 
# @Software          : PyCharm 
# @Comment           :
import os

f = open('source/data.dat', 'w+b')
f.seek(0)
f.write(b'Hello')
f.write(b'World')
f.seek(-5, os.SEEK_END)
b = f.read(5)
print(b)