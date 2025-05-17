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

int Left, Right, minn, ans;
int s[5];
int a[21][5];
void search(int x, int y)
{
    if (x > s[y])
    {
        minn = min(minn, max(Left, Right));
        return;
    }
    Left += a[x][y];
    search(x + 1, y);
    Left -= a[x][y];
    Right += a[x][y];
    search(x + 1, y);
    Right -= a[x][y]; // 毫无技巧的搜索回溯
}
int main()
{
    cin >> s[1] >> s[2] >> s[3] >> s[4];
    for (int i = 1; i <= 4; i++)
    { // 减少码量
        Left = Right = 0;
        minn = 19260817;
        for (int j = 1; j <= s[i]; j++)
            cin >> a[j][i];
        search(1, i);
        ans += minn;
    }
    cout << ans;
    return 0;
}