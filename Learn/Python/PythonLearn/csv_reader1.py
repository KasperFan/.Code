# -*- coding: utf-8 -*-
# @FileCreateTime    : 2024/5/13 16:50
# @Author            : kasperfan
# @Site              : 
# @File              : csv_reader1.py
# @Path              : 
# @Software          : PyCharm 
# @Comment           :
import csv


def read_csv1(csvfilepath):
    with open(csvfilepath, newline='') as f:
        f_csv = csv.reader(f)
        headers = next(f_csv)
        print(headers)
        for row in f_csv:
            print(row)


if __name__ == '__main__':
    read_csv1(r'source/scores.csv')
