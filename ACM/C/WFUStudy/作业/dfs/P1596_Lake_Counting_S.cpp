#include <bits/stdc++.h>

using namespace std;

int N, M;
bool is_visited[101][101];
char maps[101][101];

int main(int argc, char const *argv[])
{
    cin >> N >> M;
    getchar();
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            scanf("%c", &maps[i][j]);
        }
        getchar();
    }
    for (int i = 1; i <= N; i++)
    {
        char *p = maps[i];
        p++;
        printf("%s\n", p);
    }
    return 0;
}

// void dfs(int i,int j) {
//     if (maps[i][j]!='W')
//     {
//         /* code */
//     }
    
// }
