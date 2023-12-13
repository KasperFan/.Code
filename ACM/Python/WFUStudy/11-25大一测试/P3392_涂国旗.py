'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-11-30 19:54:40
LastEditTime: 2023-11-30 20:08:05
FilePath: /Python/WFUStudy/11-25大一测试/P3392_涂国旗.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''
from sys import stdin


def input(): return stdin.readline().strip()


def main() -> int:
    minAns = 0x4f4f4f4f
    n, m = map(int, input().split())
    arr = [" "]+[([" "]+list(map(str, input()))) for _ in range(n)]
    for write in range(1, n-1):
        for blue in range(write+1, n):
            ans = 0

            for i in range(1, write+1):
                for j in range(1, m+1):
                    if arr[i][j] != 'W': ans += 1

            for i in range(write+1, blue+1):
                for j in range(1, m+1):
                    if arr[i][j] != 'B': ans += 1

            for i in range(blue+1, n+1):
                for j in range(1, m+1):
                    if arr[i][j] != 'R': ans += 1

            minAns = minAns if minAns < ans else ans
    print(minAns)
    return 0


if __name__ == "__main__":
    main()
