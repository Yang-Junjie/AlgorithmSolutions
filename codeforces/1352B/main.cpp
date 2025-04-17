#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <numeric>
using namespace std;
#define DEBUG
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

void solve()
{
    int n, t;
    cin >> n >> t;
    VI a(t);
    if (t > n)
    {
        cout << "NO" << endl;
        return ;
    }
    int x = n / t;
    for (int i = 0; i < t - 1; i++)
    {
        a[i] = x;
    }
    a[t - 1] = n - x * (t - 1);
    bool is_same = true;
    for (auto i : a)
    {
        if (i % 2 != a[0] % 2)
        {
            is_same = false;
        }
    }
    if (is_same)
    {
        cout << "YES" << endl;
        for (auto i : a)
        {
            cout << i << ' ';
        }
        cout << endl;
        return;
    }
    else
    {
        
        for (int i = 0; i < t - 1; i++)
        {
            a[i] -= 1;
        }
        
        a[t - 1] += t - 1;
    }
    
    bool ans = true;
    for (auto i : a)
    {
        if (i % 2 != a[0] % 2||i==0)
        {
            ans = false;
        }
    }
    if (ans)
    {
        cout << "YES" << endl;
        for (auto i : a)
        {
            cout << i << ' ';
        }
        cout << endl;
        return;
    }
    else
    {
        cout << "NO" << endl;
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
