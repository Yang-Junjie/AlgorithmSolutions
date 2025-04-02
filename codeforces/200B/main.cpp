#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
#define LOG(a) std::cout << "[" << #a << ":" << (a) << "]" << std::endl;
using i64 = long long int;
using u64 = unsigned long long int;
using u32 = unsigned int;

void solve(){


}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    double ans = 0;
    for(int i = 1;i<=t;i++){
        double a;
        cin>>a;
        ans+=a*0.01;
    }
    cout<<ans/t*100;

    return 0;
}
