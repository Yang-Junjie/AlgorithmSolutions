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
    i64 n;
    cin >> n;
    vector<i64> a(n);
    for (auto& i : a) {
        cin >> i;
    }
    if (n == 2) {
        cout << a[1] - a[0] << endl;
    } else {
        i64 cnt = a[n - 2];
        for (int i = n - 3; i >= 0; i--) {
            cnt -= a[i];
        }
        cout << a[n - 1] - cnt << endl;
    }
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
