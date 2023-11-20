'''
Author: KasperFan && fanwlx@foxmail.com
Date: 2023-11-04 23:28:32
LastEditTime: 2023-11-04 23:44:51
FilePath: /Python/OJ/LeetCode/1.两数之和.py
describes: This file is created for learning Python to deal OJ problems.
Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
'''


class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        chk: dict = dict()
        ans: list
        for i in range(len(nums)):
            chk.update({nums[i]: i})
        for i in range(len(nums)):
            if target - nums[i] in chk and chk.get(target-nums[i]) != i:
                ans = [i, chk.get(target-nums[i])]
                break
        return []
