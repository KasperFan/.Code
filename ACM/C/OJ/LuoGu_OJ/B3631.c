#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct Node
{
    ElementType data;
    struct Node *next;
} Node;

typedef Node LinkedList;

LinkedList *init();
void insert(LinkedList *L, ElementType value, ElementType front_value);
ElementType ask_after(LinkedList *L, ElementType x);
void del_after(LinkedList *L, ElementType x);
void free_all(LinkedList *L);

int main()
{
    LinkedList *list = init();
    int n, op, x, y;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            scanf("%d %d", &x, &y);
            insert(list, y, x);
            break;

        case 2:
            scanf("%d", &x);
            printf("%d\n", ask_after(list, x));
            break;

        case 3:
            scanf("%d", &x);
            del_after(list, x);
            break;
        }
    }
    system("pause");
    free_all(list);
    return 0;
}

LinkedList* init(){
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = 1;
    node->next = NULL;
    return node;
}

void insert(LinkedList* L, ElementType value, ElementType front_value) {
    Node *p = L;
    while (p->data!=front_value) p = p->next;
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = value;
    node->next = p->next;
    p->next = node;
}

ElementType ask_after(LinkedList* L, ElementType x) {
    Node *p = L;
    while (p->data!=x) p = p->next;
    return (p->next == NULL ? 0 : p->next->data);
}

void del_after(LinkedList* L, ElementType x) {
    Node *p = L;
    while (p->data!=x) p = p->next;
    Node *q = p->next;
    p->next = q->next;
    free(q); q = NULL;
}

void free_all(LinkedList *L) {
    if (L == NULL) return;
    free_all(L->next);
    free(L);
    L = NULL;
}