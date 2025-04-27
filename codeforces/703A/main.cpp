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



#define ALL(x) (x).begin(), (x).end()
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


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    int m=0,c=0;
    while(n--){
        int a,b;
        cin>>a>>b;
        if(a>b){
            m++;
        }else if(a<b){
            c++;
        }
    }
    if(m>c){
        cout<<"Mishka"<<endl;
    }else if(c>m){
        cout<<"Chris"<<endl;
    }else{
        cout<<"Friendship is magic!^^"<<endl;
    }
    

    return 0;
}