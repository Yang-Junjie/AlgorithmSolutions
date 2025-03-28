#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
using namespace std;
const int N = 110;
int n, m;
int g[N][N];
int d[N][N];
using PII = pair<int, int>;
queue<PII> q;
int bfs(int a, int b)
{
    q.push({ a, b });
    d[0][0] = 0;
    while (!q.empty()) {
        PII start = q.front();
        q.pop();
        int dx[4] = { 0, 1, -1, 0 },dy[4] = { 1, 0, 0, -1 };
        for (int i = 0; i < 4; i++) {
            int x = start.first + dx[i], y = start.second + dy[i];
            if (g[x][y] == 0) {
                g[x][y] = 1;
                d[x][y] = d[start.first][start.second] + 1;
                q.push({ x, y });
            }
        }
    }
    return d[n][m];
}
int main()
{
    memset(g, 1, sizeof(g));
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> g[i][j];

    cout << bfs(1, 1);
    return 0;
}
