# -*- coding: utf-8 -*-
# @FileCreateTime    : 2024/5/13 17:08
# @Author            : kasperfan
# @Site              : 
# @File              : json_load.py
# @Path              : 
# @Software          : PyCharm 
# @Comment           :
import json

with open(r'source/data.json', 'r') as f:
    urls = json.load(f)
    print(urls)
