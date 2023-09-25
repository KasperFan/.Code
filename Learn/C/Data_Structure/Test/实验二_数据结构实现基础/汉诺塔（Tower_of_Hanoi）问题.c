#include <stdio.h>

int cnt = 0;

void Move(int n, int start, int goal, int temp)
{
    if (n >= 1)
    {
        Move(n - 1, start, temp, goal);
        printf("Move disk %d from %d to %d.\n", n, start, goal);
        cnt++;
        Move(n - 1, temp, goal, start);
    }
    /* else当n == 0时不需要做任何事 */
}

int main()
{
    int n = 3;
    Move(n, 1, 3, 2);
    printf("%d\n", cnt);
    return 0;
}
