import sys


def input(): return sys.stdin.readline()


n: int
ans: int = 0

n = int(input())
for i in input().strip().split():
    ans ^= int(i)

print(ans)
