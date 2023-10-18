#include <stdio.h>
#define M(x, y, z) x*y+z
int main()
{
    int a = 1, b = 2, c = 3;
    printf("%d\n", M(a+b, b+c, c+a));
}