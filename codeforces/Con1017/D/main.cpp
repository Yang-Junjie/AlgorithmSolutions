#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <utility>
#include <vector>
using namespace std;
#define LOG(a) std::cout << "[" << #a << ":" << (a) << "]" << std::endl;
using i64 = long long int;
using u64 = unsigned long long int;
using u32 = unsigned int;
using PII = pair<int, int>;

void solve()
{
    string p, s;

    cin >> p >> s;
    int n = p.size(), m = s.size();
    p = '0' + p, s = '0' + s;
    int l = 1, r = 1, flg = 0;
    int lcnt = 0, rcnt = 0;
    while (l <= n && r <= m) {
        while (l <= n && p[l] == 'L')
            l++, lcnt++;
        while (r <= m && s[r] == 'L')
            r++, rcnt++;
        if (!(lcnt <= rcnt && rcnt <= lcnt * 2))
            break;
        lcnt = 0, rcnt = 0;
        while (l <= n && p[l] == 'R')
            l++, lcnt++;
        while (r <= m && s[r] == 'R')
            r++, rcnt++;
        if (!(lcnt <= rcnt && rcnt <= lcnt * 2))
            break;
        lcnt = 0, rcnt = 0;
        if (l > n && r > m)
            flg = 1;
    }
    if (flg)
        cout << "YES\n";
    else
        cout << "NO\n";
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
