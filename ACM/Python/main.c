#include <stdio.h>
#include <stdlib.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode
{
    int val;
    struct ListNode *next;
};

void freeList(struct ListNode *list)
{
    if (list->next != NULL)
        freeList(list->next);
    free(list);
}

void addNode(struct ListNode *list, int value)
{ // 作用：向list的末尾添加一个值为value的节点
    struct ListNode *p = list;
    while (p->next != NULL)
        p = p->next; // 找到最后一个点
    struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode *));
    node->next = NULL;
    node->val = value;
    p->next = node;
}

struct ListNode *initList1()
{
    struct ListNode *List1 = (struct ListNode *)malloc(sizeof(struct ListNode *));
    List1->next = NULL;
    List1->val = 1;
    addNode(List1, 2);
    addNode(List1, 4);
    return List1;
}

struct ListNode *initList2()
{
    struct ListNode *List2 = (struct ListNode *)malloc(sizeof(struct ListNode *));
    List2->next = NULL;
    List2->val = 1;
    addNode(List2, 3);
    addNode(List2, 4);
    return List2;
}

struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2)
{
    struct ListNode *p = list1;
    struct ListNode *q = list2;
    struct ListNode *head = NULL;
    struct ListNode *tail = NULL;
    while (p != NULL && q != NULL)
    {
        if (q->val <= p->val)
        {
            if (head == tail)
            {
                head = tail = q;
            }
            else
            {
                tail->next = q;
                tail = tail->next;
            }
            q = q->next;
        }
        else
        {
            if (head == tail)
                head = tail = p;
            else
            {
                tail->next = p;
                tail = tail->next;
            }
            p = p->next;
        }
    }
    while (p != NULL)
    {
        tail->next = p;
        tail = tail->next;
        p = p->next;
    }
    while (q != NULL)
    {
        tail->next = q;
        tail = tail->next;
        q = q->next;
    }
    return head;
}

int main(int argc, char const *argv[])
{
    struct ListNode *List1 = initList1();
    struct ListNode *List2 = initList2();
    struct ListNode *resultList = mergeTwoLists(List1, List2);
    struct ListNode *p = resultList;
    while (p != NULL)
    {
        printf("%d, ", p->val);
        p = p->next;
    }

    freeList(resultList);

    return 0;
}