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
int n,m;
cin>>n>>m;
VI col(m);
VI row(n);
for(int i = 0;i<n;i++)
{
    for(int j = 0;j<m;j++){
        char ch;
        cin>>ch;
        if(ch=='#'){
            col[j]++;
            row[i]++;
        }
    }
}    
auto c = max_element(All(col));
auto r = max_element(All(row));
cout<<r-row.begin()+1<<' '<<c-col.begin()+1<<endl;

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
