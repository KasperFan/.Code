# -*- coding: utf-8 -*-
# @FileCreateTime    : 2024/5/13 18:55
# @Author            : kasperfan
# @Site              : 
# @File              : read_csv.py
# @Path              : 
# @Software          : PyCharm 
# @Comment           :
import csv

scores = []
csvfilepath = 'data.csv'
with open(csvfilepath, newline='') as f:
    f_csv = csv.reader(f)
    headers = next(f_csv)
    # for row in f_csv:
    #     scores.append(row)
    scores.extend(row for row in f_csv)
print("原始记录：", scores)
scoresData = []
# for rec in scores:
#     scoresData.append(int(rec[2]))
scoresData.extend(int(rec[2]) for rec in scores)
print("成绩列表：", scoresData)
print("平均成绩：", sum(scoresData)/len(scoresData))
