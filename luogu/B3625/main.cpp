#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
using PII = pair<int, int>;
const int N = 110;
char g[N][N];
int n, m;
bool bfs(int a, int b)
{
    queue<PII> q;
    q.push({ a, b });

    while (!q.empty()) {
        PII start = q.front();
        q.pop();
        g[start.first][start.second] = '#';
        int dx[] = { 1, -1, 0, 0 }, dy[] = { 0, 0, 1, -1 };
        for (int i = 0; i < 4; i++) {
            int x = start.first + dx[i], y = start.second + dy[i];
            if (g[x][y] != '#') {
                g[x][y] = '#';
                q.push({ x, y });
            }
        }
    }
    if (g[n][m] == '#')
        return true;
    return false;
}
int main()
{
    memset(g, (int)'#', sizeof(g));
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
        }
    }

    if (bfs(1, 1)) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}
