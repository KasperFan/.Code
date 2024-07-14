#include <stdio.h>

int n, m, ans;
int nrr[(int)1e6 + 10], mrr[(int)1e5 + 10];
int check(int x)
{
    int l = 1, r = n;
    while(l<r)
    {
        int mid = l + (r - l) / 2; //(r-l)/2表示该区间一半的长度，加上l就是中间的位置
        if (nrr[mid] >= x)
            r = mid;
        else
            l = mid + 1;
    }
    if (nrr[l] == x)
        return l;
    else
        return -1;
}
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &nrr[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &mrr[i]);
        ans=check(mrr[i]);
        printf("%d ", ans);
    }

    return 0;
}
