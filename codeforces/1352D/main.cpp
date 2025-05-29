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
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int l = 0, r = n - 1;
    int cnt = 0;
    int sum_l = 0, sum_r = 0;
    int last_sum = 0;
    bool flag = true; // true 表示 Alice 的回合

    while (l <= r)
    {
        int current_sum = 0;

        if (flag)
        {

            while (l <= r && current_sum <= last_sum)
            {
                current_sum += a[l];
                l++;
            }
            sum_l += current_sum;
            last_sum = current_sum;
            flag = false;
            cnt++;
        }
        else
        {

            while (l <= r && current_sum <= last_sum)
            {
                current_sum += a[r];
                r--;
            }
            sum_r += current_sum;
            last_sum = current_sum; 
            flag = true;
            cnt++;
        }
    }

    cout << cnt << ' ' << sum_l << ' ' << sum_r << endl;
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
