#include <iostream>
using namespace std;

const int N = 110;
int g[N][N];
int n, m, k;

int main() {
    cin >> n >> m >> k;
    
    // 处理火把的光照范围
    while (m--) {
        int x, y;
        cin >> x >> y;

        int dx[] = {0, 0, 0, 0, 0, -2, -1, 1, 2, -1, -1, 1, 1};
        int dy[] = {-2, -1, 0, 1, 2, 0, 0, 0, 0, -1, 1, -1, 1};
        for (int i = 0; i < 13; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= n) {
                g[nx][ny]++;
            }
        }
    }
    

    while (k--) {
        int x, y;
        cin >> x >> y;
        for (int i = x - 2; i <= x + 2; ++i) {
            for (int j = y - 2; j <= y + 2; ++j) {
                if (i >= 1 && i <= n && j >= 1 && j <= n) {
                    g[i][j]++;
                }
            }
        }
    }
    

    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (g[i][j] == 0) {
                cnt++;
            }
        }
    }
    
    cout << cnt << endl;
    return 0;
}

