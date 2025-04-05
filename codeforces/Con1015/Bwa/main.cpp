#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
#define LOG(a) std::cout << "[" << #a << ":" << (a) << "]" << std::endl;
using i64 = long long int;
using u64 = unsigned long long int;
using u32 = unsigned int;
u64 gcd(u64 a, u64 b)
{
    return b == 0 ? a : gcd(b, a % b);
}
void solve()
{
    const int N = 1e5 + 10;
    u64 a[N];
    int n;
    cin >> n;
    for(int i = 1;i<=n;i++)cin>>a[i];
    if(n<=2){
        if(a[1]%a[2]==0){
            cout<<"YES"<<endl;
            return;
        }
        else{
            cout<<"NO"<<endl;
            return;
        }
    }
    else if(n==3){

    }
    else{
        a[0] = a[n];
        u64 the_min = *min_element(a,a+n);
        if(a[n-1]%the_min==0&&a[n-2]%the_min==0){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
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
