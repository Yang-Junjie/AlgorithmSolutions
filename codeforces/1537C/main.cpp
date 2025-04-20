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
            std::cout << " | " << "\033[33m" << *it++ << "\033[0m";
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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(ALL(a));
    if(n==2){
        cout<<a[0]<<' '<<a[1]<<endl;
        return;
    }
    int absmn = numeric_limits<int>::max();
    int index = -1;
    
    for (int i = 0; i < n-1; i++)
    {
        if(absmn>abs(a[i]-a[i+1])){
            absmn = abs(a[i]-a[i+1]);
            index = i+1;
        }
    }

    for(int i = index;i<n;i++)
    {
        cout<<a[i]<<' ';
    }
    for(int i = 0;i<index;i++){
        cout<<a[i]<<' ';
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