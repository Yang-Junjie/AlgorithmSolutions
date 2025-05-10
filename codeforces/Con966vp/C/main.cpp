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

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &i : a)
    {
        cin >> i;
    }
    int m;
    cin >> m;
    while (m--)
    {
        string s;
        cin >> s;
        if (s.size() != a.size())
        {
            cout << "NO" << endl;
            continue;
        }
        unordered_map<char, ll> m;
        unordered_map<ll, char> m1;
        bool flag = true; // 表示是否满足答案
        for (int i = 0; i < n; i++)
        {
            if (m.find(s[i]) == m.end())
            {
                m.insert({s[i], a[i]});
            }
            else
            {
                if (m[s[i]] != a[i])
                {
                    flag = false;
                    break;
                }
            }
            if (m1.find(a[i]) == m1.end())
            {
                m1.insert({a[i], s[i]});
            }
            else
            {
                if (m1[a[i]] != s[i])
                {
                    flag = false;
                    break;
                }
            }
        }
        cout << (flag ? "YES" : "NO") << endl;
    }
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
