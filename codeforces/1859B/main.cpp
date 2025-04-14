#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <numeric>
using namespace std;
#define LOG(a) std::cout << "[" << #a << ":" << (a) << "]" << std::endl;
using i64 = long long int;
using u64 = unsigned long long int;
using u32 = unsigned int;
using PII = pair<int, int>;

void solve()
{
    int n;
    cin >> n;
    vector<int> min1;
    vector<int> min2;
    while (n--)
    {
        int t;
        cin >> t;
        
        vector<int> a(t);
        for (int i = 0; i < t; i++)
        {
            cin >> a[i];
            
        }
        
        sort(a.begin(), a.end());
        min1.push_back(a[0]);
        min2.push_back(a[1]);
        
        
    }
    sort(min1.begin(), min1.end());
    sort(min2.begin(), min2.end());
    min2[0] = min1[0];
    int ans = 0;
    for(auto i:min2){
        ans+=i;
    }
    cout << ans << endl;
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
