#include <stdio.h>
#include <time.h>
// #include <math.h>

clock_t start, stop;
/* 测试数据 */
int List[] = {-1, 3, -2, 4, - 6, 1, 6, -1}, N = 8;
// int List[] = {-2, 11, -4, 13, -5, -2}, N = 6;
// int List[] = {4, -3, 5, -2, -1, 2, 6, -2}, N = 8;

/*［算法1]从最直接的方法开始，就是穷举所有子列和，从中找出最大值。*/
int MaxSubseqSum1(int List[], int N);
/*［算法2]部分存储中间值的穷举。*/
int MaxSubseqSum2(int List[], int N);
/*［算法3]分而治之。*/
int Max3(int A, int B, int C);
int DivideAndConquer(int List[], int left, int right);
int MaxSubseqSum3(int List[], int N);
/*［算法4]在线处理。*/
int MaxSubseqSum4(int List[], int N);

int (*funcs[4])(int[], int) = {MaxSubseqSum1, MaxSubseqSum2, MaxSubseqSum3, MaxSubseqSum4};

int main()
{
    long ans;
    start = clock();
    for (int i = 0; i < 1e6; i++)
    // 方法测试:
    // ans = MaxSubseqSum1(List, N);
    // ans = MaxSubseqSum2(List, N);
    // ans = MaxSubseqSum3(List, N);
    ans = MaxSubseqSum4(List, N);
    stop = clock();
    printf("运算结果是%ld,消耗时间为%lfs\n", ans, (double)(stop - start)/CLOCKS_PER_SEC);
    return 0;
}

/*［算法1]从最直接的方法开始，就是穷举所有子列和，从中找出最大值。*/
int MaxSubseqSum1(int List[], int N)
{
    int ThisSum, MaxSum = 0;

    for (int i = 0; i < N; i++) /* i 是子列左端位置 */
    {
        for (int j = 0; j < N; j++) /* j 是子列右端位置 */
        {
            ThisSum = 0; /* ThisSum是从List[i]到List[j]的子列和 */
            for (int k = i; k <= j; k++)
                ThisSum += List[k];
            if (ThisSum > MaxSum) /* 如果刚得到的这个子列和更大 */
                MaxSum = ThisSum; /* 则更新结果 */
        }                         /* j循环结束 */
    }                             /* i循环结束 */
    return MaxSum;
}

/*［算法2]部分存储中间值的穷举。*/
int MaxSubseqSum2(int List[], int N)
{
    int ThisSum, MaxSum = 0;

    for (int i = 0; i < N; i++) /* i 是子列左端位置 */
    {
        ThisSum = 0;                /* ThisSum是从List[i]到List[j]的子列和 */
        for (int j = i; j < N; j++) /* j 是子列右端位置 */
        {
            /* 对于不同的i,不同的j,只要在j-1次循环的基础上累加1项即可 */
            ThisSum += List[j];
            if (ThisSum > MaxSum) /* 如果刚得到的这个子列和更大 */
                MaxSum = ThisSum; /* 则更新结果 */
        }                         /* j循环结束 */
    }                             /* i循环结束 */
    return MaxSum;
}

/*［算法3]分而治之。*/
/* 返回3个整数中的最大值 */
int Max3(int A, int B, int C) 
{
    return A > B ? A > C ? A : C : B > C ? B : C;
}

/* 分治法求List[left]到List[right]的最大子列和 */
int DivideAndConquer(int List[], int left, int right) 
{                                            
    int MaxLeftSum, MaxRightSum;             /* 存放左右子问题的解 */
    int MaxLeftBorderSum, MaxRightBorderSum; /* 存放跨分界线的结果 */

    int LeftBorderSum, RightBorderSum;
    int center;

    if (left == right) /* 递归的终止条件，子列只有1个数字 */
    {
        if (List[left] > 0)
            return List[left];
        else
            return 0;
    }

    /* 下面是"分"的过程 */
    center = (left + right) / 2; /* 找到中分点 */
    /* 递归求得两边子列的最大和 */
    MaxLeftSum = DivideAndConquer(List, left, center);
    MaxRightSum = DivideAndConquer(List, center + 1, right);

    /* 下面求跨分界线的最大子列和 */
    MaxLeftBorderSum = 0; LeftBorderSum = 0;
    for (int i = center; i >= left; i--) /* 从中线向左扫描 */
    {
        LeftBorderSum += List[i];
        if (LeftBorderSum > MaxLeftBorderSum)
            MaxLeftBorderSum = LeftBorderSum;
    } /* 左边扫描结束 */

    MaxRightBorderSum = 0; RightBorderSum = 0;
    for (int i = center + 1; i <= right; i++) /* 从中线向右扫描 */
    {
        RightBorderSum += List[i];
        if (RightBorderSum > MaxRightBorderSum)
            MaxRightBorderSum = RightBorderSum;
    } /* 右边扫描结束 */

    /* 下面返回“治”的结果 */
    return Max3(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum);
}

/* 保持与前2种算法相同的函数接口 */
int MaxSubseqSum3(int List[], int N)
{
    return DivideAndConquer(List, 0, N - 1);
}

/*［算法4]在线处理。*/
int MaxSubseqSum4(int List[], int N)
{
    int ThisSum, MaxSum;

    ThisSum = MaxSum = 0;
    for (int i = 0; i < N; i++)
    {
        ThisSum += List[i]; /* 向右累加 */
        if (ThisSum > MaxSum)
            MaxSum = ThisSum; /* 发现更大的和则更新当前结果 */
        else if (ThisSum < 0) /* 如果当前子列和为负 */
            ThisSum = 0;      /* 则不可能使后面的部分和增大,抛弃之 */
    }
    return MaxSum;
}
