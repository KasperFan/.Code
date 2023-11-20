'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-10-22 14:33:30
LastEditTime: 2023-10-23 08:09:06
FilePath: /Python/WFUStudy/第一次检验/B3664_[语言月赛202209]_零食售卖点.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''
import sys
def input(): return sys.stdin.readline()


def quick_sort(a, left, right):
    if left >= right:
        return a
    i = left
    j = right
    # 定义基准,基准左边小于基数,右边大于基数
    pivot = a[left]
    while i < j:
        # 从后向前扫描
        while i < j and a[j] > pivot:
            j -= 1
        a[i] = a[j]
        # 从前向后扫描
        while i < j and a[i] < pivot:
            i += 1
        a[j] = a[i]
    a[j] = pivot

    # 分段排序
    quick_sort(a, left, j-1)
    quick_sort(a, j+1, right)

    return a


if __name__ == "__main__":
    k: int = int(input())
    maxCnt: int = 0
    a: list = [int(i) for i in input().split()]
    ans = quick_sort(a, 0, len(a)-1)
    for i in range(len(ans)-1, 0, -1):
        maxCnt = ans[i]-ans[i-1] if maxCnt < ans[i]-ans[i-1] else maxCnt
    print(maxCnt)
