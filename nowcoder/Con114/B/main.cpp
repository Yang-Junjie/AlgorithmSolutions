#include <algorithm>
#include <iostream>
#include <numeric>
#include <set>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
#define LOG(a) std::cout << "[" << #a << ":" << (a) << "]" << std::endl;
using i64 = long long int;
using u64 = unsigned long long int;
using u32 = unsigned int;
using PII = pair<int, int>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    unordered_set<int> unique_a;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        unique_a.insert(a);
    }

    long long ans = 0;
    for (int x : unique_a) {
        if (x <= n) {
            ans += x;
        }
    }

    cout << ans << endl;
    return 0;
}
