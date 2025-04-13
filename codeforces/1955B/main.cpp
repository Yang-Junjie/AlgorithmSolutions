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
    int n, b, c;
    cin >> n >> b >> c;
    vector<int> g(n * n);
    for (auto& i : g) {
        cin >> i;
    }
    sort(g.begin(), g.end());
    vector<int> m(n * n,0);
    m[0] = g[0];
    for (int i = 0; i < n * n; i++) {
        
        if (i + 1 < n) {
            m[i + 1] = m[i] + c;
            m[i + n] = m[i] + b;
        }
        else if(i+1<=n*n-n){
            m[i + n] = m[i] + b;
            
        }
    }
    sort(m.begin(), m.end());
    cout << (m == g ? "YES" : "NO") << endl;
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

