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
    string s;
    cin >> s;
    bool isup = true;
    bool isfirstlow = (islower(s[0]) ? true : false);
    bool chule = true;
    for (int i = 0; i < s.size(); i++)
    {
        if (islower(s[i])){
            isup = false;
            break;
        }
    }
    for (int i = 1; i < s.size(); i++)
    {
        if (islower(s[i])){
            chule = false;
            break;
        }
    }
    if (isup || (isfirstlow && chule))
    {
        std::string result;
        for (char c : s)
        {
            if (isupper(c))
            {
                result += tolower(c);
            }
            else if (islower(c))
            {
                result += toupper(c);
            }
            else
            {
                result += c;
            }
        }
        cout << result << endl;
    }
    else
    {
        cout << s << endl;
    }

    return 0;
}
