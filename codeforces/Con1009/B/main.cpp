#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
#define LOG(a) std::cout << "[" << #a << ":" << (a) << "]" << std::endl;
using i64 = long long int;
using u64 = unsigned long long int;
using u32 = unsigned int;

void solve(){
    const int N = 2e5+10;
    i64 a[N];
    a[0] = 0;
    int n;
    cin>>n;
    i64 ans = 0;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    sort(a,a+n+1);
    for(int i = 2;i<=n;i++){
        a[i] = a[i]+a[i-1]-1;;
    }

    cout<<a[n]<<endl;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
