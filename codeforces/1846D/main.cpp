#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <iomanip>
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
    int n,d,h;
    cin>>n>>d>>h;
    vector<long double> y(n);  
    for(int i =0;i<n;i++){
        cin>>y[i];
    }
    long double ans = (long double)d*h*n*0.5;
    for(int i = n-1;i>=1;i--){
        long double p = (long double)y[i-1]+h-y[i];
        if(p>0){
            ans-=(long double)p*p*d/h*0.5;
        }
    }
    cout << fixed << setprecision(10) << ans << endl;
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
