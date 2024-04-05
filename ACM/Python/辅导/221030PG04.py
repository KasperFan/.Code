from sys import stdin

input = lambda: stdin.readline().strip()

balance = 0
N = int(input())
jums = list(map(int, input().split()))
L, R = map(int, input().split())
for i in range(N):
    if jums[i]>R: balance+=jums[i]-R
    elif jums[i]<L: balance+=jums[i]-L
    