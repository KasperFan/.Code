// 代码1.8 选择排序算法的伪码描述
void SelectionSort(int List[],int N)
/* 从n个整数List[i],...,List[N-1]进行非递减排序 */
{
    for (int i = 0; i < N; i++)
    {
        /* 从List[i]到List[N-1]中找最小元，并将其位置赋给MinPosition */
        int MinPosition = ScanForMin(List, i, N - 1);

        /* 将未排序部分的最小元换到有序部分的最后位置 */
        Swep(List[i], List[MinPosition]);
    }
}