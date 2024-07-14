# -*- coding: utf-8 -*-
# @FileCreateTime    : 2024/5/13 17:05
# @Author            : kasperfan
# @Site              : 
# @File              : json_dump.py
# @Path              : 
# @Software          : PyCharm 
# @Comment           :
import json

urls = {
    'baidu': 'http://www.baidu.com/',
    'sina': 'http://www.sina.com.cn/',
    'tencent': 'http://www.qq.com/',
    'taobao': 'https://www.taobao.com/'
}
print(urls)
with open(r'source/data.json', 'w') as f:
    json.dump(urls, f)
