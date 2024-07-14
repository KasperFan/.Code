#include <stdio.h>

typedef int Position;
typedef struct QNode *PtrToQNode;

struct QNode
{
    ElementType *Data;
    Position Front, Rear;
    int MaxSize;
};
typedef PtrToQNode Queue;

Queue CreateQueue(int MaxSize)
{
    Queue Q = (Queue)malloc(sizeof(struct Qnode));
    Q->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
    Q->Front = Q->Rear = 0;
    Q->MaxSize = MaxSize;
    return Q;
}

bool isFull(Queue Q)
{
    return (Q->Rear + 1) % Q->MaxSize == Q->Front;
}

bool AddQ(Queue Q, ElementType X){
    if(isFull(Q)){
        printf("is full!");
        return false;
    }
    else{
        Q->Rear = (Q->Rear + 1) % Q->MaxSize;
        Q->Data[Q->Rear] = X;
        return true;
    }
}

bool isEmpty(Queue Q)
{
    return (Q->Front == Q->Rear);
}

//好烦人啊好他妈多啊老子不写了