#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/* 头文件 */
typedef struct LNode *PtrToLNode;
struct LNode
{
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;


/* 实现文件 */

// 求表长
int Length(List L)
{
    Position p;
    int cnt = 0; /* 初始化计数器 */

    p = L; /* p指向表的第一个结点 */
    while (p)
    {
        p = p->Next;
        cnt++; /* 当前p指向的是第cnt个结点*/
    }

    return cnt;
}

// 按序号查找
#define ERROR -1

ElementType FindKth(List L, int K)
{ /* 根据指定的位序K，返回L中相应元素 */
    Position p;
    int cnt = 1; /* 位序从1开始 */

    p = L; /* p指向L的第1个结点 */
    while (p && cnt < K)
    {
        p = p->Next;
        cnt++;
    }
    if ((cnt == K) && p)
        return p->Data; /* 找到第K个 */
    else
        return ERROR; /* 否则返回错误信息 */
}

// 按值查找
#define ERROR NULL

Position Find(List L, ElementType X)
{
    Position p = L; /* p指向L的第1个结点 */

    while (p && p->Data != X)
        p = p->Next;

    /* 下列语句可以用 return p; 替换 */
    if (p)
        return p;
    else
        return ERROR;
}

// 插入算法（不带头结点）
// #define ERROR NULL /* 用空地址表示错误 */

// List Insert(List L, ElementType X, int i)
// {
//     Position tmp, pre;

//     tmp = (Position)malloc(sizeof(struct LNode)); /* 申请、填装结点 */
//     tmp->Data = X;
//     if (i == 1)
//     { /* 新结点插入在表头 */
//         tmp->Next = L;
//         return tmp; /* 返回新表头指针 */
//     }
//     else
//     {
//         /* 查找位序为i-1的结点 */
//         int cnt = 1; /* 位序从1开始 */
//         pre = L;     /* pre指向L的第1个结点 */
//         while (pre && cnt < i - 1)
//         {
//             pre = pre->Next;
//             cnt++;
//         }
//         if (pre == NULL || cnt != i - 1)
//         { /* 所找结点不在L中 */
//             printf("插入位置参数错误\n");
//             free(tmp);
//             return ERROR;
//         }
//         else
//         { /* 找到了待插结点的前一个结点pre */
//             /* 插入新结点，并且返回表头L */
//             tmp->Next = pre->Next;
//             pre->Next = tmp;
//             return L;
//         }
//     }
// }

// 插入算法（带头结点）
bool Insert(List L, ElementType X, int i)
{ /* 这里默认L有头结点 */
    Position tmp, pre;
    int cnt = 0;

    /* 查找位序为i-1的结点 */
    pre = L; /* pre指向表头 */
    while (pre && cnt < i - 1)
    {
        pre = pre->Next;
        cnt++;
    }
    if (pre == NULL || cnt != i - 1)
    { /* 所找结点不在L中 */
        printf("插入位置参数错误\n");
        return false;
    }
    else
    { /* 找到了待插结点的前一个结点pre；若i为1，pre就指向表头 */
        /* 插入新结点 */
        tmp = (Position)malloc(sizeof(struct LNode)); /*申请、填装结点*/
        tmp->Data = X;
        tmp->Next = pre->Next;
        pre->Next = tmp;
        return true;
    }
}

// 删除元素（带头结点）
bool Delete(List L, int i)
{ /* 这里默认L有头结点 */
    Position tmp, pre;
    int cnt = 0;

    /* 查找位序为i-1的结点 */
    pre = L; /* pre指向表头 */
    while (pre && cnt < i - 1)
    {
        pre = pre->Next;
        cnt++;
    }
    if (pre == NULL || cnt != i - 1 || pre->Next == NULL)
    {
        /* 所找结点或位序为i的结点不在L中 */
        printf("插入位置参数错误\n");
        return false;
    }
    else
    { /* 找到了待删结点的前一个结点pre */
        /* 将结点删除 */
        tmp = pre->Next;
        pre->Next = tmp->Next;
        free(tmp);
        return true;
    }
}
