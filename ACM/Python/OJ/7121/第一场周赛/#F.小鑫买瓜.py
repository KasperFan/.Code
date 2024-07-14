cnt = 0
L, R, w1, w2 = map(int,input().split())
if L > R:
    L += R
    R = L - R
    L -= R
for i in range(L, R+1):
    if i % w1 != 0 and i % w2 != 0:
        cnt += 1
print(cnt)