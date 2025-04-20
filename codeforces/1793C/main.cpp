#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <numeric>
#include <limits>
#include <cmath>
using namespace std;

#ifdef DEBUG
#define LOG1(a) cerr << "[" << #a << ":" << (a) << "]" << endl
#define LOG2(a, b) cerr << "[" << #a << ":" << (a) << "," << #b << ":" << (b) << "]" << endl
template <typename Container>
void PrintCon(const Container &cont)
{
    std::cout << "{ ";
    if (!cont.empty())
    {
        auto it = cont.begin();
        std::cout << "\033[33m" << *it++ << "\033[0m";
        for (; it != cont.end(); ++it)
            std::cout << " | " << "\033[33m" << *it++ << "\033[0m";
    }
    std::cout << " }" << std::endl;
}

#else
#define LOG(a)
#endif

#define LEN(a) ((int)(a).size())
#define ALL(x) (x).begin(), (x).end()
using ll = long long int;
using ull = unsigned long long int;
using PII = pair<int, int>;
using VI = vector<int>;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int l = 0, r = n - 1, mx = n, mn = 1;
    while (1)
    {
        if (a[l] == mx)
        {
            l++;
            mx--;
        }
        else if (a[l] == mn)
        {
            l++;
            mn++;
        }
        else if (a[r] == mx)
        {
            r--;
            mx--;
        }
        else if (a[r] == mn)
        {
            r--;
            mn++;
        }
        else
        {
            break;
        }
    }
    if (l <= r)
    {
        cout << l + 1 << ' ' << r + 1 << endl;
    }
    else
    {
        cout << -1 << endl;
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