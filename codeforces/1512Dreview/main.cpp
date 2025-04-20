#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <numeric>
#include <limits>
#include <cmath>
using namespace std;

#define DEBUG
#ifdef DEBUG
#define LOG1(a) cerr << "[" << #a << ":" << (a) << "]" << endl
#define LOG2(a, b) cerr << "[" << #a << ":" << (a) << "," << #b << ":" << (b) << "]" << endl
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

#else
#define LOG(a)
#endif

#define LEN(a) ((int)(a).size())
#define ALL(x) (x).begin(), (x).end()
using ll = long long int;
using ull = unsigned long long int;
using PII = pair<int, int>;
using VI = vector<int>;

void solve()
{
    ll n;
    cin >> n;
    int k = n + 2;
    vector<ll> b(k);
    for (int i = 0; i < k; ++i) {
        cin >> b[i];
    }
    sort(ALL(b));
    
    vector<ll> s(k + 1, 0);
    for (int i = 1; i <= k; ++i) {
        s[i] = s[i - 1] + b[i - 1];
    }
    
    if (b[n] == s[n]) {
        for (int i = 0; i < n; ++i) {
            cout << b[i] << " ";
        }
    } else {
        ll target = b.back(); 
        ll sum = s[n + 1];    
        int found = -1;
        
        for (int i = 0; i <= n; ++i) {
            if (target == sum - b[i]) {
                found = i;
                break;
            }
        }
        
        if (found != -1) {
            for (int i = 0; i <= n; ++i) {
                if (i != found) {
                    cout << b[i] << " ";
                }
            }
        } else {
            cout << -1;
        }
    }
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}