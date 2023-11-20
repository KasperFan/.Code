#include <stdio.h>

int main()
{
    int x, i;
    const int number = 10;
    int counts[number];
    scanf("%d", &x);
    while (x != -1) // 用来结束循环
    {
        if (x >= 0 && x < 10)
        {
            counts[x]++;
            scanf("%d", &x);
        }
    }
    for (i = 0; i < number; i++)
    {
        printf("%d:%d\n", i, counts[i]);
    }
    return 0;
}