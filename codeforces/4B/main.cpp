// #include <algorithm>
// #include <iostream>
// #include <string>
// #include <utility>
// #include <vector>
// #include <numeric>
// #include <limits>
// #include <cmath>
// #include <iomanip>
#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
template <typename Container>
void PrintCon(const Container &cont)
{
    std::cout << "{ ";
    if (!cont.empty())
    {
        auto it = cont.begin();
        std::cout << "\033[33m" << *it++ << "\033[0m";
        for (; it != cont.end(); ++it)
            std::cout << " | " << "\033[33m" << *it << "\033[0m";
    }
    std::cout << " }" << std::endl;
}

template <typename... Args>
void LOG(Args &&...values)
{
    ((std::cout << "\033[33m" << std::forward<Args>(values) << "\033[0m" << " "), ...);
    std::cout << std::endl;
}
#else
template <typename... Args>
void LOG(Args &...args);

template <typename Container>
void PrintCon(const Container &cont);
#endif

#define LEN(a) ((int)(a).size())
#define ALL(x) (x).begin(), (x).end()
using ll = long long int;
using ull = unsigned long long int;
using PII = pair<int, int>;
using VI = vector<int>;
struct Data
{
    int mn;
    int mx;
    int id;
    int ans ;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, sum;
    cin >> n >> sum;
    vector<Data> a(n);
    for (int i = 0; i < n; i++) {
        a[i].id = i;
        cin >> a[i].mn >> a[i].mx;
    }

    int total_min = 0, total_max = 0;
    for (auto &d : a) {
        total_min += d.mn;
        total_max += d.mx;
    }

    if (sum < total_min || sum > total_max) {
        cout << "NO" << endl;
        return 0;
    }

    //  如果有答案就先让sum-所有的min
    //如果sum-min>0即还有剩余的时间没用则用第0天开始到第n-1天看这些剩余的时间能不能分配进去，
    //分配的规则是在第i天尽可能多分，我们第i天已经花了min时间所以如果剩余时间小于max-min的话就完成了，
    //如果剩余时间大于max-min就分max-min给第i天剩余时间-(max-min)继续下一天
    for (auto &d : a) {
        d.ans = d.mn;
    }
    int rem = sum - total_min;

    //  
    for (int i = 0; i < n; i++) {
        a[i].ans += min(rem, a[i].mx - a[i].mn);
        rem -= min(rem, a[i].mx - a[i].mn);
        if (rem == 0) break;
    }

    sort(a.begin(), a.end(), [](const Data &a, const Data &b) { return a.id < b.id; });

    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
        if (i > 0) cout << ' ';
        cout << a[i].ans;
    }
    cout << endl;
    return 0;
}