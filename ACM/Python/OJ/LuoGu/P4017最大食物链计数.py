'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-03-15 16:17:19
LastEditTime: 2023-04-05 01:52:33
FilePath: /ACM/Python/P4017最大食物链计数.py
Description: This file is created for learning Code.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''
import sys
def input(): return sys.stdin.readline()

n, m = map(int, input().split())
mod = 80112002
edges = [[] for _ in range(n + 1)]
indegree = [0] * (n + 1)
outdegree = [0] * (n + 1)
for _ in range(m):
    a, b = map(int, input().split())
    edges[b].append(a)
    outdegree[a] += 1
    indegree[b] += 1

dp = [0] * (n + 1)
queue = []
for i in range(1, n + 1):
    if outdegree[i] == 0:
        queue.append(i)
        dp[i] = 1

while queue:
    node = queue.pop(0)
    for pre in edges[node]:
        dp[pre] += dp[node]
        dp[pre] %= mod
        outdegree[pre] -= 1
        if outdegree[pre] == 0:
            queue.append(pre)

ans = sum([dp[i] for i in range(1, n + 1) if indegree[i] == 0]) % mod
print(ans)


# 这道题目可以使用拓扑排序来解决。首先，我们可以将每个生物看作一个节点，每条食物链看作一条有向边。然后，我们可以使用拓扑排序来找到所有的入度为0的节点（即不会捕食其他生物的生产者），并将它们加入队列。
# 接下来，我们可以遍历队列中的每个节点，并更新它们所连接的节点的入度。如果某个节点的入度变为0，则将其加入队列。同时，我们可以使用动态规划来计算以该节点为终点的最大食物链数量。
# 具体地，设 $dp[i]$ 表示以第 $i$ 个节点为终点的最大食物链数量，则状态转移方程为 $dp[i] = \sum_{j \in pre[i]} dp[j]$，其中 $pre[i]$ 表示第 $i$ 个节点的所有前驱节点。
# 最后，我们遍历所有出度为0的节点（即不会被其他生物捕食的消费者），并累加它们对应的 $dp$ 值即可得到答案。
