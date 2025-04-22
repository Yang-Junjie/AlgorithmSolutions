#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <numeric>
#include <string>
#include <utility>
#include <vector>
using namespace std;
#define DEBUG
#ifdef DEBUG
template <typename Container>
void PrintCon(const Container& cont)
{
    std::cout << "{ ";
    if (!cont.empty()) {
        auto it = cont.begin();
        std::cout << "\033[33m" << *it++ << "\033[0m";
        for (; it != cont.end(); ++it)
            std::cout << " | " << "\033[33m" << *it << "\033[0m";
    }
    std::cout << " }" << std::endl;
}

template <typename... Args>
void LOG(Args&&... values)
{
    ((std::cout << "\033[33m" << std::forward<Args>(values) << "\033[0m" << " "), ...);
    std::cout << std::endl;
}
#else
template <typename... Args>
void LOG(Args&... args);

template <typename Container>
void PrintCon(const Container& cont);
#endif

#define LEN(a) ((int)(a).size())
#define ALL(x) (x).begin(), (x).end()
using ll = long long int;
using ull = unsigned long long int;
using PII = pair<int, int>;
using VI = vector<int>;

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    s='0'+s;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] != s[i - 1]) {
            cnt++;
        }
    }
    if(cnt==2){
        cnt--;
    }else if(cnt>2){
        cnt-=2;
    }
    cnt+=n;
    cout << cnt << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
