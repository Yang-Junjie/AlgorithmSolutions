#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <utility>
#include <vector>
using namespace std;
#define DEBUG
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
int is_good(vector<ll> a)
{
    int cnt=0;
    ll sum = 0;
    ll maxx = 0;
    for (int i = 0; i < a.size(); i++) {
        if (maxx < a[i]) {
            sum +=maxx; 
            maxx = a[i];
        } else {
            sum += a[i];
        }
        if (sum == maxx)
            cnt++;
    }
    return cnt;
}
void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto& i : a) {
        cin >> i;
    }
    cout << is_good(a) << endl;
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
