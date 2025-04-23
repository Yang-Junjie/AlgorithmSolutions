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

    int main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        string s;
        cin>>s;
        string t = s;
        sort(ALL(t));
        if(t!=s){
            cout<<"NO"<<endl;
            return 0;
        }
        int cnta = 0,cntb = 0,cntc=0;
        for(int i = 0;i<s.size();i++){
            if(s[i]=='a')cnta++;
            if(s[i]=='b')cntb++;
            if(s[i]=='c')cntc++;    
        }
        if(cnta==0||cntb==0){
            cout<<"NO"<<endl;
            return 0;
        }
        if(cntc!=cnta&&cntc!=cntb){
            cout<<"NO";
             return 0;
        }
        
        cout<<"YES"<<endl;
        return 0;
    }