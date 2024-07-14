from sys import stdin
from io import StringIO

input = lambda: stdin.readline().strip()

buffer = StringIO()

N = int(input())
A = [*map(int,input().split())]
M = int(input())
B = [*map(int, input().split())]
L = int(input())
C = [*map(int, input().split())]
Q = int(input())
X = [*map(int, input().split())]
for i in X:
    if A[-1]+B[-1]+C[-1] < i: buffer.write("No\n"); continue
    flag = False
    for c in C[::-1]:
        if c > i: continue
        for b in B[::-1]:
            if c+b > i: continue
            for a in A[::-1]:
                if c+b+a > i: continue
                if a+b+c == i:
                    buffer.write("Yes\n")
                    flag = not flag
                    break
            if flag: break
        if flag: break
    if not flag:
        buffer.write("No\n")
print(buffer.getvalue(), end="")