#include <bits/stdc++.h>

using namespace std;



clock_t start, endTime;

int n=5;

int main()
{
    ios::sync_with_stdio(false);
    start = clock();
    for (int i = 0; i < 100; i++)
    {
        cout << n << endl;
    }
    
    // printf("%d\n", n);
    endTime = clock();
    cout << (endTime - start) << endl;
    return 0;
}
