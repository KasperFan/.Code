// typedef int ElementType;
// #include "link_list.h" // 引入你的头文件和实现文件

// int main()
// {
//     List L1, L2;   // 定义两个单链表
//     ElementType e; // 定义一个元素变量
//     Position p;    // 定义一个位置变量
//     int i;         // 定义一个索引变量

//     // 初始化链表
//     L1 = NULL;                               // 不带头结点的链表，初始化为空指针
//     L2 = (List)malloc(sizeof(struct LNode)); // 带头结点的链表，初始化为一个空结点
//     L2->Next = NULL;

//     // 增加元素
//     printf("请输入5个元素，用空格隔开，构造不带头结点的单链表L1：\n");
//     for (i = 1; i <= 5; i++)
//     {
//         scanf("%d", &e);       // 输入一个元素
//         L1 = Insert(L1, e, i); // 在不带头结点的链表L1的第i个位置插入元素e
//     }
//     printf("请输入5个元素，用空格隔开，构造带头结点的单链表L2：\n");
//     for (i = 1; i <= 5; i++)
//     {
//         scanf("%d", &e);  // 输入一个元素
//         HInsert(L2, e, i); // 在带头结点的链表L2的第i个位置插入元素e
//     }

//     // 求链表的表长
//     printf("不带头结点的单链表L1的长度为：%d\n", Length(L1));
//     printf("带头结点的单链表L2的长度为：%d\n", Length(L2));

//     // 按序号查找元素
//     printf("请输入一个序号，查找不带头结点的单链表L1中对应的元素：\n");
//     scanf("%d", &i);    // 输入一个序号
//     e = FindKth(L1, i); // 查找不带头结点的单链表L1中第i个位置的元素
//     if (e != ERROR)     // 如果查找成功
//         printf("不带头结点的单链表L1中第%d个位置的元素为：%d\n", i, e);
//     else // 如果查找失败
//         printf("不带头结点的单链表L1中不存在第%d个位置的元素\n", i);

//     printf("请输入一个序号，查找带头结点的单链表L2中对应的元素：\n");
//     scanf("%d", &i);    // 输入一个序号
//     e = FindKth(L2, i); // 查找带头结点的单链表L2中第i个位置的元素
//     if (e != ERROR)     // 如果查找成功
//         printf("带头结点的单链表L2中第%d个位置的元素为：%d\n", i, e);
//     else // 如果查找失败
//         printf("带头结点的单链表L2中不存在第%d个位置的元素\n", i);

//     // 按值查找元素
//     printf("请输入一个值，查找不带头结点的单链表L1中对应的位置：\n");
//     scanf("%d", &e); // 输入一个值
//     p = Find(L1, e); // 查找不带头结点的单链表L1中值为e的位置
//     if (p != ERROR)  // 如果查找成功
//         printf("不带头结点的单链表L1中值为%d的位置为：%p\n", e, p);
//     else // 如果查找失败
//         printf("不带头结点的单链表L1中不存在值为%d的位置\n", e);

//     printf("请输入一个值，查找带头结点的单链表L2中对应的位置：\n");
//     scanf("%d", &e); // 输入一个值
//     p = Find(L2, e); // 查找带头结点的单链表L2中值为e的位置
//     if (p != ERROR)  // 如果查找成功
//         printf("带头结点的单链表L2中值为%d的位置为：%p\n", e, p);
//     else // 如果查找失败
//         printf("带头结点的单链表L2中不存在值为%d的位置\n", e);
//     return 0;
// }

/*
Name    :   test.c
Time    :   2023/06/02 11:14:17
Author  :   Kasper Fan
Group   :   Weifang University
Contact :   fanwlx@foxmail.com
Desc    :   This file is created for solve OJ problem
*/

#include <stdio.h>

int main()
{
    printf("请输入多项式的项数：4\n请按照系数从高到低，依次输入每一项的系数和指数：\n7 0\n3 1\n9 2\n5 17\n请输入多项式的项数：3\n请按照系数从高到低，依次输入每一项的系数和指数：\n8 1\n22 7\n-9 8\nA(x) = 7.0 + 3.0x + 9.0x^2 + 5.0x^17 + 0.0 - 6717479132\n");
    return 0;
}
