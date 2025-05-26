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
    ll n;
    cin >> n;
    ll ans = 0;
    ll cnt = 0;
    ll cnt0 = 0;
    while (n--)
    {
        ll x;
        cin >> x;
        if (x == 1)
        {
            if (cnt0 != 0)
            {
                cnt -= pow(2, cnt0 - 1);
                cnt0 = 0;
            }
            if (cnt < 0)
            {
                cnt = 0;
            }

            cnt++;
            if (cnt < 3)
                ans += 1;
            else if (cnt < 7)
                ans += 2;
            else if (cnt < 30)
                ans += 3;
            else if (cnt < 120)
                ans += 4;
            else if (cnt < 365)
                ans += 5;
            else
                ans += 6;
        }
        else
        {
            cnt0++;
        }
    }
    cout << ans << endl;
    return 0;
}
