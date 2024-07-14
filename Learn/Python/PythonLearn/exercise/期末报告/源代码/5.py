# -*- coding: utf-8 -*-
# @FileCreateTime    : 2024/6/13 17:44
# @Author            : kasperfan
# @Site              : 
# @File              : 5.py
# @Path              : 
# @Software          : PyCharm 
# @Comment           :
import sys

score2: list
with open("score1.txt", mode='r') as f:
    score2 = [[tokens[0]] + [int(tokens[1]) * 0.4 + int(tokens[2]) * 0.6] for tokens in
              (line.split() for line in f.readlines()[1:])]
with open("score2.txt", mode='w') as f:
    sys.stdout = f
    print("学号", "总评成绩", sep="\t")
    print(*("{}\t{:.1f}".format(i[0], i[1]) for i in score2), sep="\n")
sys.stdout = sys.__stdout__
seq = [0 for _ in range(5)]
total = 0
for i in score2:
    if i[1] < 60: total += i[1]; seq[0] += 1
    elif 60 <= i[1] < 70: total += i[1]; seq[1] += 1
    elif 70 <= i[1] < 80: total += i[1]; seq[2] += 1
    elif 80 <= i[1] < 90: total += i[1]; seq[3] += 1
    elif 90 <= i[1]: total += i[1]; seq[4] += 1
print(f"学生总人数为{len(score2)}。按总评成绩统计各成绩档学生的人数：",
      f"90以上{seq[4]}人、80～89有{seq[3]}人、70～79有{seq[2]}人、60～69有{seq[1]}人、60分以下{seq[0]}人。",
      "班级总平均分为{:.1f}分。".format(total / len(score2)), sep="\n")
