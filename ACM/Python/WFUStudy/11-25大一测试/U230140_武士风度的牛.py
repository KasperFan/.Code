from sys import stdin
def input(): return stdin.readline().strip()


q: list[tuple] = []
map_view: list
is_visited = [[False for _ in range(151)] for _ in range(151)]
dx: list = [-2, -2, -1, +1, +2, +2, +1, -1]
dy: list = [-1, +1, +2, +2, +1, -1, -2, -2]

def bfs():
    global map_view, is_visited
    step = 0
    while (len(q) > 0):
        size = len(q)
        for _ in range(size):
            nodex, nodey = q.pop(0)
            if map_view[nodex][nodey] == 'H':
                return step
            for i in range(8):
                nx = nodex+dx[i]; ny = nodey+dy[i]
                if nx < 0 or nx >= R or ny < 0 or ny >= C:
                    continue
                if not is_visited[nx][ny] and map_view[nx][ny] != '*':
                    is_visited[nx][ny] = True
                    q.append((nx,ny))
        step += 1


if __name__ == "__main__":
    C, R = map(int, input().split())
    map_view = [list(map(str, input())) for _ in range(R)]
    for i in range(R):
        for j in range(C):
            if map_view[i][j] == 'K':
                q.append((i, j))
                is_visited[i][j] = True
                break
        else:
            continue
        break
    print(bfs())
