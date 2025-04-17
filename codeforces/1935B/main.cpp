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
    for(int i =0;i<n;i++){
        cin>>a[i];
    }
    VI pre(n);
    VI suf(n);
    VI cnt(n);

    int x =0;
    for(int i = 1;i<n;i++){
        cnt[a[i-1]]++;
        while(cnt[x]){
            x++;
        }
        pre[i] = x;
    }
     x =0;
    cnt.assign(n,0);
    for(int i = n-1;i>0;i--){
        cnt[a[i]]++;
        while(cnt[x]){
            x++;
        }
        suf[i] = x;
    }

    bool is_ans = false;
    int l =-1;
    for(int i = 1;i<n;i++){
        if(pre[i] == suf[i]){
            is_ans = true;
            l=i;
        }
    }
if(is_ans){
    cout<<2<<'\n';
    cout<<1<<' '<<l<<endl;
    cout<<l+1<<' '<<n<<endl;
}
else{
    cout<<-1<<endl;
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
