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

char a[50] = {"qwertyuiopasdfghjkl;zxcvbnm,./"};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    char k;
    string s;
    cin >> k >> s;
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = 0; j <= 29; j++)
        {
            if (s[i] == a[j])
            {
                if (k == 'R')
                {
                    cout << a[j - 1];
                }
                else
                {
                    cout << a[j + 1];
                }
            }
        }
    }
    cout << endl;
    return 0;
}
