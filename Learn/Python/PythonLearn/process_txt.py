# -*- coding: utf-8 -*-
# @FileCreateTime    : 2024/5/13 18:31
# @Author            : kasperfan
# @Site              : 
# @File              : process_txt.py
# @Path              : 
# @Software          : PyCharm 
# @Comment           :
scores = []
txtfilepath = 'data.txt'
with open(txtfilepath, encoding='utf-8') as f:
    scores.extend(int(s) for s in f.readlines())
result_filepath = 'result.txt'
# with open(result_filepath, 'w', encoding='utf-8') as f:

