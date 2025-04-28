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
    unordered_map<string, int> q;
    q["one"] = 1;
    q["two"] = 2;
    q["three"] = 3;
    q["four"] = 4;
    q["five"] = 5;
    q["six"] = 6;
    q["seven"] = 7;
    q["eight"] = 8;
    q["nine"] = 9;
    q["ten"] = 10;
    q["eleven"] = 11;
    q["twelve"] = 12;
    q["thirteen"] = 13;
    q["fourteen"] = 14;
    q["fifteen"] = 15;
    q["sixteen"] = 16;
    q["seventeen"] = 17;
    q["eighteen"] = 18;
    q["nineteen"] = 19;
    q["twenty"] = 20;
    q["a"] = 1;
    q["both"] = 2;
    q["another"] = 1;
    q["first"] = 1;
    q["second"] = 2;
    q["third"] = 3;
    vector<int> a;
    for (int i = 0; i < 6; i++)
    {
        string s;
        cin >> s;
        if (q[s])
        {
            int num = q[s] * q[s] % 100;
            a.push_back(num);
        }
    }
    sort(ALL(a));
    if (a.size() != 0)
    {
        cout << a[0];
    }
    else
    {
        cout << 0;
    }
    for (int i = 1; i < a.size(); i++)
    {
        int num = a[i];
        if (num < 10)
        {
            cout << 0;
        }
        cout << num;
    }

    return 0;
}
