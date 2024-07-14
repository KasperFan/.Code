# # filename = 'pi_million_digits.txt'

# # with open(filename) as f:
# #     lines = f.readlines()

# # pi_string = ''
# # for line in lines:
# #     pi_string += line.strip()

# # name = input('请输入你的真实姓名：')
# # birthday = input('请输入你的生日，（如输入0705表示7月5日）：')
# # if birthday in pi_string:
# #     print(f"恭喜你，{name}，你的生日包含在 π 中")
# # else:
# #     print(f"抱歉，{name}，你的生日不包含在 π 中")


# # filename = 'pi_million_digits.txt'

# # with open(filename) as file:
# #     lines = file.readlines()

# # pi_string = ''
# # for line in lines: pi_string += line.strip()

# name = input('请输入你的姓名：')
# day = input(f"{name}请输入你的生日：")
# # if day in pi_string:
# #     print(f"恭喜你，{name}，你的生日包含在π中")
# # else: print(f"抱歉，{name}，你的生日不包含在π中")
filename = 'pi_million_digits.txt'

with open(filename) as file:
    lines = file.readlines()

pi_string = ''
for line in lines:
    pi_string += line.strip()

name = input('请输入你的姓名：')
day = input(f"你好，{name}，请输入你的生日：")
if day in pi_string:
    print(f"恭喜你，{name}，你的生日包含在π中")
else:
    print(f"抱歉，{name}，你的生日不包含在π中")
