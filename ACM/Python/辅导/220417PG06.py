from sys import stdin

input=lambda: stdin.readline().strip()


dx = [-1, +1, 0, 0]
dy = [0, 0, -1, +1]

def dfs(x, y):
    global book
    book[x][y] = True
    for i in range(4):
        nx = x + dx[i]; ny = y + dy[i]
        if nx < 0 or nx >= N or ny < 0 or ny >= M or graph[nx][ny] == 'X' or book[nx][ny]: continue
        dfs(nx, ny)


ans = 0
book = [[False for _ in range(100)] for _ in range(100)]
N, M = map(int, input().split(','))
graph = [list(map(str, input().split(','))) for _ in range(N)]
for i in range(N):
    for j in range(M):
        if graph[i][j] == 'R' and not book[i][j]: ans+=1; dfs(i, j)
        pass
print(ans)
