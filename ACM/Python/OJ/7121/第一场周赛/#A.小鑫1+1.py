temp = 0
ans: list = [0]*int(1e4+10)
point: int = int(1e4)
pinyin = ["ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"]
data = list(map(int, input()))
if data[0] == 0:
    print(pinyin[0])
    exit()
for i in data:
    temp += i
while temp > 0:
    ans[point] = temp % 10
    point -= 1
    temp //= 10
for i in range(point+1, int(1e4)+1):
    print(pinyin[ans[i]], end=' ')
