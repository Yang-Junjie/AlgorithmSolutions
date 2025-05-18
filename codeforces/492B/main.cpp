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
    ll n, l;
    cin >> n >> l;
    vector<double> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(ALL(a));
    double mx = numeric_limits<double>::min();
    if (a[0] != 0)
    {
        mx = max(mx, a[0]);
    }
    if (a[n - 1] != l)
    {
        mx = max(mx, l - a[n - 1]);
    }
    for (int i = 0; i < n - 1; i++)
    {
        mx = max(mx, (a[i + 1] - a[i]) / 2);
    }
    cout << fixed << setprecision(10) << mx << endl;
    return 0;
}
