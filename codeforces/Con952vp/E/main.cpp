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
    ll ans = 0;
    ll x,y,z,k;
    cin>>x>>y>>z>>k;
    ll c;
    for(ll a = 1;a<=x;a++){
        for(ll b = 1;b<=y;b++){
            if(k%(a*b)==0&&(k/(a*b))<=z){
                c = k/(a*b);
                ll way =(x-a+1)*(y-b+1)*(z-c+1);
                ans = max(way,ans);
            }
        }
    }
    cout<<ans<<endl;
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
