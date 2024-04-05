

q = []
grass = None
dx = [-2, -2, -1, +1, +2, +2, +1, -1]
dy = [-1, +1, +2, +2, +1, -1, -2, -2]

def bfs():
    global q,book
    step = 0
    while len(q):
        size = len(q)
        for _ in range(size):
            nodex, nodey = q.pop(0)
            if graph[nodex][nodey] == 'H': return step
            book[nodex][nodey] = True
            for i in range(8):
                nx,ny = nodex+dx[i], nodey+dy[i]
                if nx not in range(0,r) or ny not in range(0,c): continue
                if graph[nx][ny] == '*' or book[nx][ny]: continue
                book[nx][ny] = True
                q.append((nx,ny))
        step += 1


c, r = map(int, input().split())
book = [[False for _ in range(c)]for _ in range(r)]
graph = [[*map(str, input())] for _ in range(r)]

for i in range(r):
    for j in range(c):
        if graph[i][j] == 'K':
            q.append((i,j))
            break
    else: continue
    break

print(bfs())