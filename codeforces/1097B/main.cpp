#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <tuple>
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
    vector<int> alpha(30, 0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        for (int j = 0; j < 26; j++) {
            if (alpha[j] == a) {
                cout << (char)('a' + j);
                alpha[j]++;
                break;
            }
        }
    }
    cout<<endl;
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
