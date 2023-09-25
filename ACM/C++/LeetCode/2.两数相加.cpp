/*
 * @Author: KasperFan && fanwlx@foxmail.com
 * @Date: 2023-09-01 10:56:48
 * @LastEditTime: 2023-09-03 15:23:39
 * @FilePath: /C/OJ/LeetCode/2.两数相加.cpp
 * @describes: This file is created for solving OJ problems.
 * Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *head = nullptr, *tail = nullptr;
        bool check = false;
        while (l1 || l2)
        {
            int op1 = l1 ? l1->val : 0, op2 = l2 ? l2->val : 0;
            int sum = op1 + op2 + (check ? 1 : 0);
            if (!head)
            {
                head = tail = new ListNode(sum % 10);
            }
            else
            {
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }
            check = sum / 10;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }
        if (check)
        {
            tail->next = new ListNode(1);
        }
        return head;
    }
};
