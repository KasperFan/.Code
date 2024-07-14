import heapq
q = []

heapq.heappush(q, (3, 4))
heapq.heappush(q, (6, 5))
heapq.heappush(q, (7, 8))
heapq.heappush(q, (1, 9))

while q:
    print(heapq.heappop(q))