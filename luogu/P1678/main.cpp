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

int BS(int x, const vector<int> &a)
{
    int l = -1, r = a.size();
    while (l + 1 != r)
    {
        int mid = l + r >> 1;
        if (x <= a[mid])
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    return r;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, n;
    cin >> m >> n;
    vector<int> a(m);
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    sort(ALL(a));
    ll ans = 0;
    while (n--)
    {
        int x;
        cin >> x;

        int index = BS(x, a);
        if (index == 0)
        {
            ans += abs(x - a[0]);
        }
        else if (index == m)
        {
            ans += abs(x - a[m - 1]);
        }
        else
        {
            ans += min(abs(x - a[index]), abs(x - a[index - 1]));
        }
    }
    cout << ans << endl;
    return 0;
}