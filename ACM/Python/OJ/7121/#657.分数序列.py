
import sys


def input(): return sys.stdin.readline()
def print(data): return sys.stdout.write(data)


fi: list = [0]*110
fi[1] = fi[2] = 1
sum: float = 0

if __name__ == "__main__":
    n: int = int(input())
    for i in range(2, n+2):
        fi[i+1] = fi[i-1]+fi[i]
        sum += fi[i+1]/fi[i]
    print("%.6f\n" % sum)
