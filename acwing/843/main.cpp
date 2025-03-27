#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
const int N = 15;
int n;
char g[N][N];
bool col[N], gd[2 * N], rgd[2 * N];
void dfs(int u)
{
    if (u == n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << g[i][j];
            cout << '\n';
        }
        cout << '\n';
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!col[i] && !gd[i + u] && !rgd[n - i + u]) {
            g[u][i] = 'Q';
            col[i] = gd[i + u] = rgd[n - i + u] = true;
            dfs(u + 1);
            col[i] = gd[i + u] = rgd[n - i + u] = false;
            g[u][i]='.';
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            g[i][j] = '.';
    dfs(0);
    return 0;
}
