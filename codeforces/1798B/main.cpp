#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <numeric>
#include <set>
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

void solve()
{
    int m;
    cin >> m;
    int n;
    vector<vector<int>> a(m);
    for (int i = 0; i < m; i++)
    {
        cin >> n;
        a[i].resize(n);
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    vector<int> ans(m);
    vector<int> have;
    for (int i = m - 1; i >= 0; i--)
    {
        int win = -1;
        for (auto y : a[i])
        {
            if ((int)count(All(have), y) == 0)
            {
                win = y;
                have.push_back(y);
            }
        }
        if (win == -1)
        {
            cout << -1 << endl;
            return;
        }
        ans[i] = win;
    }
    for (auto i : ans)
    {
            cout << i << ' ';
    }
    cout << endl;
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
