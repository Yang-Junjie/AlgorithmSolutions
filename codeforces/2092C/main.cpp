#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <numeric>
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
using pii = pair<int, int>;
using vi = vector<int>;

void solve()
{
    int n;
    cin >> n;
    ll sum = 0;
    int oddlen = 0, evenlen = 0;
    ll max = -1;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        sum += tmp;
        if (tmp % 2 == 0)
        {
            evenlen++;
        }
        else
        {
            oddlen++;
        }
        if (tmp > max)
        {
            max = tmp;
        }
    }
    if (oddlen == 0 || evenlen == 0)
    {
        cout << max << endl;
    }
    else
    {
        cout << sum - oddlen + 1 << endl;
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
