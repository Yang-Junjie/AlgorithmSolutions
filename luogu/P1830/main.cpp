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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<vector<pair<int, int>>> a(n, vector<pair<int, int>>(m, {0, 0}));
    int sum = 0;
    while (x--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        sum++;
        for (int r = x1 - 1; r <= x2 - 1; r++)
        {
            for (int c = y1 - 1; c <= y2 - 1; c++)
            {
                a[r][c].first++;
                a[r][c].second = sum;
            }
        }
    }
    while (y--)
    {
        int r, c;
        cin >> r >> c;
        if (a[r - 1][c - 1].first != 0)
        {
            cout << "Y" << ' ' << a[r - 1][c - 1].first << ' ' << a[r - 1][c - 1].second << endl;
        }
        else
        {
            cout << "N" << endl;
        }
    }

    return 0;
}
