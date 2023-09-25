#include <stdio.h>

int main()
{
    int *p, arr[10];
    for (int i = 9; i >= 0; i--)
        arr[i] = 10 - i;
    p = arr;
    printf("%d\n", (*(++p) + *(p++)) + (--*p));
    return 0;
}
