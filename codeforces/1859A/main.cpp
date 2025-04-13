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
    vector<int> a(n);
    for (auto& i : a) {
        cin >> i;
    }
    sort(a.begin(), a.end());
    if (a.front() == a.back()) {
        cout << -1 << endl;
        return;
    }
    int index = 0;
    for (int i = 0; i < n; i++) {

        if (a[i] != a[0]) {
            index = i;
            break;
        }
    }
    cout<<index<<' '<<n-index<<endl;
    for (int i = 0; i < index; i++) {
        cout << a[i] << ' ';
    }
    cout << endl;
    for (int i = index; i < n; i++) {
        cout << a[i] << ' ';
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
