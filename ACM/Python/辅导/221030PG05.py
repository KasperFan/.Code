from sys import stdin

input = lambda: stdin.readline().strip()


# 关系添加
def add(x, y, nx, ny):
    global indegree, outdegree, edge
    # 由于存在关系：当前点(x, y) -> 可达点(nx, ny)
    # 所以存在一条从点(x, y)出发到点(nx, ny)的边，故点(x, y)的出度+1，点(nx, ny)的入度+1
    indegree[nx][ny] += 1; outdegree[x][y] += 1
    # 将可达点(nx, ny)添加至当前点(x, y)的可达队列中
    edge[x*M+y].append((nx, ny)) # 二维坐标一维化

# 拓扑排序
def topoSort():
    global q
    # 遍历整个图，发现某个点入度为0，将其添加至拓扑排序队列q
    for i in range(N):
        for j in range(M):
            if indegree[i][j] == 0: q.append((i, j))
    
    step = 0 # 最长步计数
    while len(q) > 0:  # 当拓扑排序队列不为空
        size = len(q) # 取当前队列元素个数
        for _ in range(size): # 重复size次，对当前阶段点做处理
            x, y = q.pop(0) # 取出当前队首元素
            # 快捷写法（元组）
            for i, j in edge[x*M+y]:
                # 结算该边入度关系
                indegree[i][j] -= 1
                # 如果该点的入度为0，则
                if indegree[i][j] == 0: q.append((i, j))
        step += 1 # 结算完当前阶段所有点后，将最长步数+1
    return step # 返回结果


dx = [-1, +1, 0, 0]; dy = [0, 0, -1, +1] # 坐标偏移
indegree = [[0 for _ in range(1000)] for _ in range(1000)] # 记录每个点对应的入度
outdegree = [[0 for _ in range(1000)] for _ in range(1000)] # 记录每个点对应的出度
edge = [[] for _ in range(1000*1000)] # 记录每个点四个方向的可达点
q = [] # 拓扑排序队列



N, M = map(int, input().split())
# 极简写法（列表推导式）
graph = [[*map(int, input().split())] for _ in range(N)]
# 等价写法1
# graph = [list(map(int, input().split())) for _ in range(N)]
# 等价写法2
# graph = list(list(map(int, input().split())) for _ in range(N))
for x in range(N):
    for y in range(M): # 遍历整个图
        # 遍历点(x, y)的四个方向，找可到达点
        for i in range(4):
            nx, ny = (x+dx[i], y+dy[i])
            # 下一点不满足条件，跳过
            if nx not in range(0, N) or ny not in range(0, M) or graph[nx][ny] >= graph[x][y]: continue
            add(x, y, nx, ny)
print(topoSort())
