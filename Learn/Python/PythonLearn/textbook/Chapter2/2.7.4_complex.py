# -*- coding: utf-8 -*-
# @FileCreateTime    : 2024/2/11 15:28
# @Author            : kasperfan
# @Site              : 
# @File              : 2.7.4_complex.py
# @Path              : 
# @Software          : PyCharm 
# @Comment           :
"""
当数值字符串中包含虚部（j 或 J）时，即为复数（complex）字面量。
complex是Python的内置数据类型，Python解释器自动创建complex型对象实例。
其基本形式为：
     complex(real[, imag])   # 创建 complex 对象（虚部可选）
"""
fu = complex('1 + 3j')
print(fu)
