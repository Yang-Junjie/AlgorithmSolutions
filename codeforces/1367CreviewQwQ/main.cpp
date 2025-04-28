// #include <algorithm>
// #include <iostream>
// #include <string>
// #include <utility>
// #include <vector>
// #include <numeric>
// #include <limits>
// #include <cmath>
// #include <iomanip>
#include <bits/stdc++.h>
using namespace std;


#define ALL(x) (x).begin(), (x).end()
#define MAXV(a, l, r) *std::max_element((a).begin() + (l), (a).begin() + (r))
#define MINV(a, l, r) *std::min_element((a).begin() + (l), (a).begin() + (r))


using ll = long long int;
using ull = unsigned long long int;
using PII = pair<int,int>;

#define DEBUG

#ifdef DEBUG
template<typename Container>
void PrintCon(const Container& cont) {
    std::cout << "{ ";
    if (!cont.empty()) {
        auto it = cont.begin();
        std::cout <<"\033[33m"<< *it++<< "\033[0m";
        for (; it != cont.end(); ++it)
            std::cout << " | " <<"\033[33m"<< *it<< "\033[0m";
    }
    std::cout << " }" << std::endl;
}

template<typename... Args>
void LOG(Args&&... values) {
    ((std::cout <<"\033[33m"<< std::forward<Args>(values) << "\033[0m"<< " "), ...);
    std::cout << std::endl;
}
#else
template<typename ...Args>
void LOG(Args& ...args);
    
template<typename Container>
void PrintCon(const Container& cont);
#endif


void solve(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int cnt = count(ALL(s),'1');
    int ans =0;
    int ans2= 0;
    if(cnt==0){
        ans = (n+k)/(k+1);
    }
    else{
        for(int i = 0;i<n-k-1;i++){
            if(s[i]=='1'&&s[i+k+1]!='1'){
                ans++;
            }
        }
        reverse(ALL(s));
        for(int i = 0;i<n-k-1;i++){
            if(s[i]=='1'&&s[i+k+1]!='1'){
                ans2++;
            }
        }
    }
    cout<<max(ans,ans2)<<endl;
   //LOG(max(ans,ans2));
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
