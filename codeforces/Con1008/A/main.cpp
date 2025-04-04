#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define LOG(a) std::cout << "[" << #a << ":" << (a) << "]" << std::endl;
using i64 = long long int;
using u64 = unsigned long long int;
using u32 = unsigned int;

void solve(){
int a,b;
cin>>a>>b;
int avg = 0;
for(int i = 0;i<a;i++){ 
    int tmp;
    cin>>tmp;
    avg+=tmp;
}

if(avg/a==b && avg%a == 0){
    cout<<"YES"<<endl;
}else  
    cout<<"NO"<<endl;

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
