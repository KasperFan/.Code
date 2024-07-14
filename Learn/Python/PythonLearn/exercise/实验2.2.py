import random

c1 = c2 = 0
for i in range(50):
    d1 = d2 = 0
    for j in range(6):
        d1 = d1 + random.randint(1, 6)
        d2 = d2 + random.randint(1, 6)
        if d1 > d2: c1 += 1
        elif d1 < d2: c2 += 1
if c1 > c2: print('\n玩家一胜利。')
elif c1 < c2: print('\n玩家二胜利。')
else: print('\n平局。')
