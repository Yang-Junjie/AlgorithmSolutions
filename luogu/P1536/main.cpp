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
const int N = 1010;
int p[N];
int find(int x)
{
    if (p[x] == x)
    {
        return x;
    }
    return p[x] = find(p[x]);
}
void joint(int x, int y)
{
    int f1 = find(x), f2 = find(y);
    if (f1 == f2)
    {
        return;
    }
    p[f1] = find(f2);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (true)
    {
        int n, m;
        cin >> n;
        if (n == 0)
            break;
        for (int i = 1; i <= n; i++)
        {
            p[i] = i;
        }
        cin >> m;
        int x = 0, y = 0;
        while (m--)
        {
            cin >> x >> y;
            joint(x, y);
        }
        int cnt = 0;
        int fx = find(n);
        for (int i = 1; i <= n; i++)
        {
           
            if (find(i) == fx)
            {
                continue;
            }
            else
            {
                joint(i,fx);
                //LOG(i,find(i),fx);
                cnt++;
            }
        }
        cout << cnt << endl;
    }

    return 0;
}
