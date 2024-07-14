"""
1.用户信息存储在文件中。
2.注册时判断用户是否已存在。
3.登录时比较用户的登录信息与文件中存储的信息是否一致。
（不使用正则，用文件读写函数和字符串操作相关知识实现）
4.退出
"""
import os


def welcome():
    # 用户注册 用户登录 退出
    op = [0, register, login, exi]
    while True:
        print("欢迎使用账户管理程序",
              "1.用户注册",
              "2.用户登录",
              "3.退出", sep='\n')
        try:
            option = int(input("请选择功能:"))
            assert 0 < option <= 3
            op[option]()
        except AssertionError: pass
        except ValueError: pass



# 将文件中的数据转换为字典
def convert_data():
    info_li = []
    with open('./info.txt', mode='r+', encoding='utf8') as f:
        info_data = f.readlines()
        for i in info_data:
            info_dict = dict()
            # 替换{ 和 } 并去掉空格
            step_one = i.replace('{', '').replace('}', '')
            # 以冒号进行分隔
            step_two = step_one.split(':')
            # 拼接字典
            info_dict["姓名"] = step_two[1].split(',')[0].replace("'", '').strip()
            info_dict["密码"] = step_two[2].replace("'", '').strip()
            # 保存到列表中
            info_li.append(info_dict)
    return info_li


# 注册
def register():
    if not os.path.exists('./info.txt'):
        with open('./info.txt', mode='w', encoding='utf8') as f:
            f.write('')
    # 用户名列表
    name_li = []
    info_li = convert_data()
    # 接收注册信息
    person_info = {}
    name = input("请输入注册用户名：\n")
    # 获取用户列名列表
    for i in info_li:
        name_li.append(i['姓名'])
    # 判断用户是否存在
    if name in name_li:
        print('用户已注册')
    else:
        password = input("请输入注册密码：\n")
        person_info['姓名'] = name
        person_info['密码'] = password
        # 写入注册信息
        with open('./info.txt', mode='a+', encoding='utf8') as info_data:
            info_data.write(str(person_info) + '\n')

# 登录
def login():
    if os.path.exists('./info.txt') is not True:
        print('当前无数据，请先注册')
    else:
        # 用户名列表
        name_li = []
        info_li = convert_data()
        name = input("请输入登录用户名：\n")
        password = input("请输入登录密码：\n")
        # 获取用户列名列表
        for i in info_li:
            name_li.append(i['姓名'])
        # 判断用户是否存在
        if name in name_li:
            # 获取修改用户的索引
            modify_index = name_li.index(name)
            # 判断密码是否正确
            if password == info_li[modify_index]['密码']:
                print('登录成功')
            else:
                print('用户名或密码不正确')
        else:
            print('用户名或密码不正确')

# 退出
def exi(): print('退出登录'); exit(0)

if __name__ == '__main__':
    welcome()
