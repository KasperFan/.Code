# -*- coding: utf-8 -*-
# @FileCreateTime    : 2024/6/13 17:42
# @Author            : kasperfan
# @Site              : 
# @File              : 3.3.py
# @Path              : 
# @Software          : PyCharm 
# @Comment           :
def getMaxPos(L: list[int]) -> tuple[int, int]:
    return max(L), L.index(max(L)) + 1


def main():
    citys: list
    with open("rainfall.txt", mode='r') as f:
        citys = [[tokens[0]] + [int(i) for i in tokens[1:]] for tokens in (line.split() for line in f.readlines()[1:])]
    print("地区", "最大月降水量（mm）", "对应降水月份", sep="\t")
    print(*("{}\t{:8}\t{:6}月".format(city[0], *getMaxPos(city[1:])) for city in citys), sep="\n")


if __name__ == '__main__':
    main()