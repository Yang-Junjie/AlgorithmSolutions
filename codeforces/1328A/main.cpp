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
    int a, b;
    cin >> a >> b;
    if (a % b == 0) {
        cout << 0 << endl;
    } else {
        if (a > b) {
            cout << ((a + b - 1) / b) * b - a << endl;
        } else {
            cout << b - a << endl;
        }
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
