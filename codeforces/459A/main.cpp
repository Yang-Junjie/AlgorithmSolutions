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
long long f(long long s)
{
    if (s < 0)
        s = -s;
    return s;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long a, b, x, y;
    cin >> a >> b >> x >> y;
    if (a == x)
        cout << a + f(b - y) << " " << b << " " << x + f(b - y) << " " << y;
    else if (b == y)
        cout << a << " " << b + f(a - x) << " " << x << " " << y + f(a - x);
    else if (f(a - x) == f(b - y))
        cout << a << " " << y << " " << x << " " << b;
    else
        cout << -1;

    return 0;
}
