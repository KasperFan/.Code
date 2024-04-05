# -*- coding: utf-8 -*-
# @FileCreateTime    : 2024/3/8 17:21
# @Author            : kasperfan
# @Site              : 
# @File              : richTqdmDemo.py
# @Path              : 
# @Software          : PyCharm 
# @Comment           :
from tqdm.rich import tqdm, trange
from time import sleep

for i in trange(100):
    sleep(0.2)
    pass

