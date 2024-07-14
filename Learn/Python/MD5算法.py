'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-04-19 20:02:50
LastEditTime: 2023-05-23 09:35:43
FilePath: /.Code/Learn/Python/MD5算法.py
describes: This file is created for learning Code.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''
import hashlib

message = 'mode=3&oid=1605225532&pagination_str=%7B%22offset%22%3A%22%7B%5C%22type%5C%22%3A1%2C%5C%22direction%5C%22%3A1%2C%5C%22session_id%5C%22%3A%5C%221759586085171455%5C%22%2C%5C%22data%5C%22%3A%7B%7D%7D%22%7D&plat=1&type=1&web_location=1315875&wts=1718345885(V,F)=>R$1(V,v$3(F))'
md5_hash = hashlib.md5()
md5_hash.update(message.encode('utf-8'))
hash_value = md5_hash.hexdigest()

print(hash_value)

# 蒙德-龙脊雪山-雪葬之都·旧宫
# 2022_01_07_19_潍坊学院天一楼

