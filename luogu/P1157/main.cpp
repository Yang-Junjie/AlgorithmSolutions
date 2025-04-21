#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <numeric>
#include <limits>
#include <iomanip>
#include <cmath>
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int S = (1 << n) - 1; S >= 0; S--)
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (S & (1 << i))
            {
                a[cnt++] = i;
            }
        }
        if(cnt==k){
            for(int i = k-1;i>=0;i--){
                cout<<setw(3)<<n-a[i];
            }
            cout<<endl;
        }
        
    }
    

    return 0;
}