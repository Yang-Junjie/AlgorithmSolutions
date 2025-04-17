#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <numeric>
using namespace std;

#ifdef DEBUG
#define LOG(a) cerr << "[" << #a << ":" << (a) << "]" << endl
#else
#define LOG(a)
#endif

#define Len(a) ((int)(a).size())
#define All(x) (x).begin(), (x).end()
using ll = long long int;
using ull = unsigned long long int;
using PII = pair<int, int>;
using VI = vector<int>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a;
    cin >> a;
    int t;
    cin >> t;
    int cnt = 0;
    for (int i = 1; i <= a; i++)
    {
        for (auto ch : to_string(i))
        {
            if (ch == t + '0')
            {
                cnt++;
            }
        }    
    }
    cout<<cnt<<endl;
    return 0;
}
