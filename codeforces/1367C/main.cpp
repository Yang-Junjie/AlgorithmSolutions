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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int cnt = count(ALL(s), '1');
    int ans = 0;
    vector<int> a(n);
    if (cnt == 0)
    {
        ans = (n + k) / (k + 1);
    }
    else
    {
        int l = 0, r = numeric_limits<int>::max();
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                for (int j = i+1; j <= i + k&&j<n; j++)
                {
                    if (s[j] != '1')
                        a[j]++;
                }
            }
        }
        for (int i = n-1; i >=0; i--)
        {
            if (s[i] == '1')
            {
                for (int j = i-1; j >= i - k&&j>=0; j--)
                {
                    if (s[j] != '1')
                        a[j]++;
                }
            }
        }
        for(int i = 0;i<n;i++){
            if(a[i]==0&&s[i]!='1'){
                ans++;
                for (int j = i+1; j <= i + k&&j<n; j++)
                {
                    if (s[j] != '1')
                        a[j]++;
                }
            }
        }
    }
    cout<<ans<<endl;
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
