'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-04-19 20:02:50
LastEditTime: 2023-05-23 09:35:43
FilePath: /.Code/Learn/Python/MD5算法.py
describes: This file is created for learning Code.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''
import hashlib

message = input()
md5_hash = hashlib.md5()
md5_hash.update(message.encode('utf-8'))
hash_value = md5_hash.hexdigest()

print(hash_value)

# 蒙德-龙脊雪山-雪葬之都·旧宫
# 2022_01_07_19_潍坊学院天一楼

