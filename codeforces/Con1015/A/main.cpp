#include <algorithm>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
#define LOG(a) std::cout << "[" << #a << ":" << (a) << "]" << std::endl;
using i64 = long long int;
using u64 = unsigned long long int;
using u32 = unsigned int;

void solve()
{
    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << -1 << endl;
    } else {
        cout << n << ' ';
        for (int i = 1; i < n; i++) {
            cout << i << ' ';
        }
        cout << '\n';
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
