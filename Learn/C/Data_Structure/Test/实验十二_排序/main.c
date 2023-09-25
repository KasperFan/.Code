#include <stdio.h>
#include <stdlib.h>
#include <mach/mach_time.h> //macOS内核时间头文件

typedef void (*func_ptr)();
typedef int ElementType;
typedef enum {false, true} bool;

void show(int i);

void cal(int i, int List[], int N);

void InsertionSort(ElementType A[], int N);
void BubbleSort(ElementType A[], int N);
void QuickSort(ElementType A[], int N);
void MergeSort(ElementType A[], int N);

ElementType Median3(ElementType A[], int Left, int Right);
void Qsort(ElementType A[], int Left, int Right);

void Merge(ElementType A[], ElementType TmpA[], int L, int R, int RightEnd);
void Msort(ElementType A[], ElementType TmpA[], int L, int RightEnd);

void Swap(ElementType *X, ElementType *Y);

func_ptr funcs[4] = {InsertionSort, BubbleSort, QuickSort, MergeSort};

// 定义打点变量，用于计算算法处理数据的时间
uint64_t start, stop;


int main(int argc, char const *argv[])
{
    mach_timebase_info_data_t info;
    mach_timebase_info(&info);

    for (int i = 0; i < 4; i++)
    {
        show(i);
        int set[] = {44, 12, 59, 36, 62, 43, 94, 7, 35, 52, 85};
        cal(i, set, 11);
        for (int j = 0; j < 11; j++)
        {
            printf("%d ", set[j]);
        }
        printf("\n");
        printf("time uses %lu ns\n", ((stop - start) * info.numer) / info.denom);
    }
    return 0;
}

void cal(int i, int List[], int N){
    start = mach_absolute_time();
    funcs[i](List, N);
    stop = mach_absolute_time();
}

void Swap(ElementType *X, ElementType *Y)
{ /* 交换X和Y两个元素 */
    ElementType tmp;
    tmp = *X;
    *X = *Y;
    *Y = tmp;
}

// 简单插入排序
void InsertionSort(ElementType A[], int N)
{ /* 插入排序 */
    int P, i;
    ElementType Tmp;

    for (P = 1; P < N; P++)
    {
        Tmp = A[P]; /* 取出未排序序列中的第一个元素*/
        for (i = P; i > 0 && A[i - 1] > Tmp; i--)
            A[i] = A[i - 1]; /*依次与已排序序列中元素比较并右移*/
        A[i] = Tmp;          /* 放进合适的位置 */
    }
}

// 冒泡排序
void BubbleSort(ElementType A[], int N)
{ /* 冒泡排序 */
    int P, i;
    bool flag;

    for (P = N - 1; P >= 0; P--)
    {
        flag = false; /* 标记该次循环中是否发生交换，若无，则说明整个序列有序 */
        for (i = 0; i < P; i++)
        { /* 一趟冒泡 */
            /* 每次循环找出一个最大元素，被交换到最右端 */
            if (A[i] > A[i + 1])
            {
                Swap(&A[i], &A[i + 1]);
                flag = true; /* 标识发生了交换 */
            }
        }
        if (flag == false)
            break; /*若全程无交换，则跳出循环*/
    }
}
// 快速排序（Quick Sort）
ElementType Median3(ElementType A[], int Left, int Right)
{
    int Center = (Left + Right) / 2;
    if (A[Left] > A[Center])
        Swap(&A[Left], &A[Center]);
    if (A[Left] > A[Right])
        Swap(&A[Left], &A[Right]);
    if (A[Center] > A[Right])
        Swap(&A[Center], &A[Right]);
    /* 此时A[Left] <= A[Center] <= A[Right] */
    Swap(&A[Center], &A[Right - 1]); /* 将基准Pivot藏到右边*/
    /* 只需要考虑A[Left+1] … A[Right-2] */
    return A[Right - 1]; /* 返回基准Pivot */
}

void Qsort(ElementType A[], int Left, int Right)
{ /* 核心递归函数 */
    int Pivot, Cutoff, Low, High;

    if (Cutoff <= Right - Left)
    {                                    /* 如果序列元素充分多，进入快排 */
        Pivot = Median3(A, Left, Right); /* 选基准 */
        Low = Left;
        High = Right - 1;
        while (1)
        { /*将序列中比基准小的移到基准左边，大的移到右边*/
            while (A[++Low] < Pivot)
                ;
            while (A[--High] > Pivot)
                ;
            if (Low < High)
                Swap(&A[Low], &A[High]);
            else
                break;
        }
        Swap(&A[Low], &A[Right - 1]); /* 将基准换到正确的位置 */
        Qsort(A, Left, Low - 1);      /* 递归解决左边 */
        Qsort(A, Low + 1, Right);     /* 递归解决右边 */
    }
    else
        InsertionSort(A + Left, Right - Left + 1); /* 元素太少，用简单排序 */
}

void QuickSort(ElementType A[], int N)
{ /* 统一接口 */
    Qsort(A, 0, N - 1);
}


// 归并排序
/* L = 左边起始位置, R = 右边起始位置, RightEnd = 右边终点位置*/
void Merge(ElementType A[], ElementType TmpA[], int L, int R, int RightEnd)
{ /* 将有序的A[L]~A[R-1]和A[R]~A[RightEnd]归并成一个有序序列 */
    int LeftEnd, NumElements, Tmp;
    int i;

    LeftEnd = R - 1; /* 左边终点位置 */
    Tmp = L;         /* 有序序列的起始位置 */
    NumElements = RightEnd - L + 1;

    while (L <= LeftEnd && R <= RightEnd)
    {
        if (A[L] <= A[R])
            TmpA[Tmp++] = A[L++]; /* 将左边元素复制到TmpA */
        else
            TmpA[Tmp++] = A[R++]; /* 将右边元素复制到TmpA */
    }

    while (L <= LeftEnd)
        TmpA[Tmp++] = A[L++]; /* 直接复制左边剩下的 */
    while (R <= RightEnd)
        TmpA[Tmp++] = A[R++]; /* 直接复制右边剩下的 */

    for (i = 0; i < NumElements; i++, RightEnd--)
        A[RightEnd] = TmpA[RightEnd]; /* 将有序的TmpA[]复制回A[] */
}

void Msort(ElementType A[], ElementType TmpA[], int L, int RightEnd)
{ /* 核心递归排序函数 */
    int Center;

    if (L < RightEnd)
    {
        Center = (L + RightEnd) / 2;
        Msort(A, TmpA, L, Center);               /* 递归解决左边 */
        Msort(A, TmpA, Center + 1, RightEnd);    /* 递归解决右边 */
        Merge(A, TmpA, L, Center + 1, RightEnd); /* 合并两段有序序列 */
    }
}

void MergeSort(ElementType A[], int N)
{ /* 归并排序 */
    ElementType *TmpA;
    TmpA = (ElementType *)malloc(N * sizeof(ElementType));

    if (TmpA != NULL)
    {
        Msort(A, TmpA, 0, N - 1);
        free(TmpA);
    }
    else
        printf("空间不足");
}

void show(int i)
{
    switch (i)
    {
    case 0:
        printf("Using InsertionSort\n");
        break;

    case 1:
        printf("Using BubbleSort\n");
        break;

    case 2:
        printf("Using QuickSort\n");
        break;

    case 3:
        printf("Using MergeSort\n");
        break;
    }
}
