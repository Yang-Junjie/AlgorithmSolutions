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
    i64 n, b = 0;
    cin >> n;
    string s;
    cin >> s;
    if (n <= 2) {
        cout << 0 << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == '-') {
            b++;
        }
    }
    cout << (b / 2) * ((b + 1) / 2) * (n - b) << endl;
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
