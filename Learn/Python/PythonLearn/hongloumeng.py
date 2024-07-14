# -*- coding: utf-8 -*-
# @FileCreateTime    : 2024/5/17 19:46
# @Author            : kasperfan
# @Site              : 
# @File              : hongloumeng.py
# @Path              : 
# @Software          : PyCharm 
# @Comment           :
import jieba

txtfilepath = '红楼梦.txt'
with open(txtfilepath, encoding='utf-8') as f:  # 打开文件
    txt = f.read()      # 读取文本文件的所有内容
words = jieba.cut(txt)      # 使用精确模式对文本进行分词
counts = {}             # 通过键值对的形式存储词语及其出现的个数
for word in words:          # 遍历所有词语，每出现一次其对应的值加 1
    if len(word) == 1:     # 单字词语不计算在内
        continue
    else:
        counts[word] = counts.get(word, 0) + 1
items = list(counts.items())
items.sort(key=lambda x: x[1], reverse=True)
for i in range(5):
    word, count = items[i]
    print("{0:<8}{1:>8}".format(word, count))
