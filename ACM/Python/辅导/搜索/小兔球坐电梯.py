def bfs():
    global count,q
    count = 0
    q.append(a)
    while len(q):
        length = len(q)
        for i in range(length):
            nx_ = q.pop(0)
            if nx_ == b:
                return count
            #for i in range(4):
                



n, a, b = map(int,input().split())
count = 0
q = []
floor = list(map(int,input().split()))
dx = []
