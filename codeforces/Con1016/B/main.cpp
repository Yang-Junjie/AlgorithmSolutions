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
using PII = pair<int,int>;

void solve(){
    string a;
    cin>>a;
    int cnt = 0;
    int i = a.size()-1;
    while(i>=0&&a[i]=='0'){
        cnt++;
        i--;
    }
    int cnt2 = 0;
    for(int j = 0;j<i;j++){
        if(a[j]!='0'){
            cnt2++;
        }
    }
    cout<<cnt+cnt2<<endl;

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
