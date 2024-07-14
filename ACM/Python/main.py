# '''
# Author: KasperFan && fanwlx@foxmail.com
# Date: 2024-01-06 14:38:09
# LastEditTime: 2024-02-02 10:31:50
# FilePath: /Python/main.py
# describes: This file is created for learning Python to deal OJ problems.
# Copyright (c) 2024 by KasperFan in WFU, All Rights Reserved. 
# '''
# # import sys
# # from datetime import datetime

# # sys.stdin = open("./test.txt", mode="r")

# # def input(): return sys.stdin.readline().strip()


# # start_time = datetime.now()

# # flag = False
# # book = [[False for _ in range(int(1e5))]for _ in range(int(1e5))]
# # dx = [-1, 1, 0, 0]; dy = [0, 0, -1, 1]


# # def dfs(x, y):
# #     global book, pr, flag
# #     if graph[x][y] > 1 and not flag: pr += 1; flag = True
# #     book[x][y] = True
# #     for i in range(4):
# #         nx = x+dx[i]
# #         ny = y+dy[i]
# #         if nx not in range(0, n) or ny not in range(0, m) or book[nx][ny] or graph[nx][ny] == 0: continue
# #         dfs(nx, ny)
# #     return


# # n, m = map(int,input().split())
# # graph = [[*map(int, input())] for _ in range(n)]
# # ans = pr = 0
# # for i in range(n):
# #     for j in range(m):
# #         if graph[i][j] == 0 or book[i][j]: continue
# #         flag = False
# #         ans += 1
# #         dfs(i, j)
# # print(ans, pr)

# # end_time = datetime.now()
# # print("运行时间：", end_time - start_time)

# # class People:
# #     def __init__(self, name, sex, idNumber) -> None:
# #         self.name = name
# #         self.sex = sex
# #         self.idNumber = idNumber
# #         pass

# #     def sayHello(self) -> None:
# #         print(f"你好，我是{self.name}，我的身份证号码是{self.idNumber}")


# # # 张三 未知 123456
# # # people = People("张三", "未知", "123456")
# # people = People(*input().split())
# # people.sayHello()

# # X, Y, M = map(int, input().split(','))
# # boxes = [-1 for _ in range(M+1)]
# # boxes[0] = 1
# # boxes[1] = 1 if X != 1 or Y != 1 else 0
# # for i in range(2, M+1):
# #     if i == X or i == Y: boxes[i] = 0
# #     else: boxes[i] = boxes[i-1] + boxes[i-2]
# # print(boxes[M])
# # for i in range(1, M+1): print(i, end="\t")
# # print()
# # for i in boxes[1:]: print(i, end="\t")
# # print()

# # from math import *
# # n = int(input())

# # for i in range(2, n+1):
# #     chk = 1
# #     root = sqrt(i)
# #     for j in range(2, int(root)):
# #         if i % j == 0: chk += (j + (i // j))
# #     if root - int(root) == 0: chk -= int(root)
# #     if chk == i: print(i)

# # from math import sqrt
# # S = int(input())


# # def is_prime(num):
# #     if num == 1:
# #         return False
# #     if num == 2 or num == 3 or num == 5 or num == 7:
# #         return True
# #     if num % 2 == 0 or num % 3 == 0 or num % 5 == 0 or num % 7 == 0:
# #         return False
# #     for i in range(11, int(sqrt(num))+1, 2):
# #         if num % i == 0:
# #             return False
# #     return True


# # ans = 0
# # for a in range(1, S//2 + 1):
# #     if not is_prime(a):
# #         continue
# #     b = S - a
# #     if not is_prime(b):
# #         continue
# #     if a*b > ans:
# #         ans = a*b
# # print(ans)

# # print(
# # '''                ********
# #                ************
# #                ####....#.
# #              #..###.....##....
# #              ###.......######              ###            ###
# #                 ...........               #...#          #...#
# #                ##*#######                 #.#.#          #.#.#
# #             ####*******######             #.#.#          #.#.#
# #            ...#***.****.*###....          #...#          #...#
# #            ....**********##.....           ###            ###
# #            ....****    *****....
# #              ####        ####
# #            ######        ######
# # ##############################################################
# # #...#......#.##...#......#.##...#......#.##------------------#
# # ###########################################------------------#
# # #..#....#....##..#....#....##..#....#....#####################
# # ##########################################    #----------#
# # #.....#......##.....#......##.....#......#    #----------#
# # ##########################################    #----------#
# # #.#..#....#..##.#..#....#..##.#..#....#..#    #----------#
# # ##########################################    ############'''
# # )



# # T, M = map(int, input().split())
# # dp = [[0 for _ in range(T+1)] for _ in range(M+1)]
# # Times = [0 for _ in range(M+1)]; Values = [0 for _ in range(M+1)]
# # for i in range(1, M+1): Times[i], Values[i] = map(int, input().split())
# # for i in range(1, M+1):
# #     for j in range(T, 0, -1):
# #         if j >= Times[i]: dp[i][j] = max(dp[i-1][j], dp[i-1][j-Times[i]]+Values[i])
# #         else: dp[i][j] = dp[i-1][j]
# # print(dp[M][T])


# '''
# Author: KasperFan && fanwlx@foxmail.com
# Date: 2023-10-28 16:35:13
# LastEditTime: 2023-10-29 10:19:21
# FilePath: /Python/OJ/LuoGu/搜索/P2036_PERKET.py
# describes: This file is created for learning Python to deal OJ problems.
# Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
# '''
# import sys
# import math
# def input(): return sys.stdin.readline()


# def dfs(which):
#     global ans, S, B
#     S *= s[which]
#     B += b[which]
#     ans = int(math.fabs(S-B)) if int(math.fabs(S-B)) < ans else ans
#     for i in range(which+1, n+1): dfs(i)
#     S //= s[which]
#     B -= b[which]


# S, B = 1, 0
# ans: int = 0x4f4f4f4f

# n = int(input())
# s = [1 for _ in range(n+1)]
# b = [0 for _ in range(n+1)]
# for i in range(1, n+1): s[i], b[i] = map(int, input().split())
# dfs(0)
# print(ans)

# from sys import stdin
# from io import StringIO


# def input(): return stdin.readline().strip()


# buffer = StringIO()

# c = [0 for _ in range(int(1e5+1))]
# n = int(input())
# a = [0] + [*map(int, input().split())]
# for i in range(1, n+1):
#     c[i] = c[i-1]+a[i]
# m = int(input())
# for _ in range(m):
#     l, r = map(int, input().split())
#     buffer.write(f"{c[r]-c[l-1]}\n")
# print(buffer.getvalue(), end="")

# from sys import stdin
# from io import StringIO


# input = lambda: stdin.readline().strip()
# buffer = StringIO()

# class Coin:
#     def __init__(self, m, v):
#         self.m = m
#         self.v = v
#         self.p = self.v/self.m

# ans = 0
# N, T = map(int, input().split())
# coins = [Coin(*map(int, input().split())) for _ in range(N)]
# coins.sort(key=lambda o: o.p, reverse=True)
# while T > 0:
#     coin = coins.pop(0)
#     m, v, p = coin.m, coin.v, coin.p
#     if T >= m: ans+=v; T-=m
#     else: ans+=p*T; T = 0
# print(format(ans, ".2f"))

# from sys import stdin
# from io import StringIO

# input = lambda: stdin.readline().strip()
# buffer = StringIO()

# class Apple:
#     def __init__(self, x, y): self.x = x; self.y = y

# ans = 0
# n, s = map(int, input().split())
# a, b = map(int, input().split())
# apples = [Apple(*map(int, input().split())) for _ in range(n)]
# apples.sort(key=lambda apple: apple.y)
# for apple in apples:
#     if apple.x <= a+b and apple.y <= s: ans+=1; s-=apple.y
#     if s < apple.y: break
# print(ans)


# from sys import stdin
# from io import StringIO

# input = lambda: stdin.readline().strip()
# buffer = StringIO()

# def dfs(x, y):
#     global graph
#     graph[x][y] = 0
#     for i in range(4):
#         nx, ny = x+dx[i], y+dy[i]
#         if nx not in range(n+2) or ny not in range(n+2) or graph[nx][ny] == 1 or graph[nx][ny] == 0: continue
#         dfs(nx, ny)


# dx = [-1, +1, 0, 0]; dy = [0, 0, -1, +1]    

# n = int(input())
# graph = [[0 for _ in range(n+2)]] + [([0] + [*map(int, input().split())] + [0]) for _ in range(n)] + [[0 for _ in range(n+2)]]
# for i in range(n+2):
#     for j in range(n+2): graph[i][j] = 2 if graph[i][j] == 0 else graph[i][j]
# dfs(0, 0)
# for i in range(1, n+1):
#     for j in range(1, n+1): buffer.write(f"{graph[i][j]} ")
#     buffer.write("\n")
# print(buffer.getvalue(), end="")

# from sys import stdin
# from io import StringIO

# input = lambda: stdin.readline().strip()
# buffer = StringIO()

# class Classmate:
#     def __init__(self, name, year, month, day) -> None:
#         self.name = name
#         self.year = int(year)
#         self.month = int(month)
#         self.day = int(day)
#         self.chk = int(year)*365+int(month)*30+int(day)
    
#     def __str__(self) -> str:
#         return "%s %d %d %d" % (self.name, self.year, self.month, self.day)

# n = int(input())
# classmates = [Classmate(*input().split()) for _ in range(n)]
# for i in range(0, n-1):
#     for j in range(0, n-1-i):
#         if classmates[j].chk >= classmates[j+1].chk:
#             classmate = classmates[j]; classmates[j] = classmates[j+1]; classmates[j+1] = classmate
# # print()
# for i in classmates:
#     print(i.name)

# # 蜗牛
# from sys import stdin
# from io import StringIO

# input = lambda: stdin.readline().strip()

# def dfs(x, y):
#   global graph, ans
#   if x == len(graph)-1 and y == len(graph[x])-1: ans += 1; return
#   graph[x][y] = 1
#   for i in range(3):
#     nx, ny = x + dx[i], y + dy[i]
#     if nx not in range(len(graph)) or ny not in range(len(graph[nx])) or graph[nx][ny] == 1 or graph[nx][ny] == -1:
#       continue
#     dfs(nx, ny)
#   graph[x][y] = 0
#   pass


# ans = 0
# dx = [+1, +1, 0]; dy = [0, +1, +1]
# graph = []
# N = int(input())
# for i in range(N//2):
#   graph.append([0]*(N-abs(N//2-i)))
# graph.append([0] * N)
# for i in range(N//2+1, N):
#   graph.append([-1]*(i-N//2)+[0]*(N-abs(N//2-i)))
# dfs(0, 0)
# print(ans)



# # 部门开会
# from sys import stdin
# from io import StringIO

# input = lambda: stdin.readline().strip()

# def max_departments(plans):
#   # 按照结束时间对部门计划进行排序
#   plans.sort(key=lambda x: x[1])
#   # 初始化结果为0
#   result = 0
#   # 初始化上一个选择的部门的结束时间为8点
#   last_end = 8
#   # 遍历所有部门计划
#   for start, end in plans:
#     # 如果当前部门的开始时间晚于上一个部门的结束时间，说明可以选择这个部门
#     if start >= last_end:
#       # 更新结果和上一个部门的结束时间
#       result += 1
#       last_end = end
#   # 返回结果
#   return result


# # 读取输入
# N = int(input())  # 部门数量
# plans = [tuple(map(int, input().split())) for _ in range(N)]  # 部门计划列表

# # 调用函数，输出结果
# print(max_departments(plans))


# ## 食材
# from sys import stdin
# from io import StringIO

# input = lambda: stdin.readline().strip()

# # 定义一个函数，接受一个食材数量N和一个食材对列表pairs，返回最多能有多少种食材
# def max_ingredients(N, pairs):
#   # 初始化一个邻接矩阵，表示食材之间的关系，0表示没有边，1表示有边
#   adj = [[0] * N for _ in range(N)]
#   # 遍历所有的食材对，更新邻接矩阵
#   for x, y in pairs:
#     # 食材编号从1开始，所以要减1
#     x -= 1
#     y -= 1
#     # 无向图，所以两个方向都要更新
#     adj[x][y] = 1
#     adj[y][x] = 1
#   # 初始化一个结果变量，表示最大独立集的大小
#   result = 0
#   # 初始化一个状态变量，表示当前选择的食材集合，用二进制表示，第i位为1表示选择第i个食材
#   state = 0
#   # 遍历所有可能的状态，共有2^N种
#   for state in range(1 << N):
#     # 初始化一个标志变量，表示当前状态是否合法，即没有相邻的食材
#     valid = True
#     # 初始化一个计数变量，表示当前状态选择了多少种食材
#     count = 0
#     # 遍历所有的食材
#     for i in range(N):
#       # 如果当前状态选择了第i个食材
#       if state & (1 << i):
#         # 计数加1
#         count += 1
#         # 遍历所有的食材
#         for j in range(N):
#           # 如果当前状态选择了第j个食材，并且第i个和第j个食材有边，即会产生副作用
#           if state & (1 << j) and adj[i][j]:
#             # 标志设为False，表示当前状态不合法，退出循环
#             valid = False
#             break
#         # 如果标志为False，退出循环
#         if not valid:
#           break
#     # 如果标志为True，表示当前状态合法，更新结果
#     if valid:
#       result = max(result, count)
#   # 返回结果
#   return result

# # 读取输入
# N, M = map(int, input().split()) # 食材数量和食材对数
# pairs = [] # 食材对列表
# for _ in range(M):
#   # 读取每对食材
#   x, y = map(int, input().split())
#   # 添加到食材对列表
#   pairs.append((x, y))

# # 调用函数，输出结果
# print(max_ingredients(N, pairs))


m,n = map(int,input().split())
#graph = [[0 for _ in range(n+2)]for _ in range(m+2)]
#is_visited = [[False for _ in range(m+2)]for _ in range(n+2)]
ls = [[*map(int, input().split())] for _ in range(n)]
dx = [0,0,1,-1]
dy = [1,-1,0,0]
ans = 0

def dfs(x,y):
    # global ls
    ls[x][y] = 0
    #global graph,is_visited,list1
    for i in range(4):
        nx = x+dx[i]
        ny = y+dy[i]
        if nx not in range(m) or ny not in range(n) or ls[nx][ny] == 0:continue
        dfs(nx,ny)

for i in range(n):
    for j in range(m):
        if ls[i][j]==1:
            ans += 1
            dfs(i,j)
        # elif ls[i][j] =='0':
        #     dfs(i,j)
print(ans)