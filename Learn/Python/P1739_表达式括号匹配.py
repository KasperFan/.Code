sentences = input()
cnt: int = 0
chk: bool = True
for i in sentences:
    cnt += 0 if i != "(" and i != ")" else -1 if i == ")" else 1
    if cnt == -1:
        chk = False
chk = True if (chk != False and cnt == 0) else False
print(cnt, "YES" if chk else "NO")
# is not
