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

template<typename... Args>
void LOG(Args&&... values) {
    ((std::cout <<"\033[33m"<< std::forward<Args>(values) << "\033[0m"<< " "), ...);
    std::cout << std::endl;
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
using PII = pair<int,int>;
using VI = vector<int>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    bool flg = false, ok = true;
    ll cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (b[i] != -1)
        {
            ll p = a[i] + b[i];

            if (!flg)
            {
                flg = true;
                cnt = p;
            }
            else if (p != cnt)
            {
                ok = false;
                break;
            }
        }
    }
    if (!ok)
    {
        cout << 0 << endl;
        return;
    }
    if (flg)
    {
        for (int i = 0; i < n; i++)
        {
            if (b[i] == -1)
            {
                ll bi = cnt - a[i];
                if (bi < 0 || bi > k)
                {
                    ok = false;
                    break;
                }
            }
        }
        cout << (ok ? 1 : 0) << endl;
    }
    else
    {
        ll L = 0, R = numeric_limits<ll>::max();
        for (int i = 0; i < n; i++)
        {
            L = max(L, a[i]);
            R = min(R, a[i] + k);
        }
        cout << (R >= L ? R - L + 1 : 0) << endl;
    }
    return 0;
}