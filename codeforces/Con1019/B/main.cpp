#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <numeric>
#include <limits>
#include <cmath>
#include <iomanip>
#include <map>
using namespace std;

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

#define LEN(a) ((int)(a).size())
#define ALL(x) (x).begin(), (x).end()
using ll = long long int;
using ull = unsigned long long int;
using PII = pair<int, int>;
using VI = vector<int>;

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    int ini = (s[0] != '0');
    vector<int> a;
    for (int i = 1; i < n; ++i) {
        if (s[i-1] != s[i])
            a.push_back(i);
    }
    int cnt = a.size();
    int mx = 0;
    
    for (int r = 0; r < n; ++r) {
        int new_ini = (s[r] != '0');
        int d = (r < n-1) ? (s[r] != s[r+1]) : 0;
        int b = (r < n-1) ? (s[0] != s[r+1]) : 0;
        mx = max(mx, (ini - new_ini) + (d - b));
    }
    
    
    for (int i = 0; i < (int)a.size() - 1; ++i) {
        int p = a[i], q = a[i+1];
        if (s[p-1] == s[q] && s[p] == s[q-1]) {
            mx = max(mx, 2);
            break;
        }
    }
    
    cout << (ini + cnt - mx) + n << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
