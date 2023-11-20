'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-11-05 15:33:15
LastEditTime: 2023-11-05 16:54:11
FilePath: /Python/WFUStudy/摸底/U56447_小猫爬山.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''
N: int
W: int
cats: list[int]
# is_used: list[bool] = [False] * 19
q: list = []
# cnt: int = 0
ans: int = 0
# def dfs(index: int, target: int):
#     global cats, q, cnt, ans
#     if cnt > W:
#         return
#     if cnt == W or target < cats[0]:
#         for i in q:
#             cats.pop(i)
#         ans += 1
#         return
#     elif sum(cats) <= W:
#         cats.clear()
#         ans += 1
#         return
#     for i in range(index, -len(cats)-1, -1):
#         cnt += cats[i]
#         q.append(i)
#         dfs(index-1, target-cnt)


# def dfs(index: int):
#     global cats, q, cnt, ans
#     if cnt == W or 
#     for i in range(index+1, N+1):

#     pass

def dfs(index:int, target: int):
    global cats, q, ans
    if target == 0 or target < cats[1]:
        for i in q:
            cats.pop(i)
        ans += 1
        return
    elif sum(cats) <= W:
        cats.clear()
        ans += 1
        return
    for i in range(index, 0, -1):
        if i not in range(len(cats)):
            continue
        if cats[i] in range(1,target+1):
            q.append(i)
            dfs(i-1, target-cats[i])
            return



N, W = map(int, input().split())
cats = [0]+[int(input()) for _ in range(N)]
cats.sort()
while len(cats) > 1:
    dfs(len(cats)-1, W)
print(ans)
