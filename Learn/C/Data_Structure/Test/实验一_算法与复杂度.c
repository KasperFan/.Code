#include <stdio.h>
#include <mach/mach_time.h> //macOS内核时间头文件

// 定义一个函数指针类型，用于指向算法函数
typedef int (*func_ptr)();

// 定义一个函数，用于按顺序选择算法来计算数组中的最大子列和
int MaxSubseqSum(int i, int List[], int N);

// 定义四种算法，分别实现最大子列和问题的求解
int MaxSubseqSum1(int List[], int N); // 算法1：穷举所有子列和
int MaxSubseqSum2(int List[], int N); // 算法2：部分存储中间值的穷举
int MaxSubseqSum3(int List[], int N); // 算法3：分而治之
int MaxSubseqSum4(int List[], int N); // 算法4：在线处理

// 定义一个辅助函数，用于比较三个整数中的最大值
int Max3(int A, int B, int C);

// 定义一个递归函数，用于实现分而治之算法
int DivideAndConquer(int List[], int left, int right);

// 定义一个函数指针数组，并初始化为四个算法函数的地址
func_ptr funcs[4] = {MaxSubseqSum1, MaxSubseqSum2, MaxSubseqSum3, MaxSubseqSum4};

// 定义打点变量，用于计算算法处理数据的时间
uint64_t start, stop;

// 定义三组测试数据
int test1[] = {-1, 3, -2, 4, -6, 1, 6, -1};
int test2[] = {-2, 11, -4, 13, -5, -2};
int test3[] = {4, -3, 5, -2, -1, 2, 6, -2};

// 计算每组测试数据的长度
int len1 = sizeof(test1) / sizeof(test1[0]);
int len2 = sizeof(test2) / sizeof(test2[0]);
int len3 = sizeof(test3) / sizeof(test3[0]);


// 主函数
int main()
{
    // 获取时钟频率
    mach_timebase_info_data_t info;
    mach_timebase_info(&info);

    for (int i = 0; i < 4; i++)
    {
        printf("Using algorithm %d to calculate output.\n", i + 1);
        // 调用函数，计算每组测试数据的最大子列和，并输出结果和程序运行时间(ns)
        printf("The max subsequence sum of test1 is %d, and time uses %lu ns\n", MaxSubseqSum(i, test1, len1), ((stop - start) * info.numer) / info.denom);
        printf("The max subsequence sum of test2 is %d, and time uses %lu ns\n", MaxSubseqSum(i, test2, len2), ((stop - start) * info.numer) / info.denom);
        printf("The max subsequence sum of test3 is %d, and time uses %lu ns\n", MaxSubseqSum(i, test3, len3), ((stop - start) * info.numer) / info.denom);
    }
    return 0;
}

// 计算数组中的最大子列和
int MaxSubseqSum(int i, int List[], int N)
{
    // 获取开始时间
    start = mach_absolute_time();
    // 按顺序参数运行函数
    int ans = funcs[i](List, N);
    // 获取截止时间
    stop = mach_absolute_time();

    return ans;
}

// 算法1：穷举所有子列和
int MaxSubseqSum1(int List[], int N)
{
    int ThisSum, MaxSum = 0;

    for (int i = 0; i < N; i++)
    { // i是子列左端位置
        for (int j = i; j < N; j++)
        {                // j是子列右端位置
            ThisSum = 0; // ThisSum是从List[i]到List[j]的子列和
            for (int k = i; k <= j; k++)
                ThisSum += List[k];
            if (ThisSum > MaxSum) // 如果刚得到的这个子列和更大
                MaxSum = ThisSum; // 则更新结果
        }                         // j循环结束
    }                             // i循环结束
    return MaxSum;
}

// 算法2：部分存储中间值的穷举
int MaxSubseqSum2(int List[], int N)
{
    int ThisSum, MaxSum = 0;

    for (int i = 0; i < N; i++)
    {                // i是子列左端位置
        ThisSum = 0; // ThisSum是从List[i]到List[j]的子列和
        for (int j = i; j < N; j++)
        { // j是子列右端位置
            // 对于相同的i，不同的j，只要在j-1次循环的基础上累加1项即可
            ThisSum += List[j];
            if (ThisSum > MaxSum) // 如果刚得到的这个子列和更大
                MaxSum = ThisSum; // 则更新结果
        }                         // j循环结束
    }                             // i循环结束
    return MaxSum;
}

// 算法3：分而治之
int MaxSubseqSum3(int List[], int N)
{
    // 保持与前两种算法相同的函数接口
    return DivideAndConquer(List, 0, N - 1);
}

// 比较三个整数中的最大值
int Max3(int A, int B, int C)
{
    return A > B ? A > C ? A : C : B > C ? B : C;
}

// 分治法求List[left]到List[right]的最大子列和
int DivideAndConquer(int List[], int left, int right)
{
    int MaxLeftSum, MaxRightSum;             // 存放左右子问题的解
    int MaxLeftBorderSum, MaxRightBorderSum; // 存放跨分界线的结果
    int LeftBorderSum, RightBorderSum;

    int center;

    if (left == right)
    { // 递归的终止条件，子列只有1个数字
        if (List[left] > 0) return List[left];
        else return 0;
    }

    // 下面是"分"的过程
    center = (left + right) / 2; // 找到中分点
    // 递归求得两边子列的最大和
    MaxLeftSum = DivideAndConquer(List, left, center);
    MaxRightSum = DivideAndConquer(List, center + 1, right);
    /* 下面求跨分界线的最大子列和*/
    MaxLeftBorderSum = 0;
    LeftBorderSum = 0;

    for (int i = center; i >= left; i--)
    { /*从中线向左扫描*/
        LeftBorderSum += List[i];
        if (LeftBorderSum > MaxLeftBorderSum) MaxLeftBorderSum = LeftBorderSum;
    } /* 左边扫描结束 */
    MaxRightBorderSum = 0;
    RightBorderSum = 0;
    for (int i = center + 1; i <= right; i++)
    { /*从中线向右扫描*/
        RightBorderSum += List[i];
        if (RightBorderSum > MaxRightBorderSum) MaxRightBorderSum = RightBorderSum;
    } /* 右边扫描结束 */
    /* 下面返回"治"的结果 */
    return Max3(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum);
}

// 算法4：在线处理

int MaxSubseqSum4(int List[], int N)

{
    int ThisSum, MaxSum;
    ThisSum = MaxSum = 0;

    for (int i = 0; i < N; i++)
    {
        ThisSum += List[i]; /* 向右累加 */
        if (ThisSum > MaxSum)
            MaxSum = ThisSum; /* 发现更大和则更新当前结果*/
        else if (ThisSum < 0) /* 如果当前子列和为负 */
            ThisSum = 0; /* 则不可能使后面的部分和增大，抛弃之 */
    }

    return MaxSum;
}
