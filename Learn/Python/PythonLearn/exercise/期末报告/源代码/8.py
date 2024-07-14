# -*- coding: utf-8 -*-
# @FileCreateTime    : 2024/6/13 17:47
# @Author            : kasperfan
# @Site              : 
# @File              : 8.py
# @Path              : 
# @Software          : PyCharm 
# @Comment           :
class Course:
    def __init__(self, number, name, teacher, location):
        self.number, self.name, self.teacher, self.__location = number, name, teacher, location

    def show_info(self):
        print(f"课程编号：{self.number}",
              f"课程名称：{self.name}",
              f"任课教师：{self.teacher}",
              f"上课地点：{self.__location}", sep="\n")


course1 = Course("CS101", "计算机科学导论", "张磊", "天一楼7212")
course1.show_info()
print(course1.name)
print(course1.number)
print(course1.teacher)
# print(course1.__location) # 报错
