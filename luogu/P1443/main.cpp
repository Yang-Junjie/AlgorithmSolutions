#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int N = 420;
int g[N][N];
int n, m, a, b;
int d[N][N];
using PII = pair<int, int>;
queue<PII> q;
bool vis[N][N];
void bfs(int a, int b)
{
    q.push({ a, b });
    vis[a][b] = true;
    int dx[] = { -2, -2, -1, -1, 1, 1, 2, 2 },
        dy[] = { -1, 1, -2, 2, -2, 2, -1, 1 };
    while (!q.empty()) {

        PII start = q.front();
        q.pop();
        for (int i = 0; i < 8; i++) {
            int x = start.first + dx[i], y = start.second + dy[i];
            if (g[x][y] != -1) {
                g[x][y] = -1;
                vis[x][y] = true;
                d[x][y] = d[start.first][start.second] + 1;
                q.push({ x, y });
            }
        }
    }
}
int main()
{
    cin >> n >> m >> a >> b;
    memset(g, -1, sizeof(g));
    memset(d, 0, sizeof(d));
    memset(vis, 0, sizeof(vis));
    for (int i = 2; i <= n + 1; i++)
        for (int j = 2; j <= m + 1; j++)
            g[i][j] = 0;
    bfs(a + 1, b + 1);
    d[a+1][b+1] = 0;

    for (int i = 2; i <= n + 1; i++) {
        for (int j = 2; j <= m + 1; j++) {
            if (!vis[i][j])
                printf("%-5d",-1);
            else
                printf("%-5d",d[i][j]);
        }
        cout << endl;
    }
    return 0;
}
