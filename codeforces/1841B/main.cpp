#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <numeric>
using namespace std;

#ifdef DEBUG
#define LOG(a) cerr << "[" << #a << ":" << (a) << "]" << endl
#else
#define LOG(a)
#endif

#define Len(a) ((int)(a).size())
#define All(x) (x).begin(), (x).end()
using ll = long long int;
using ull = unsigned long long int;
using PII = pair<int, int>;
using VI = vector<int>;

void solve()
{
    int q;
    cin >> q;
    vector<int> a;
    string ans;
    bool flag = true;
    for (int i = 0; i < q; ++i) {
        int x;
        cin >> x;
        if (a.empty()) {
            a.push_back(x);
            ans += '1';
        } else {
            if (flag) {
                if (x >= a.back()) {
                    a.push_back(x);
                    ans += '1';
                } else {
                    if (x <= a[0]) {
                        a.push_back(x);
                        ans += '1';
                        flag = false;
                    } else {
                        ans += '0';
                    }
                }
            } else {
                if (x >= a.back() && x <= a[0]) {
                    a.push_back(x);
                    ans += '1';
                } else {
                    ans += '0';
                }
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
