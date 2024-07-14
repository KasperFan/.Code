import random

data = open("./data.txt", 'r').readlines()
cse = set()
length = random.randint(0, len(data)-1)
print(length)