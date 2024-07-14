'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2024-04-12 21:11:35
LastEditTime: 2024-04-13 23:37:05
FilePath: /Python/运算符重载/Matrix.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2024 by KasperFan in WFU, All Rights Reserved. 
'''
import numpy as np



class Matrix:
    @staticmethod
    def I(size):
        return Matrix(size=size)

    def __init__(self, matrix=None, size=0):
        if matrix: self.matrix = matrix
        elif size:
            self.matrix = [\
                [1 if i == j else 0 for j in range(size)]\
                    for i in range(size)]
        else: self.matrix =[]

    def __add__(self, other):
        if len(self.matrix) != len(other.matrix) or len(self.matrix[0]) != len(other.matrix[0]):
            raise ValueError("矩阵大小不匹配，无法相加")
        return Matrix([[self.matrix[i][j] + other.matrix[i][j] for j in range(len(self.matrix[0]))] for i in range(len(self.matrix))])

    def __mul__(self, other):
        if len(self.matrix[0]) != len(other.matrix):
            raise ValueError("矩阵大小不匹配，无法相乘")
        result = [[sum(a * b for a, b in zip(self_row, other_col)) for other_col in zip(*other.matrix)] for self_row in self.matrix]
        return Matrix(result)

    def __str__(self):
        return '\n'.join([' '.join(map(str, row)) for row in self.matrix])


# 示例使用
m1 = Matrix([[1, 2], [3, 4]])
m2 = Matrix([[5, 6], [7, 8]])

print(m1)
print(m2)

m3 = m1 + m2
print("矩阵加法结果：")
print(m3)

m4 = m1 * m2
m4 = m1.__mul__(m2)
print("矩阵乘法结果：")
print(m4)

ele = zip(*m4.matrix)
print(ele)