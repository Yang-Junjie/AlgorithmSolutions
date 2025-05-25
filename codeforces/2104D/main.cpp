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
    ll n, ans = numeric_limits<ll>::max();
    cin >> n;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    ll l = 1, r = n;

    while (l + 1 <= n && a[l + 1] == a[l])
        l++;
    while (r - 1 >= 1 && a[r - 1] == a[r])
        r--;

    if (a[1] == a[n])
    {
        ans = min(ans, max(r - l - 1, (long long)0));
    }
    ans = min(min(n - l, r - 1), ans);

    cout << max((long long)0, ans) << endl;
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
