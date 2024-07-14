from sys import stdin
def input(): return stdin.readline()


if __name__ == "__main__":
    n: int = int(input())
    maxL = maxR = indexL = indexR = 0
    total: int = 2**n
    half: int = total // 2
    countrys = [0]+[int(i) for i in input().split()]
    print(countrys)
    maxL = max(countrys[1:half])
    maxR = max(countrys[half+1:total])
    indexL = countrys.index(maxL)
    indexR = countrys.index(maxR)
    print(maxL, maxR, indexL, indexR)
    print(indexL if maxL < maxR else indexR)
