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

void solve()
{
    ll n, x, k;
    string s;

    cin >> n >> x >> k >> s;
    ll nw1 = x, nw2 = 0, stp1 = n + 1, stp2 = k + 1;
    s = ' ' + s;
    for (ll i = 1; i <= n; i++)
    {
        if (s[i] == 'L')
            nw1--, nw2--;
        if (s[i] == 'R')
            nw1++, nw2++;
        if (nw1 == 0 && stp1 == n + 1)
            stp1 = i;
        if (nw2 == 0 && stp2 == k + 1)
            stp2 = i;
    }
    cout << ((stp1 != n + 1 && k >= stp1) ? 1 + (k - stp1) / stp2 : 0) << endl;
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
