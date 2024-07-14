# import math

# # def trucation(x): return math.trunc(x)
# def trucation(x):
#     s = str(x)
#     if '.' in s:
#         dotIndex = s.index('.')
#         if dotIndex == 0:
#             return '0'
#         else:
#             return int(s[:dotIndex])
#     else:
#         return int(s)

# num = float(input('输入一个小数:'))
# trunc_num = trucation(num)
# print('{0}截断后是{1}'.format(num, trunc_num))


# class_1 = ['James', 'Thomas', 'Vespa']
# class_2 = ['James', 'Thomas', 'Vespa']
# class_3 = class_1

# print(class_1 == class_2)
# print(class_1 is class_2)
# print(class_3 is class_1)
# print(id(class_1), id(class_2), id(class_3))


# s1 = input("输入第1个字符串：")
# s2 = input("输入第2个字符串：")
# count = 0
# same_chars = set(s1) & set(s2)
# for c in same_chars:
#     print('相同字符：', c)
#     count += 1

# if count == 0:
#     print('没有相同字符')
# else:
#     print(F'相同的字符有{len(same_chars)}个，分别是{same_chars}')


# 北京市北京第二外国语学院
# 北京市朝阳区中国传媒大学
