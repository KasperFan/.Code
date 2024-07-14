# -*- coding: utf-8 -*-
# @FileCreateTime    : 2024/6/13 17:42
# @Author            : kasperfan
# @Site              : 
# @File              : 3.2.py
# @Path              : 
# @Software          : PyCharm 
# @Comment           :
def get_birthday(id_num: str) -> list[int]:
    year = int(id_num[6:10])
    month = int(id_num[10:12])
    day = int(id_num[12:14])
    return [year, month, day]


id_nums = ['310101199005052115', '310104199607076128', '310117199309235133']
for id_num in id_nums:
    print("{}的生日为：{}-{}-{}".format(id_num, *get_birthday(id_num)))