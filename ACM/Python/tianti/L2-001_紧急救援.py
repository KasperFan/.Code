import os
import sys
import math
import io
import heapq
import queue

buffer = io.StringIO()

input = lambda: sys.stdin.readline().strip()

q = []

def dijkstra(s:int):
    global q, d, vis, n, dianquan, ans, path
    d[s] = 0
    ans[s] = 1
    path[s] = -1
    dianquan[s] = n[s]
    heapq.heappush(q, (0, s))
    while q:
        _, u = heapq.heappop(q)
        if vis[u]: continue
        vis[u] = 1
        for ed in e[u]:
            v, w = ed
            if d[v] > d[u]+w:
                d[v] = d[u]+w
                dianquan[v] = dianquan[u] + n[v]
                ans[v] = ans[u]
                path[v] = u
                heapq.heappush(q, (d[v], v))
            elif d[v] == d[u]+w:
                ans[v] += ans[u]
                if dianquan[v] < dianquan[u] + n[v]:
                    dianquan[v] = dianquan[u] + n[v]
                    path[v] = u
    buffer.write("%d %d\n" % (ans[D], dianquan[D]))

def print_path(t):
    global buffer
    q = queue.LifoQueue()
    while t != -1:
        q.put(t)
        t = path[t]
    while q:
        buffer.write("%d " % q.get())
    # buffer.

N, M, S, D = map(int, input().split())
e = [[] for _ in range(N)]
dianquan = [0 for _ in range(N)]
path = [0 for _ in range(N)]
d = [math.inf for _ in range(N)]
vis = [0 for _ in range(N)]
ans = [0 for _ in range(N)]

n = [*map(int, input().split())]
for _ in range(M):
    u, v, w = map(int, input().split())
    e[u].append((v, w))
    e[v].append((u, w))

dijkstra(S)
print_path(D)


