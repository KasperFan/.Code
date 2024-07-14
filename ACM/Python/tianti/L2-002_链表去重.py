import os
import sys
import math
import io
import heapq
import queue

class LinkNode:
    def __init__(self, di, val, ne) -> None:
        self.di, self.val, self.ne = di, val, ne
        pass

q = [[] for _ in range(int(1e6))]
co = []
# linkli = {}

head, N = map(int, input().split())
for _ in range(N):
    di, key, ne = map(int, input().split())
    q[di] = LinkNode(di, key, ne)

# p = head

# while


