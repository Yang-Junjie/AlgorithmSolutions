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
    vector<int> s(4);
    for (int i = 0; i < 4; i++)
    {
        cin >> s[i];
    }
    vector<vector<int>> a(4, vector<int>());
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < s[i]; j++)
        {
            int tmp;
            cin >> tmp;
            a[i].push_back(tmp);
        }
    }
    for (int i = 0; i < 4; i++)
    {
        sort(ALL(a[i]), [](int a, int b)
             { return a > b; });
    }
    int ans = 0;
    for (int i = 0; i < 4; i++)
    {
        if (a[i].size() <= 2)
        {
            ans += *max_element(ALL(a[i]));
        }
        else
        {
            bool flag = true;;//存在非0
            for (int j = 0; flag; j++)
            {
                if(a[i][j]!=0)flag = true;
                ans += a[i][1];
                a[i][0] -= a[i][1];
                a[i][1] = 0;
                sort(ALL(a[i]), [](int a, int b)
                     { return a > b; });
                if(a[i][1]==0){
                    ans+=a[i][0];
                    break;
                }
                if(!flag)break;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}