#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

using i32 = int;
using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;

const int N = 1e5 + 5;

i64 a[N], suf[N], msuf[N], pre[N], mpre[N];

void solve()
{
    i64 n, k, x, sum = 0;
    cin >> n >> k >> x;

    for (int i = 0; i < n; ++i)
        cin >> a[i], sum += a[i];

    for (int i = n - 1; i >= 0; --i)
        suf[i] = a[i] + (i < n - 1 ? suf[i + 1] : 0);

    if (sum > 0) {
        if (sum * k < x) {
            cout << "0\n";
            return;
        }
        i64 ans = 0;
        for (int i = 0; i < n; ++i) {
            if (suf[i] >= x)
                ans += k;
            else {
                i64 c = (x - suf[i] + sum - 1) / sum;
                if (c <= k - 1)
                    ans += k - c;
            }
        }
        cout << ans << '\n';

    } else {
        if (sum * k >= x) {
            cout << "0\n";
            return;
        }

        for (int i = n - 1; i >= 0; --i)
            msuf[i] = max(a[i], a[i] + (i < n - 1 ? msuf[i + 1] : 0));

        mpre[0] = a[0];
        for (int i = 1; i < n; ++i)
            mpre[i] = max(mpre[i - 1], a[i] + mpre[i - 1]);

        i64 ans = 0;
        for (int i = 0; i < n; ++i) {
            if (msuf[i] >= x)
                ans += k;
            else if (k > 1) {
                i64 cross = (i ? mpre[i - 1] : 0) + suf[i];
                if (cross >= x)
                    ans += k - 1;
            }
        }
        cout << ans << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
