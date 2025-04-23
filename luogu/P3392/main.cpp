// #include <algorithm>
// #include <iostream>
// #include <string>
// #include <utility>
// #include <vector>
// #include <numeric>
// #include <limits>
// #include <iomanip>
// #include <cmath>
// #include <set>
#include <bits/stdc++.h>
using namespace std;

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

#define LEN(a) ((int)(a).size())
#define ALL(x) (x).begin(), (x).end()
using ll = long long int;
using ull = unsigned long long int;
using PII = pair<int,int>;
using VI = vector<int>;
string s;
int n,m;
inline int check(char c){
    int tot=0;
    for(int i=0;i<m;++i)
        if(s[i]!=c)++tot;
    return tot;    
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    vector<int> w(51,0);
    vector<int> b(51,0);
    vector<int> r(51,0);
    for(int i=1;i<=n;i++){
        cin>>s;
        w[i]=w[i-1]+check('W');
        b[i]=b[i-1]+check('B');
        r[i]=r[i-1]+check('R');
    }
    int ans = numeric_limits<int>::max();
    for(int i = 1;i<n-1;i++){
        for(int j = i+1;j<n;j++){
            ans=min(ans,w[i]+b[j]-b[i]+r[n]-r[j]);
        }
    }
    cout<<ans<<endl;
    return 0;
}