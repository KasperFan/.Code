// 代码1.9 循环求和
int IterativeSum(int List[], int N)
/* 循环求N个整数的和 */
{
    int i;       /* 执行1步 */
    int Sum = 0; /* 执行1步 */

    for (i = 0; i < N; i++) /* 共执行 2N+2 步 */
        Sum += List[i];     /* 共执行 N 步 */

    return Sum; /* 执行1步 */
}

// 代码1.10 递归求和
int RecursiveSum(int List[],int N)
/* 递归求N个整数的和 */
{
    if (N) /* 执行1步 */
        return (RecursiveSum(List, N - 1) + List[N - 1]); /* 执行 x+2 步 */
    return 0; /* 执行1步 */
}