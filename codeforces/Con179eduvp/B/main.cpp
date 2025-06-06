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
    vector<int> f(n + 1, 0);

    f[1] = 1;
    f[2] = 2;

    for (int i = 3; i <= n; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
    }
    PrintCon(f);
    while (m--)
    {
        ll w, l, h;
        cin >> w >> l >> h;

        if (min(w, min(l, h)) >= f[n] && max(w, max(l, h)) >= f[n] + f[n - 1])
        {
            cout << 1;
        }
        else
        {
            cout << 0;
        }
    }
    cout << endl;
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
