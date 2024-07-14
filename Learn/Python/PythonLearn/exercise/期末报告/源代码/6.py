# -*- coding: utf-8 -*-
# @FileCreateTime    : 2024/6/13 17:45
# @Author            : kasperfan
# @Site              : 
# @File              : 6.py
# @Path              : 
# @Software          : PyCharm 
# @Comment           :
import random, string, sys

random.seed(0x1010)
chars = string.ascii_letters+string.digits+"!@#$%^&*"
passwords = []
exclude = set()
while len(passwords) < 10:
    password = ""
    while len(password) < 10:
        password += random.choice(chars)
    if password[0] in exclude: continue
    exclude.add(password[0])
    passwords.append(password)
with open("../随机密码.txt", mode="w") as f:
    sys.stdout = f
    print(*passwords, sep="\n")
sys.stdout = sys.__stdout__
