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
int BS(int x, const vector<ll> &a)
{
    int l = -1, r = a.size();
    while (l + 1 != r)
    {
        int mid = l + r >> 1;
        if (a[mid] > x)
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    if (a[l] > x)
    {
        return -1;
    }
    else
    {
        return l;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(ALL(a));
    int q;
    cin >> q;
    while (q--)
    {
        int x;
        cin >> x;
        int index = BS(x, a);
        if (BS(x, a) != -1)
            cout << index + 1 << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}
