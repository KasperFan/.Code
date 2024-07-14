// 散列表（线性探测避免冲突）
#include <stdio.h>
#include <string.h>

static int arr[] = {7, 8, 30, 11, 18, 9, 14};
static float rate = 0.7;



int main(int argc, char const *argv[])
{
    int length = (int)((sizeof(arr) / sizeof(arr[0])) / rate);
    int hashtable[length];
    memset(hashtable, -1, length*sizeof(hashtable[0]));
    
    return 0;
}
