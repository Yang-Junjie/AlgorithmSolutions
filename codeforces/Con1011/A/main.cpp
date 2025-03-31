#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
#define LOG(a) std::cout << "[" << #a << ":" << (a) << "]" << std::endl;
using i64 = long long int;
using u64 = unsigned long long int;
using u32 = unsigned int;

void solve()
{
    int n, k;
    string a;
    cin >> n >> k;
    cin >> a;
    string b = a;
    reverse(b.begin(), b.end());
    if (a < b || (k >= 1 && *max_element(a.begin(), a.end()) != *min_element(a.begin(), a.end()))) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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
