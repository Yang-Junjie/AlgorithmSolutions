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
    if (a % 2 == 0) {
        for (int i = a; i > a / 2; i--) {
            cout << i << ' ' << a - i + 1 << ' ';
        }
        cout << endl;
    } else {
        for (int i = a; i > a / 2+1; i--) {
            cout << i << ' ' << a - i + 1 << ' ';
        }
        cout<<(a+2-1)/2<<endl;
    cout<<endl;
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
