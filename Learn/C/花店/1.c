#include<stdio.h>

int main(int argc, char const *argv[])
{
    int i = 3, a, b;
    printf("%d\n", i++);
    printf("%d\n", ++i);
    a = i++;
    b = ++i;
    // printf("%d\n", (i++) + (++i));
    // printf("%d\n", (++i) + (i++));
    return 0;
}
