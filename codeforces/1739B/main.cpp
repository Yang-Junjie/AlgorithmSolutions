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
    vector<int> b(n);
    vector<int> a(n);
    for (auto& i : b) {
        cin >> i;
    }
    a[0] = b[0];
    for (int i = 1; i < n; i++) {

        int x = a[i - 1] - b[i], y = b[i] + a[i - 1];
        if ((x > 0 && y > 0 && x != y)) {
            cout << -1 << endl;
            return;
        } else {
            if (x >= 0) {
                a[i] = x;
            } else {
                a[i] = y;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
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
