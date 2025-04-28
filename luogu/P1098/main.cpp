// #include <algorithm>
// #include <iostream>
// #include <string>
// #include <utility>
// #include <vector>
// #include <numeric>
// #include <limits>
// #include <iomanip>
// #include <cmath>
// #include <set>
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
    int p1, p2, p3;
    cin >> p1 >> p2 >> p3;
    string s;
    cin >> s;

    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '-' && i > 0 && i < s.size() - 1)
        {
            char left = s[i - 1], right = s[i + 1];

            bool sameType = (isdigit(left) && isdigit(right)) || (islower(left) && islower(right));
            if (sameType && left < right)
            {
                string ns;

                for (char c = left + 1; c < right; ++c)
                {
                    char ch = c;

                    if (p1 == 3)
                    {
                        ch = '*';
                    }
                    else
                    {
                        if (isalpha(ch))
                        {
                            if (p1 == 1)
                                ch = tolower(ch);
                            else if (p1 == 2)
                                ch = toupper(ch);
                        }
                    }

                    ns.append(p2, ch);
                }

                if (p3 == 2)
                    reverse(ns.begin(), ns.end());

                s.replace(i, 1, ns);
                i += ns.size() - 1;
            }
        }
    }

    cout << s << endl;

    return 0;
}
