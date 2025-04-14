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

    if (m < n || m > 2 * n) {
        cout << "NO\n";
        return;
    }

    bool ok = true;
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (p[i] != s[j]) {
            cout << "NO\n";
            return;
        }
        int haishen_p = n - i;
        int haishen_s = m - j;
        if (haishen_s < haishen_p || haishen_s > 2 * haishen_p) {
            cout << "NO\n";
            return;
        }
        if (j + 1 < m && s[j + 1] == p[i] && (haishen_s - 2 >= haishen_p - 1)) {
            j += 2;
        } else {
            j += 1;
        }
        i += 1;
    }

    cout << ((i == n && j == m) ? "YES\n" : "NO\n");
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

