#include <bits/stdc++.h>
#include <vector>
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

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n + 2, vector<int>(n + 2, 0));
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); j++) {
            a[i][j + 1] = (s[j] - '0');
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == 1 && a[i][j - 1] == 0 && a[i][j + 1] == 0) {
                cout << "TRIANGLE" << endl;
                return;
            }
        }
    }
    cout << "SQUARE" << endl;
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
