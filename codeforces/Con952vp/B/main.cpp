#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <utility>
#include <vector>
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

int sum(int n)
{
    if (n == 1)
        return 1;
    return n + sum(n - 1);
}
void solve()
{
    int n;
    cin >> n;
    int maxx = 0;
    int maxi = 0;
    for (int i = 2; i <= n; i++) {
        if (sum(n / i) * i > maxx) {
            maxx = sum(n / i) * i;
            maxi = i;
        }
    }
    cout << maxi << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
