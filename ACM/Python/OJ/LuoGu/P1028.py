# from functools import *

# res = [0 for _ in range(1010)]

# def get(n: int) -> int:
#     global res
#     if not res[n]:
#         if n in (1, 2): res[n] = n
#         elif n%2 == 1: res[n] = get(n-1)
#         else: res[n] = get(n-1)+get(n//2)
#     return res[n]
    

# def main():
#     n = int(input())
#     print(get(n))

# if __name__ == "__main__":
#     main()

info = {1: '小明', 2:'小黄',3:'小兰'}
name = info.get(4,'小红') 
name2 = info.get(1) 
print(name) 
print(name2)