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
    int n;
    cin >> n;
    vector<PII> a(n + 1, {0, 0});
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin() + 1, a.end(), [](PII a, PII b)
         {
        if (a.first == b.first)
            return a.second < b.second;
        return a.first < b.first; });

    bool ok = true;
    for (int i = 1; i < n; ++i)
    {
        if (a[i].second > a[i + 1].second)
        {
            ok = false;
            break;
        }
    }
    if (!ok)
    {
        cout << "NO" << endl;
        return;
    }

    string ans = "";
    int x = 0, y = 0;
    for (int i = 1; i <= n; ++i)
    {
        int dx = a[i].first - x;
        int dy = a[i].second - y;
        if (dx < 0 || dy < 0)
        {
            cout << "NO" << endl;
            return;
        }
        ans += string(dx, 'R');
        ans += string(dy, 'U');
        x = a[i].first;
        y = a[i].second;
    }

    cout << "YES" << endl;
    cout << ans << endl;
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
