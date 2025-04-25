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

#define ALL(x) (x).begin(), (x).end()
using ll = long long int;
using ull = unsigned long long int;
using PII = pair<int, int>;

int a[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int f(int n)
{
    if (n < 10)
        return a[n];
    return f(n / 10) + a[n % 10];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    int cnt =0;
    for(int i = 0;i<=1000;i++){
        for(int j = 0;j<=1000;j++){
            cnt += (f(i)+f(j)+f(i+j)+4==n);
        }
    }
    cout<<cnt<<endl;
    return 0;
}