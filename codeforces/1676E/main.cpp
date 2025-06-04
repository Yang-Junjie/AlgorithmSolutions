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

ll BS(const vector<ll> &a, int x)
{
    ll l = 0, r = a.size(), ans = -1;
    while (l + 1 != r)
    {
        ll mid = (l + r) / 2;
        if (a[mid] >= x)
        {
            ans = mid;
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    return ans;
}
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<ll> a(n, 0);
    vector<ll> sum(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(ALL(a), [](ll a, ll b)
         { return a > b; });
    for (int i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1] + a[i - 1];
    }
    while (q--)
    {

        ll x;
        cin >> x;
        cout << BS(sum, x) << endl;
    }
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
