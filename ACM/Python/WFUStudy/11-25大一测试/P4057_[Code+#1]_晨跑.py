'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-11-28 19:31:17
LastEditTime: 2023-11-29 22:07:28
FilePath: /Python/WFUStudy/11-25大一测试/P4057_[Code+#1]_晨跑.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''


def gcd(*integers) -> int:
    if not integers: return 0
    
    def _gcd(x, y) -> int:
        if x%y == 0: return y
        else: return _gcd(y, x % y)
    
    answer: int = integers[0]
    for i in range(1, len(integers)): answer = _gcd(answer, integers[i])
    return answer


def lcm(*integers) -> int:
    if not integers: return 0
    
    def _lcm(x, y) -> int:
        return (x * y) // gcd(x, y)
    
    answer = integers[0]
    for i in range(1, len(integers)):
        answer = _lcm(answer, integers[i])
    return answer

def main() -> int:
    print(lcm(*map(int, input().split())))
    return 0


if __name__ == "__main__":
    main()
