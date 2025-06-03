#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define ALL(x) (x).begin(), (x).end()

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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m;
    cin >> m;
    int n;
    cin >> n;
    vector<PII> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(ALL(a), [](PII a, PII b) {
        return a.first < b.first;
    });
    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (cnt >= m) {
            break;
        } else {
            if (cnt + a[i].second > m) {
                ans += a[i].first * (m - cnt);
                cnt += (m - cnt);
            } else {
                ans += a[i].first * a[i].second;
                cnt += a[i].second;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
