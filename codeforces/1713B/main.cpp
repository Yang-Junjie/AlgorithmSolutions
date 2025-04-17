#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <numeric>
using namespace std;

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
int maxv = 0;
for(int i = 0;i<n;i++){
    cin>>a[i];
    if(a[maxv]<a[i]){
         maxv = i;
    }
}
bool flag = true;
for(int i = maxv;i>0;i--){
    if(a[i]<a[i-1]){
        flag = false;
    }
}
for(int i = maxv;i<n-1;i++){
    if(a[i]<a[i+1]){
        flag = false;
    }
}
if(flag){
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
