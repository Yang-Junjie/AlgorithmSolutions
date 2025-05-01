#include <bits/stdc++.h>
using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define MAXV(a, l, r) *std::max_element((a).begin() + (l), (a).begin() + (r))
#define MINV(a, l, r) *std::min_element((a).begin() + (l), (a).begin() + (r))

using ll = long long int;
using ull = unsigned long long int;
using PII = pair<int, int>;

#define DEBUG

#ifdef DEBUG
template <typename Container>
void PrintCon(const Container& cont)
{
    std::cout << "{ ";
    if (!cont.empty()) {
        auto it = cont.begin();
        std::cout << "\033[33m" << *it++ << "\033[0m";
        for (; it != cont.end(); ++it)
            std::cout << " | " << "\033[33m" << *it << "\033[0m";
    }
    std::cout << " }" << std::endl;
}

template <typename... Args>
void LOG(Args&&... values)
{
    ((std::cout << "\033[33m" << std::forward<Args>(values) << "\033[0m" << " "), ...);
    std::cout << std::endl;
}
#else
template <typename... Args>
void LOG(Args&... args);

template <typename Container>
void PrintCon(const Container& cont);
#endif

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto& i : a) {
        cin >> i;
    }
    int ans = 0;
    for (int i = 0, j = i; i < n; i = j + 1) {
        while (j + 1 < n && a[j + 1] == a[i]) {
            j++;
        }
        bool flag_l = false, flag_r = false;
        if (j == n - 1 || a[j + 1] < a[i]) {
            flag_r = true;
        }
        if (i == 0 || a[i - 1] < a[i]) {
            flag_l = true;
        }
        if (flag_r && flag_l) {
            ans++;
        }
    }
    //LOG(ans);
    cout << ans << endl;
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
