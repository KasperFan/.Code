#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ERROR -1
typedef stack_t Stack;
typedef struct GNode *PtrToGNode;
typedef PtrToGNode GList;
struct GNode
{
    int Tag; /* 标志域：0表示该结点是单元素；1表示该结点是广义表 */
    union
    {
        /* 子表指针域Sublist与单元素数据域Data复用，即共用存储空间 */
        ElementType Data;
        GList Sublist;
    } URegion;
    PtrPtrToGNode Next; /* 指向后继结点 */
};

/*C语言代码：堆栈的定义与操作-链式存储*/
// 生成
Stack CreateStack()
{ /* 构建一个堆栈的头结点，返回该结点指针 */
    Stack S;

    S = malloc(sizeof(struct SNode));
    S->Next = NULL;
    return S;
}
bool IsEmpty(Stack S)
{ /* 判断堆栈S是否为空，若是返回true；否则返回false */
    return (S->Next == NULL);
}
// 压栈
bool Push(Stack S, ElementType X)
{ /* 将元素X压入堆栈S */
    PtrToSNode TmpCell;

    TmpCell = (PtrToSNode)malloc(sizeof(struct SNode));
    TmpCell->Data = X;
    TmpCell->Next = S->Next;
    S->Next = TmpCell;
    return true;
}
// 出栈
ElementType Pop(Stack S)
{ /* 删除并返回堆栈S的栈顶元素 */
    PtrToSNode FirstCell;
    ElementType TopElem;

    if (IsEmpty(S))
    {
        printf("堆栈空");
        return ERROR;
    }
    else
    {
        FirstCell = S->Next;
        TopElem = FirstCell->Data;
        S->Next = FirstCell->Next;
        free(FirstCell);
        return TopElem;
    }
}
