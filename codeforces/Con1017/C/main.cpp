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
    int n;
    cin >> n;
    vector<bool> vis(n * n, false);
    int the_max = -1;
    int cnt = 0;
    vector<int> p(n * n, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int tmp;
            cin >> tmp;
            if (!vis[tmp]) {
                p[i + j] = tmp;

                vis[p[i + j]] = true;
                cnt++;
            }
        }
    }
    for (int i = 1; i <= cnt+1; i++) {
        if (!vis[i])
            p[1] = i;
    }
    for (int i = 1; i <= cnt+1; i++) {
        cout << p[i] << ' ';
    }
    cout << endl;
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
