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
        string s;
        cin>>s;
        int cnt0= 0;
        for(int i =0;i<n;i++){
            if(s[i]=='0'){
                cnt0++;
            }
        }
        if(cnt0==1){
            cout<<"BOB"<<endl;
            return;
        }
        if(cnt0==0){
            cout<<"DRAW"<<endl;
            return;
        }
        int mid = (n-2+1)/2;
        if(cnt0&1){
            if(s[mid]==1){
                cout<<"BOB"<<endl;
            }else{
                cout<<"ALICE"<<endl;
            }
        }else{
            cout<<"BOB"<<endl;
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