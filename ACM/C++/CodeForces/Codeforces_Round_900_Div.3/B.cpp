#include <bits/stdc++.h>

using namespace std;

int t, a[(int)(2E5 + 10)], n, i;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    a[1] = 6;
    a[2] = 8;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (i = 3; i <= n; i++)
        {
            for (int j = a[i - 1] + 1;; j++)
            {
                if (3 * j % (a[i - 2] + a[i - 1]))
                {
                    a[i] = j;
                    break;
                }
            }
        }
        for (i = 1; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << a[i] << endl;
    }
    return 0;
}
