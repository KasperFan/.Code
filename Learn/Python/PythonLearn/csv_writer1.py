# -*- coding: utf-8 -*-
# @FileCreateTime    : 2024/5/13 16:58
# @Author            : kasperfan
# @Site              : 
# @File              : csv_writer1.py
# @Path              : 
# @Software          : PyCharm 
# @Comment           :
import csv


def write_csv1(csvfilepath):
    headers = ['学号', '姓名', '性别', '班级', '语文', '数学', '英语']
    rows = [('102111', '宋颐园', '男', '一班', '72', '85', '82'),
            ('102113', '王二丫', '女', '一班', '75', '82', '51'),
            ('102131', '董再永', '男', '三班', '55', '74', '79'),
            ('101521', '陈春燕', '女', '二班', '80', '86', '68'),
            ('102135', '周一萍', '女', '三班', '72', '76', '72')]
    with open(csvfilepath, 'w', newline='') as f:
        f_csv = csv.writer(f)
        f_csv.writerow(headers)
        f_csv.writerows(rows)


if __name__ == '__main__':
    write_csv1(r'source/scores1.csv')
