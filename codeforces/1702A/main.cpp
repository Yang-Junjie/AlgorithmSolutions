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
    string a;
    cin >> a;
    a[0] = (char)((int)(a[0] - '0') - 1 + '0');
    bool flag = false;
    for (auto& ch : a) {
        if (ch != '0') {
            flag = true;
        }
        if (flag) {
            cout << ch;
        }
    }
    if(!flag){
        cout<<0;
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
