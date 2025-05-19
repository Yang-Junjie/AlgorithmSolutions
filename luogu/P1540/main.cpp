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
    int m, n;
    cin >> m >> n;
    queue<int> rom;
    int ans = 0;
    while (n--)
    {
        int ch;
        cin >> ch;
        bool have = false;
        if (!rom.empty())
        {
            queue<int> temp = rom;
            while (!temp.empty())
            {
                if (temp.front() == ch)
                {
                    have = true;
                    break;
                }
                temp.pop();
            }
            if (!have)
            {
                if (rom.size() == m)
                {
                    rom.pop();
                    rom.push(ch);
                }
                else
                {
                    rom.push(ch);
                }
                ans++;
            }
        }
        else
        {
            ans++;
            rom.push(ch);
        }
    }
    cout << ans << endl;

    return 0;
}
