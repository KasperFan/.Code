#include <stdio.h>

#define MAXSIZE 100
typedef int ElementType;
#include "list.h"

int data[] = {23, 29, 20, 32, 23, 21, 33, 25};

int main(int argc, char const *argv[])
{
    List chain;
    chain = MakeEmpty();
    for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++)
    {
        if (!Insert(chain, data[i], i + 1)) printf("插入失败\n");
    }
    int index;
    printf("线性表的长度为: %d\n", Length(chain));
    scanf("%d", &index);
    printf("Find %d : %d\n", index, Find(chain, index) == ERROR ? ERROR : Find(chain, index) + 1);
    scanf("%d", &index);
    printf("Find %d : %d\n", index, Find(chain, index) == ERROR ? ERROR : Find(chain, index) + 1);
    scanf("%d", &index);
    printf("FindKth %d : %d\n", index, FindKth(chain, index) == ERROR ? ERROR : FindKth(chain, index));
    scanf("%d", &index);
    if (!Delete(chain, index)) printf("删除失败\n");
    printf("线性表的长度为: %d\n", Length(chain));
    scanf("%d", &index);
    if (!Delete(chain, index)) printf("删除失败\n");
    printf("线性表的长度为: %d\n", Length(chain));
    free(chain);
    return 0;
}
