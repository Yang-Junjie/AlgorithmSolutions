#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <sys/types.h>
#include <utility>
#include <vector>
#include <numeric>
#include <limits>
#include <cmath>
#include <iomanip>
#include <set>
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

void solve(){
    int n;
    cin>>n;
    set<int> a;
    for(int i = 0;i<n;i++){
        int tmp;
        cin>>tmp;
        a.insert(tmp);
    }
    cout<<a.size()<<endl;
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
