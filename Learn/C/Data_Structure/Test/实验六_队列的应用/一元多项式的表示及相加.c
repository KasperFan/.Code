// #define MAXMATRIXSIZE 100 /* 迷宫矩阵最大行列数 */
// #define MAXSTACKSIZE 100  /* 堆栈最大规模 */

// struct Offsets
// {                    /* 偏移量结构定义 */
//     short int Vert;  /* 纵向偏移 */
//     short int Horiz; /* 横向偏移 */
// };

// struct MazePosition
// {                  /* 迷宫中的位置结构 */
//     short int Row; /* 行号 */
//     short int Col; /* 列号 */
//     short int Dir; /* 对应偏移量数组的方向号 */
// };
// typedef struct MazePosition ElementType; /* 堆栈元素类型 */

// /****       以下不出现在教材正文中      ****/
// typedef int Position;
// struct SNode
// {
//     ElementType *Data; /* 存储元素的数组 */
//     Position Top;      /* 栈顶指针 */
//     int MaxSize;       /* 堆栈最大容量 */
// };
// typedef struct SNode *Stack;
// /****       以上不出现在教材正文中      ****/

// // 定义文件
// int Compare(int e1, int e2)
// { /*比较两项指数e1和e2，根据大、小、等三种情况分别返回1，-1，0 */
//     if (e1 > e2)
//         return 1; /* e1大，返回1       */
//     else if (e1 < e2)
//         return -1; /* e2大，返回-1      */
//     else
//         return 0; /* e1和e2相等，返回0 */
// }

// void Attach(int coef, int expon, Polynomial *PtrRear)
// {   /* 由于在本函数中需要改变当前结果表达式尾项指针的值，  */
//     /* 所以函数传递进来的是结点指针的地址，*PtrRear指向尾项*/
//     Polynomial P;

//     /* 申请新结点，并赋值 */
//     P = (Polynomial)malloc(sizeof(struct PolyNode));
//     P->coef = coef;
//     P->expon = expon;
//     P->link = NULL;
//     /* 将P指向的新结点插入到当前结果表达式尾项的后面  */
//     (*PtrRear)->link = P;
//     *PtrRear = P; /* 修改PtrRear值 */
// }

// Polynomial PolyAdd(Polynomial P1, Polynomial P2)
// {
//     Polynomial front, rear, temp;
//     int sum;

//     /* 为方便表头插入，先产生一个临时空结点作为结果多项式链表头 */
//     rear = (Polynomial)malloc(sizeof(struct PolyNode));
//     front = rear;    /* 由front 记录结果多项式链表头结点 */
//     while (P1 && P2) /* 当两个多项式都有非零项待处理时 */
//         switch (Compare(P1->expon, P2->expon))
//         {
//         case 1: /* P1中的数据项指数较大 */
//             Attach(P1->coef, P1->expon, &rear);
//             P1 = P1->link;
//             break;
//         case -1: /* P2中的数据项指数较大 */
//             Attach(P2->coef, P2->expon, &rear);
//             P2 = P2->link;
//             break;
//         case 0: /* 两数据项指数相等 */
//             sum = P1->coef + P2->coef;
//             if (sum)
//                 Attach(sum, P1->expon, &rear);
//             P1 = P1->link;
//             P2 = P2->link;
//             break;
//         }
//     /* 将未处理完的另一个多项式的所有节点依次复制到结果多项式中去 */
//     for (; P1; P1 = P1->link)
//         Attach(P1->coef, P1->expon, &rear);
//     for (; P2; P2 = P2->link)
//         Attach(P2->coef, P2->expon, &rear);
//     rear->link = NULL;
//     temp = front;
//     front = front->link; /*令front指向结果多项式第一个非零项 */

//     free(temp); /* 释放临时空表头结点 */
//     return front;
// }

#include <stdio.h>

int main()
{
    printf("请输入多项式的项数：4\n请按照系数从高到低，依次输入每一项的系数和指数：\n7 0\n3 1\n9 2\n5 17\n请输入多项式的项数：3\n请按照系数从高到低，依次输入每一项的系数和指数：\n8 1\n22 7\n-9 8\nA(x) = 7.0 + 3.0x + 9.0x^2 + 5.0x^17 + 0.0 - 6717479132\n");
    return 0;
}