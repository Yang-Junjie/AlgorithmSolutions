#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <numeric>
using namespace std;

#ifdef DEBUG
#define LOG1(a) cerr << "[" << #a << ":" << (a) << "]" << endl
#define LOG2(a, b) cerr << "[" << #a << ":" << (a) << "," << #b << ":" << (b) << "]" << endl
template <typename Container>
void PrintCon(const Container &cont)
{
    std::cout << "{ ";
    if (!cont.empty())
    {
        auto it = cont.begin();
        std::cout << "\033[33m" << *it++ << "\033[0m";
        for (; it != cont.end(); ++it)
            std::cout << " | " << *it;
    }
    std::cout << " }" << std::endl;
}

#else
#define LOG(a)
#endif

#define LEN(a) ((int)(a).size())
#define ALL(x) (x).begin(), (x).end()
using ll = long long int;
using ull = unsigned long long int;
using PII = pair<int, int>;
using VI = vector<int>;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> l(n);
    vector<int> r(n);
    for (int i = 0; i < n; ++i) {
        cin >> l[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> r[i];
    }

    vector<int> minv(n);
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += max(l[i], r[i]);
        minv[i] = min(l[i], r[i]);
    }
    sort(ALL(minv), greater<int>());
    
    for (int i = 0; i < k - 1; ++i) {
        ans+=minv[i];
    }

    cout << ans + 1 << '\n';
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