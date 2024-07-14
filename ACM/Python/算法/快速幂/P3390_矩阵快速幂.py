'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2024-04-12 23:05:13
LastEditTime: 2024-04-13 08:15:22
FilePath: /Python/算法/快速幂/P3390_矩阵快速幂.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2024 by KasperFan in WFU, All Rights Reserved. 
'''
from math import inf
import numpy as np
import sys

sys.stdin = open("算法/快速幂/P3390_1.in", mode="r")
result = open("算法/快速幂/P3390_1.out", mode="r").read()

# def input(): return sys.stdin.readline().strip()


class Matrix:
    @staticmethod
    def I(size):
        return Matrix(size=size)

    def __init__(self, matrix=None, size=0):
        if matrix:
            self.matrix = matrix
        elif size:
            self.matrix = [
                [1 if i == j else 0 for j in range(size)]
                for i in range(size)]
        else:
            self.matrix = []

    def __mul__(self, other):
        result = [[sum(a * b for a, b in zip(self_row, other_col))
                   for other_col in zip(*other.matrix)] for self_row in self.matrix]
        return Matrix(result)

    # def __imul__(self, other):

    def __str__(self):
        return '\n'.join([' '.join(map(str, row)) for row in self.matrix])


def fastMi(A: Matrix, k):
    r: Matrix = Matrix.I(n)
    while k:
        if k & 1:
            r = r * A
        A = A * A
        k >>= 1
    return r


n: int
k: int
A: Matrix

n, k = map(int, input().split())
A = Matrix([[*map(int, input().split())] for _ in range(n)])
print(result == fastMi(A, k))
sys.stdin = sys.__stdin__
na