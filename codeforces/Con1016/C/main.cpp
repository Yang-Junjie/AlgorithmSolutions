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
bool isPrime(i64 x)
{
    if (x <= 1)
        return false;
    for (int i = 2; i <= x / i; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}
void solve()
{
    i64 x, k;
    cin >> x >> k;
    if (k == 1) {
            cout << (isPrime(x) ? "YES" : "NO") << endl;
        } else {
            if (x == 1) {
            cout << (k == 2 ? "YES" : "NO") << endl;
            } else {
                cout << "NO" << endl;
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
