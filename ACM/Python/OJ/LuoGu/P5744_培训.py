'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-12-10 23:08:57
LastEditTime: 2023-12-10 23:31:10
FilePath: /Python/P5744_培训.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''
import sys, io

def input(): return sys.stdin.readline().strip()

class Stu:
    def __init__(self, _name: str, _age: str, _score: str) -> None:
        self._name = _name
        self._age = int(_age)
        self._score = int(_score)
        pass

    def __tostr__(self) -> str:
        return f"{self._name} {self._age} {self._score}"
    
    def trail(self) -> None:
        self._age += 1
        self._score = 600 if int(self._score*1.2) > 600 else int(self._score*1.2)
        pass
    pass

with io.StringIO() as buffer:
    n = int(input())
    stus = [Stu(*input().split()) for _ in range(n)]
    for i in stus: i.trail(); print(i._age)
    for i in stus: buffer.write(f"{i.__tostr__()}\n")
    print(buffer.getvalue(), end="")
