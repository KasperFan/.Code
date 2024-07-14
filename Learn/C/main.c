#include <stdio.h>

void swap(int *a, int *b);
void quick_sort(int q[], int l, int r);

int arr[] = {1, 3, 6, 5, 2, 4, 8, 9, 7, 0};

int main(){
    quick_sort(arr, 0, 9);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quick_sort(int q[], int l, int r){
    if (l >= r) return;
    int x = q[(l+r)/2], i = l-1, j = r+1;
    while (i < j)
    {
        do i++; while (q[i] < x);
        do j--; while (q[j] > x);
        if (i < j) swap(&q[i], &q[j]);
    }
    for (int k = l; k <= r; k++)
    {
        printf("%d ", q[k]);
    }
    printf("\n");

    quick_sort(q, l, j);
    quick_sort(q, j+1, r);
}

