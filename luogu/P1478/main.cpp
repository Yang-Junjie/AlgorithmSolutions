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

#define LEN(a) ((int)(a).size())
#define ALL(x) (x).begin(), (x).end()
using ll = long long int;
using ull = unsigned long long int;
using PII = pair<int,int>;
using VI = vector<int>;
struct Data{
    int h;
    int s;
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    cin>>n>>k;
    int l,r;
    cin>>l>>r;

    vector<Data> a(n);
    for(int i = 0;i<n;i++){
        cin>>a[i].h>>a[i].s;
    }
    sort(ALL(a),[](Data a,Data b){
        return a.s<b.s;
    });
    int ans = 0;
    for(int i = 0;i<n;i++){
        if(a[i].s<=k&&a[i].h<=l+r){
            ans++;
            k-=a[i].s;
        }
    }
    cout<<ans<<endl;
    return 0;
}