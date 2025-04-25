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

#define LEN(a) ((int)(a).size())
#define ALL(x) (x).begin(), (x).end()
using ll = long long int;
using ull = unsigned long long int;
using PII = pair<int, int>;
using VI = vector<int>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<string> ans;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        string tmp;
        cin >> tmp;
        bool isans = true;
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] != '*' && s[j] != tmp[j])
            {
                isans = false;
            }
        }
        if (isans)
        {
            cnt++;
            ans.push_back(tmp);
        }
    }
    cout << cnt << endl;
    if (!ans.empty())
    {
        for (auto i : ans)
        {
            cout << i << endl;
        }
    }
    return 0;
}