import os, sys, io

e = [[] for _ in range(A+1)]
fa = [0 for _ in range(A+1)]

# A个点
for i in range(1, A+1):
    fai = int(input())
    e[fai].append(i)
    fa[i] = fai

