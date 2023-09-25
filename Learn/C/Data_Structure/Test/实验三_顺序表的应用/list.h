// 头文件
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ERROR -1
typedef int Position;
typedef struct LNode *PtrToLNode;
struct LNode
{
    ElementType Data[MAXSIZE];
    Position Last;
};
typedef PtrToLNode List;

int Length(List L);

// 实现文件
/* 初始化 */
List MakeEmpty()
{
    List L;

    L = (List)malloc(sizeof(struct LNode));
    L->Last = -1;

    return L;
}


ElementType FindKth(List L, int K)
{
    if (K >= 1 && K <= Length(L)) return L->Data[K-1];
    else return ERROR;
}

/* 查找元素 */
Position Find(List L, ElementType X)
{
    Position i = 0;

    while (i <= L->Last && L->Data[i] != X)
        i++;
    if (i > L->Last)
        return ERROR; /* 如果没找到，返回错误信息 */
    else
        return i; /* 找到后返回的是存储位置 */
}

/* 插入元素 */
bool Insert(List L, ElementType X, int i)
{ /* 在L的指定位序i前插入一个新元素X;位序i元素的数组位置下标是i-1 */
    Position j;

    if (L->Last == MAXSIZE - 1)
    {
        /* 表空间已满，不能插入 */
        printf("表满");
        return false;
    }
    if (i < 1 || i > L->Last + 2)
    {
        /* 检查插入位序的合法性：是否在1~n+1。n为当前元素个数，即Last+1 */
        printf("位序不合法");
        return false;
    }
    for (j = L->Last; j >= i - 1; j--) /*Last指向序列最后元素 */
        L->Data[j + 1] = L->Data[j];   /* 将位序i及以后的元素顺序向后移动 */
    L->Data[i - 1] = X;                /* 新元素插入第i位序，其数组下标为i-1 */
    L->Last++;                         /* Last仍指向最后元素 */
    return true;
}

/* 删除元素 */
bool Delete(List L, int i)
{ /* 从L中删除指定位序i的元素,该元素数组下标为i-1 */
    Position j;

    if (i < 1 || i > L->Last + 1)
    { /* 检查空表及删除位序的合法性 */
        printf("位序%d不存在元素", i);
        return false;
    }
    for (j = i; j <= L->Last; j++)
        L->Data[j - 1] = L->Data[j]; /*将位序i+1及以后的元素顺序向前移动*/
    L->Last--;                       /* Last仍指向最后元素 */
    return true;
}

int Length(List L)
{
    return L->Last + 1;
}