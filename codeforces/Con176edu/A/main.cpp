#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
#define LOG(a) std::cout << "[ " << #a << ":" << (a) << " ]" << std::endl;
using i64 = long long int;
using u64 = unsigned long long int;
using u32 = unsigned int;
void solve()
{
    i64 n,k;
    i64 cnt=0;
    cin>>n>>k;
    if(n%2==1)n-=k,cnt++;
    k--;
    cnt +=(n+k-1)/k;
    cout<<cnt<<endl;
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
