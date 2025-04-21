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

#define DEBUG

#ifdef DEBUG
#define VarToStr(x) #x
template<typename... Args>
void LOG(Args&&... args) {

    ( (std::cout <<"\033[33m"<< std::forward<Args>(args) <<"\033[0m"<< " "), ... );
    std::cout << std::endl;
}
template<typename Container>
void PrintCon(const Container& cont) {
    std::cout << "{ ";
    if (!cont.empty()) {
        auto it = cont.begin();
        std::cout <<"\033[33m"<< *it++<< "\033[0m";
        for (; it != cont.end(); ++it)
            std::cout << " | " <<"\033[33m"<< *it<< "\033[0m";
    }
    std::cout << " }" << std::endl;
}

#else
template<typename ...Args>
void LOG(Args& ...args);
    
template<typename Container>
void PrintCon(const Container& cont);
#endif

#define LEN(a) ((int)(a).size())
#define ALL(x) (x).begin(), (x).end()
using ll = long long int;
using ull = unsigned long long int;
using PII = pair<int, int>;
using VI = vector<int>;
bool isPrime(int x)
{
    if (x <= 1)
        return false;
    for (int i = 2; i <= x / i; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &i : a)
    {
        cin >> i;
    }

    int ans = 0;
    int U = (1 << n);
    for (int S = 0; S < U; S++)
    {
        if (__builtin_popcount(S) == k)
        {

            int sum = 0;
            for (int i = 0; i < n; i++)
            {
                if (S & (1 << i))
                    sum += a[i];
            }
            if (isPrime(sum))
                ans++;
        }
    }
    LOG(ans,n,k);
    cout << ans << endl;
    return 0;
}