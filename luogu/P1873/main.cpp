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
ll n, m;
bool check(ll mid, vector<ll> a)
{
    ll cnt = 0;
    for (auto i : a)
    {
        if (i > mid)
        {
            cnt += i - mid;
        }
    }

    return cnt >= m;
}

int BS(int l, int r, vector<ll> a)
{
    int mid;
    while (l + 1 != r)
    {
        mid = l + r >> 1;
        if (check(mid, a))
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    return l;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    vector<ll> a(n);
    for (auto &i : a)
    {
        cin >> i;
    }
    cout << BS(0, MAXV(a, 0, n)+1, a) << endl;

    return 0;
}
