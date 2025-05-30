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
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(ALL(b));
    int l = 0, r = n - 1;
    while (a[l] == b[l] && l <= n - 1)
    {
        l++;
    }
    while (a[r] == b[r] && r >= 0)
    {
        r--;
    }
    if (l >= r)
    {
        cout << "yes" << endl;
        cout << "1 1" << endl;
        return 0;
    }
    for (int i = l, j = r; i <= r; i++, j--)
    {
        b[i] = a[j];
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (b[i] > b[i + 1])
        {
            cout << "no";
            return 0;
        }
    }
    cout << "yes" << endl;
    cout << l + 1 << " " << r + 1<<endl;

    return 0;
}
