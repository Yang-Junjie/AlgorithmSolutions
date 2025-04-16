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
struct pep{
    int id;
    int src;
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<pep> a;
    vector<pep> b;
    for(int i = 0;i<n;i++){
        pep tmp;
        cin>>tmp.id>>tmp.src;
        a.push_back(tmp);
    }
    sort(All(a),[](pep a,pep b){
        if(a.src!=b.src){
            return a.src>b.src;
        }
        return a.id<b.id;
    });
    int l = m*1.5;
    for(auto s:a){
        if(s.src>=a[l-1].src){
            b.push_back(s);
        }
    }
    cout<<a[l-1].src<<' '<<b.size()<<endl;
    for(auto s:b){
        cout<<s.id<<' '<<s.src<<endl;
    }

    return 0;
}
