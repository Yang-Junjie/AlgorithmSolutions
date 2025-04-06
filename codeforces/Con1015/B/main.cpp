#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
using namespace std;
#define LOG(a) std::cout << "[" << #a << ":" << (a) << "]" << std::endl;
using i64 = long long int;
using u64 = unsigned long long int;
using u32 = unsigned int;

void solve(){
    int n;
    cin>>n;
    vector<i64> a(n);
    for(auto& i : a){
        cin>>i;
    }
    sort(a.begin(),a.end());
    i64 x = 0;
    for(int i = 1;i<n;i++){
        if(a[i]%a[0]==0){
            x = gcd(x,a[i]);
        }
    }
    if(x == a[0]){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }

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
