from io import StringIO
from sys import stdin


def input(): return stdin.readline().strip()


buffer = StringIO()

T = int(input())
for _ in range(T):
    n = int(input())
    temp = 2
    for i in range(n-1, 1, -2):
        temp *= i
    buffer.write(f"{temp}\n")
print(buffer.getvalue(), end="")
