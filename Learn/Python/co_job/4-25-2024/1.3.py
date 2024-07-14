# 定义文件名变量，便于将用户回答存储在文件中
filename = 'programming_poll.txt'

# 定义一个空列表，用于收集用户回答
responses = []
# 无限循环，收集用户们的回答以添加到用户回答列表中
while True:
    # 询问用户他们喜欢编程的原因
    response = input("\nWhy do you like programming? ")
    # 列表中新增用户回答
    responses.append(response)
    # 询问用户是否让其他人回答
    continue_poll = input("Would you like to let someone else respond?(y/n) ")
    # 如果用户的回答不是 'y'，即不想让其他人回答，退出循环
    if continue_poll != 'y': break

# 以续写模式打开文件
with open(filename, 'a') as f:
    # 将列表中的所有回答写入到文件的新行
    for response in responses: f.write(f"{response}\n")
