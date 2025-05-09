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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    vector<int> dx = {2, 1, -1, -2, -2, -1, 1, 2, 0};
    vector<int> dy = {1, 2, 2, 1, -1, -2, -2, -1, 0};
    vector<vector<int>> h(50, vector<int>(50, 0));
    int max_x = n + 1, max_y = m + 1;
    for (int i = 0; i < 9; i++) {
        int x = a + dx[i];
        int y = b + dy[i];
        if (x >= 0 && x <= n && y >= 0 && y <= m) {
            h[x + 1][y + 1] = 1;
        }
    }
    vector<vector<ll>> dp(50, vector<ll>(50, 0)); 
    dp[1][1] = 1; 
    for (int i = 1; i <= n + 1; i++) {
        for (int j = 1; j <= m + 1; j++) {
            if (i == 1 && j == 1) continue;
            if (h[i][j] == 0) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    }
    cout << dp[n+1][m+1] << endl;
    return 0;
}
