if __name__ == "__main__":
    n = int(input())
    minNum = 0x4f4f4f4f
    for i in input().split():
        minNum = int(i) if minNum > int(i) else minNum
    print(minNum)
