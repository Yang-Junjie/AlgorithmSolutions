#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define maxv(a, l, r) *std::max_element((a).begin() + (l), (a).begin() + (r))
#define minv(a, l, r) *std::min_element((a).begin() + (l), (a).begin() + (r))

using ll = long long int;
using ull = unsigned long long int;
using pii = pair<int, int>;

#define debug
#ifdef debug
template <typename container>
void printcon(const container& cont)
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

template <typename... args>
void log(args&&... values)
{
    ((std::cout << "\033[33m" << std::forward<args>(values) << "\033[0m" << " "), ...);
    std::cout << std::endl;
}

#else

template <typename... args>
void log(args&... args);
template <typename container>
void printcon(const container& cont);

#endif

struct Data {
    double t;
    int id;
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<Data> a(n);
    for (int i = 0; i < n; i++) {
        a[i].id = i + 1;
        cin >> a[i].t;
    }
    sort(all(a), [](Data a, Data b) {
        return a.t < b.t;
    });
    for (auto i : a) {
        cout << i.id << " ";
    }
    cout << endl;
    double time = 0.0;
    vector<double> sum(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + a[i - 1].t;
        time += sum[i-1];
    }
    cout << setprecision(2) << fixed << time / n << endl;
    return 0;
}
