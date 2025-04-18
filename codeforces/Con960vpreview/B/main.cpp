#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <numeric>
using namespace std;

#ifdef DEBUG
#define LOG1(a) cerr << "[" << #a << ":" << (a) << "]" << endl
#define LOG2(a,b) cerr << "[" << #a << ":" << (a) <<","<< #b << ":" << (b) << "]" << endl
template<typename Container>
void PrintCon(const Container& cont) {
    std::cout << "{ ";
    if (!cont.empty()) {
        auto it = cont.begin();
        std::cout <<"\033[33m"<< *it++<< "\033[0m";
        for (; it != cont.end(); ++it)
            std::cout << " | " << *it;
    }
    std::cout << " }" << std::endl;
}

#else
#define LOG(a)
#endif

#define LEN(a) ((int)(a).size())
#define ALL(x) (x).begin(), (x).end()
using ll = long long int;
using ull = unsigned long long int;
using PII = pair<int,int>;
using VI = vector<int>;

void solve(){
    int n,x,y;
    cin>>n>>x>>y;
    int a;
    y--;
    for(int i =0;i<n;i++){
        if(i<y){
            a = (y-i)%2==0?1:-1;
        }
        else if(i<x){
            a = 1;
        }
        else{
            a=  (x-i)%2==0?-1:1;
        }
        cout<<a<<' ';
    }
    cout<<endl;
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