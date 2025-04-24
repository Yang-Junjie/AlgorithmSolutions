#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <numeric>
#include <string>
#include <system_error>
#include <utility>
#include <vector>
using namespace std;
#define DEUBG
#ifdef DEBUG
template <typename Container>
void PrintCon(const Container& cont)
{
    std::cout << "{ ";
    if (!cont.empty()) {
        auto it = cont.begin();
        std::cout << "\033[33m" << *it++ << "\033[0m";
        for (; it != cont.end(); ++it)
            std::cout << " | " << "\033[33m" << *it << "\033[0m";
    }
    std::cout << " }" << std::endl;
}

template <typename... Args>
void LOG(Args&&... values)
{
    ((std::cout << "\033[33m" << std::forward<Args>(values) << "\033[0m" << " "), ...);
    std::cout << std::endl;
}
#else
template <typename... Args>
void LOG(Args&... args);

template <typename Container>
void PrintCon(const Container& cont);
#endif

#define LEN(a) ((int)(a).size())
#define ALL(x) (x).begin(), (x).end()
using ll = long long int;
using ull = unsigned long long int;
using PII = pair<int, int>;
using VI = vector<int>;

void solve()
{
    int n, m;
    cin >> n >> m;
    int col = 0;
    int row = 0;
    vector<string> g;
    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        g.push_back(tmp);
    }
    for (int i = 0; i < n; i++) {
        int c = g[i][0]-'0';
        for (int j = 1; j < m; j++) {
            c ^= g[i][j]-'0';
        }
        row += c;
    }
    for (int j = 0; j < m; j++) {
        int r = g[0][j]-'0';
        for (int i = 1; i < n; i++) {
            r ^= g[i][j]-'0';
        }
        col += r;
    }
    cout << max(col, row) << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
