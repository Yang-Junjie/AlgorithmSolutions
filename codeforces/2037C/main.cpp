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
    if (n <= 4) {
        cout << -1 << endl;
    } else {
        for (int i = 2; i <= n; i += 2) {
            if (i != 4) {
                cout << i << ' ';
            }
        }
        cout << "4 5 ";
        for (int i = 1; i <= n; i += 2) {
            if (i != 5) {
                cout << i << ' ';
            }
        }
        cout << endl;
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
