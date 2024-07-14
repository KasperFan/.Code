player_info = {}
li = []
print('输入quit表示选手成绩录入完毕')
while True:
    name = input("请输入选手名称：")
    if name == 'quit': break
    score = float(input("请输入选手票数："))
    player_info[name] = score
items = player_info.items()
li.extend([j[1], j[0]] for j in items)
# 转换为list类型，进行排序
li.sort(reverse=True)
# 输出排名
for i in range(1, len(li) + 1):
    print(f"第{i}名：{li[i-1][1]},成绩为{li[i-1][0]}分")
