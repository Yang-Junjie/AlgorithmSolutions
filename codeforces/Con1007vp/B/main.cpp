#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <numeric>
#include <cmath>
using namespace std;

#ifdef DEBUG
#define LOG(a) cerr << "[" << #a << ":" << (a) << "]" << endl
#else
#define LOG(a)
#endif

#define Len(a) ((int)(a).size())
#define All(x) (x).begin(), (x).end()
using ll = long long int;
using ull = unsigned long long int;
using PII = pair<int, int>;
using VI = vector<int>;
bool isSquare(ll num)
{
    ll a = sqrt(num);
    if (a * a == num)
        return true;
    return false;
}
void solve()
{
    ll n;
    cin >> n;
    if (isSquare(1LL*n * (n + 1) / 2))
    {
        cout << -1 << endl;
        return;
    }
    vector<ll> a(n);
    iota(All(a), 1);

    for (int i = 1; i < n; i++)
    {
        if (isSquare(1LL*i * (i + 1) / 2))
        {
            swap(a[i], a[i - 1]);
        }
    }
    for (auto x : a)
    {
        std::cout << x << " \n"[x == a.back()];
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
