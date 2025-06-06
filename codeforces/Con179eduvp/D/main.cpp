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
    int n, m;
    cin >> n >> m;
    vector<PII> a(m);
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        a[i].first = x / 100;
        a[i].second = x % 100;
    }
    sort(ALL(a));
    for (int i = 0; i < m; i++)
    {
        a[i].first = a[i].first * 100 + a[i].second;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            if (i & 1)
            {
                cout << a[i / 2].first << ' ' << a[m - 1 - i / 2].first <<' ';
            }
            else
            {
                cout << a[m - 1 - i / 2].first << ' ' << a[i / 2].first << ' ';
            }
        }
        cout << endl;
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
