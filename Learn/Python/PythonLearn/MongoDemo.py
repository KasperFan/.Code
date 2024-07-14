# -*- coding: utf-8 -*-
# @FileCreateTime    : 2024/4/16 16:34
# @Author            : kasperfan
# @Site              : 
# @File              : MongoDemo.py
# @Path              : 
# @Software          : PyCharm 
# @Comment           :
import pymongo, json

client = pymongo.MongoClient("localhost", 27017)

db = client['test']


class Person:
    def __init__(self):
        pass


persons = []
collection = db['main']
result = collection.find()
for i in result:
    print(type(i))

