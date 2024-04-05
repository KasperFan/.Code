#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>

using namespace std;
const int N = 1e6 + 10;
int n, m;
int graph[1010][1010];
int h[N], e[2 * N], ne[2 * N], idx;
int f[N];
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
int book[1010][1010], vidx;
int din[N], dout[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void topo()
{
    queue<int> q;
    for (int i = 1; i <= vidx; i++)
    {
        if(!din[i])
        {
            q.push(i);
            f[i] = 1;
        }
    }
    while(q.size())
    {
        int t = q.front();
        q.pop();
        for (int i = h[t]; ~i; i = ne[i])
        {
            int j = e[i];
            din[j]--;
            f[j] = max(f[j], f[t] + 1);
            if(!din[j])
                q.push(j);
        }
    }
}

int main()
{
    memset(h, -1, sizeof h);
    cin >> n >> m;
    for (int i = 1; i <= n;i++)
    {
        for (int j = 1; j <= m;j++)
        {
            cin >> graph[i][j];
        }
    }
    for (int i = 1; i <= n;i++)
    {
        for (int j = 1; j <= m;j++)
        {
            for (int k = 0; k < 4;k++)
            {
                int nx = i + dx[k], ny = j + dy[k];
                if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && graph[i][j] > graph[nx][ny])
                {
                    if(!book[i][j])
                    {
                        book[i][j] = ++vidx;
                    }
                    if(!book[nx][ny])
                    {
                        book[nx][ny] = ++vidx;
                    }
                    add(book[i][j], book[nx][ny]);
                    din[book[nx][ny]]++;
                    dout[book[i][j]]++;
                }
            }
        }
    }
    topo();
    int ans = 0;
    for (int i = 1; i <= vidx; i++)
    {
        ans = max(ans, f[i]);
    }
    cout << ans << endl;
    return 0;
}