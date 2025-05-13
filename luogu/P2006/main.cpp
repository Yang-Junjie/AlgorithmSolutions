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
struct Data {
    int id;
    int a;
    int b;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k, m, n;
    cin >> k >> m >> n;
    vector<Data> q;
    for (int i = 0; i < m; i++) {
        Data tmp;
        tmp.id = i + 1;
        cin >> tmp.a >> tmp.b;
        q.push_back(tmp);
    }
    vector<Data> ans;
    for (auto &i : q) {
        if (i.a == 0) {
            if (i.b == 0) {
                if (n <= 0) {
                    ans.push_back(i);
                }
            } else {
                ans.push_back(i);
            }
        } else {
            if (i.a > k) continue;
            int l = k / i.a;
            if (l * i.b >= n) {
                ans.push_back(i);
            }
        }
    }
    if (!ans.empty()) {
        sort(ALL(ans), [](Data a, Data b) { return a.id < b.id; });
        for (auto &i : ans) {
            cout << i.id << ' ';
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}