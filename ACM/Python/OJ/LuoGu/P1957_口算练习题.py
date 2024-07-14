'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-12-02 13:09:59
LastEditTime: 2023-12-02 15:00:17
FilePath: /Python/OJ/LuoGu/P1957_口算练习题.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''
import sys, io


def input(): return sys.stdin.readline().strip()
def inputs(): return sys.stdin.readlines()


buffer = io.StringIO()


def main():
    op = None
    i = int(input())
    for _ in range(i):
        syntax = input()
        if len(list(syntax.split())) > 2:
            op, num1, num2 = map(str, syntax.split())
            num1 = int(num1); num2 = int(num2)
        else:
            num1, num2 = map(str, syntax.split())
            num1 = int(num1); num2 = int(num2)
        
        if op == 'a': 
            write = "%d+%d=%d" % (num1, num2, num1+num2)
            buffer.write("%s\n%d\n" % (write, len(write)))
        elif op == 'b':
            write = "%d-%d=%d" % (num1, num2, num1-num2)
            buffer.write("%s\n%d\n" % (write, len(write)))
        elif op == 'c':
            write = "%d*%d=%d" % (num1, num2, num1*num2)
            buffer.write("%s\n%d\n" % (write, len(write)))
        pass
    print(buffer.getvalue(), end="")


if __name__ == "__main__":
    main()