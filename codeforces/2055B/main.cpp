#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <numeric>
using namespace std;
#define DEBUG
#ifdef DEBUG
#define LOG(a) cerr << "[" << #a << ":" << (a) << "]" << endl
#else
#define LOG(a)
#endif

#define Len(a) ((int)(a).size())
#define All(x) (x).begin(), (x).end()
using ll = long long int;
using ull = unsigned long long int;
using PII = pair<int,int>;
using VI = vector<int>;

void solve(){
    int n;
    cin>>n;
    VI a(n);
    VI b(n);
    VI sub(n);
    for(int i = 0;i<n;i++)cin>>a[i];
    for(int i =0;i<n;i++)cin>>b[i];
    for(int i =0;i<n;i++)sub[i] = a[i]-b[i];
    int cnt = 0;
    bool is_ok = true;
    for(int i = 0;i<n;i++){
        if(sub[i]<0){
            is_ok = false;
            cnt++;
        }
        if(cnt>=2){
            cout<<"NO"<<endl;
            return;
        }
    }
    if(is_ok){
        cout<<"YES"<<endl;
        return;
    }
    sort(All(sub));
    bool ans = true;
    for(int i = 1;i<n;i++){
        if(sub[0]+sub[i]<0){
            ans = false;
        }
    }
    if(ans){
        cout<<"YES"<<endl;
        
    }else{
       
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
