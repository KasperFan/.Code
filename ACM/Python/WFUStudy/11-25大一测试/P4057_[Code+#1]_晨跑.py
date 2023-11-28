'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-11-28 19:31:17
LastEditTime: 2023-11-28 19:32:31
FilePath: /Python/WFUStudy/11-25大一测试/P4057_[Code+#1]_晨跑.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''
from math import lcm


def main() -> None:
    print(lcm(*map(int, input().split())))


if __name__ == "__main__":
    main()
