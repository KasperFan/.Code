'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2024-03-09 20:44:17
LastEditTime: 2024-03-09 21:05:02
FilePath: /Python/ATCoder/24.3.9/D.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2024 by KasperFan in WFU, All Rights Reserved. 
'''
from sys import stdin
from io import StringIO

input = lambda: stdin.readline().strip()

buffer = StringIO()

def dfs(key):
    global ans
    if key in strSet and : ans += 1; return
    else:

ans = 0
T = input()
N = int(input())
# strSet = {*input().split()[1:] for line in stdin.read()}
strSet = {element for line in stdin.read().splitlines()
          for element in line.split()[1:]}

