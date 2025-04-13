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
    vector<i64> a(n, 0);
    for (auto& i : a) {
        cin >> i;
    }
    vector<i64> ev;
    int s = -1;
    for (auto i : a) {
        if (i % 2 == 0)
            ev.push_back(i);
        else if (i > s) {
            s = i;
        }
    }
    sort(ev.begin(), ev.end());
    if (s == -1 || ev.empty()) {
        cout << 0 << endl;
        return;
    }
    int ans = ev.size();
    for (auto& i : ev) {
        if (s > i) {
            s = s + i;
        } else {
            ans++;
            break;
        }
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
