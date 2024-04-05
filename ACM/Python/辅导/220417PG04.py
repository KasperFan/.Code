from sys import stdin

input = lambda: stdin.readline().strip()

N = int(input())
count = list(map(int, input().split(',')))
for i in range(len(count)):
    if count[i] == 0: continue
    elif count[i] % 3 == 0 or '3' in str(count[i]): print(i%N+1); exit(0)