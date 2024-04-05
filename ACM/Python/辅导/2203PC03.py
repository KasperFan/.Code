from sys import stdin

input = lambda: stdin.readline().strip()

ans = 0
N = int(input())
sets = set(map(int, input().split(',')))
for i in sets:
    if N-i != i and N-i in sets: ans += 1
print(ans//2)