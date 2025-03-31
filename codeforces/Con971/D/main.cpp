#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
#define LOG(a) std::cout << "[" << #a << ":" << (a) << "]" << std::endl;
using i64 = long long int;
using u64 = unsigned long long int;
using u32 = unsigned int;
i64 t, x, y, n, ans = 0;
i64 v[200010][2];
void solve()
{
    ans = 0;
    cin >> n;
    memset(v, 0, sizeof(v));
    for (int i = 1; i <= n; i++) {
        cin >> x >> y;
        v[x][y] = 1;
    }
    for (int i = 0; i <= n; i++) {
        if (v[i][1] == 1 && v[i][0] == 1)
            ans += (n - 2);
        if (v[i][1] == 1 && v[i - 1][0] == 1 && v[i + 1][0] == 1)
            ans++;
        if (v[i][0] == 1 && v[i - 1][1] == 1 && v[i + 1][1] == 1)
            ans++;
    }
    cout << ans << endl;
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
