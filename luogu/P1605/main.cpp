#include <bits/stdc++.h>
using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define MAXV(a, l, r) *std::max_element((a).begin() + (l), (a).begin() + (r))
#define MINV(a, l, r) *std::min_element((a).begin() + (l), (a).begin() + (r))

using ll = long long int;
using ull = unsigned long long int;
using PII = pair<int, int>;

#define DEBUG
#ifdef DEBUG
template <typename Container>
void PrintCon(const Container &cont)
{
    std::cout << "{ ";
    if (!cont.empty())
    {
        auto it = cont.begin();
        std::cout << "\033[33m" << *it++ << "\033[0m";
        for (; it != cont.end(); ++it)
            std::cout << " | " << "\033[33m" << *it << "\033[0m";
    }
    std::cout << " }" << std::endl;
}

template <typename... Args>
void LOG(Args &&...values)
{
    ((std::cout << "\033[33m" << std::forward<Args>(values) << "\033[0m" << " "), ...);
    std::cout << std::endl;
}

#else

template <typename... Args>
void LOG(Args &...args);
template <typename Container>
void PrintCon(const Container &cont);

#endif
int cnt = 0;
PII start, destination;
int dx[] = {1, 0, 0, -1}, dy[] = {0, -1, 1, 0};
void dfs(PII u, vector<vector<int>> &g)
{
    if (u.first == destination.first && u.second == destination.second)
    {
        cnt++;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int nx = u.first + dx[i], ny = u.second + dy[i];
        if (g[nx][ny] != 1)
        {
            g[nx][ny] = 1;
            dfs({nx, ny}, g);
            g[nx][ny] = 0;
        }
    }
    // for (auto i : g)
    // {
    //     PrintCon(i);
    // }
    // cout << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, t;
    cin >> n >> m >> t;

    cin >> start.first >> start.second >> destination.first >> destination.second;
    vector<vector<int>> g(n + 2, vector<int>(m + 2, 0));
    for (int i = 0; i < n + 2; i++)
    {
        for (int j = 0; j < m + 2; j++)
        {
            if (i == 0 || i == n + 1 || j == 0 || j == n + 1)
                g[i][j] = 1;
        }
    }

    g[start.first][start.second] = 1;
    while (t--)
    {
        int x, y;
        cin >> x >> y;
        g[x][y] = 1;
    }
    dfs(start, g);
    cout << cnt << endl;

    return 0;
}
