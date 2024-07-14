import os, sys, io

input = lambda: sys.stdin.readline().strip()

buffer = io.StringIO()

def dfs(u, father):
    global dep, fa
    dep[u] = dep[father]+1

    fa[u][0] = father
    for i in range(1, 20):
        fa[u][i] = fa[fa[u][i-1]][i-1]
    
    for v in e[u]:
        if v != father: dfs(v, u)


def lca(u, v):
    if dep[u] < dep[v]: u,v = v,u

    for i in range(19, -1, -1):
        if dep[fa[u][i]] >= dep[v]: u = fa[u][i]
    
    if u == v: return u
    for i in range(19, -1, -1):
        if fa[u][i] != fa[v][i]:
            u, v = fa[u][i], fa[v][i]
    return fa[u][0]

N, M, S = map(int, input().split())
e = [[] for _ in range(N+1)]
dep = [0 for _ in range(N+1)]
fa = [[0 for _ in range(20)] for _ in range(N+1)]
for i in range(N-1):
    a, b = map(int, input().split())
    e[a].append(b)
    e[b].append(a)
dfs(S, 0)
for i in range(M):
    a, b = map(int, input().split())
    buffer.write(f'{lca(a, b)}\n')
print(buffer.getvalue(), end="")
