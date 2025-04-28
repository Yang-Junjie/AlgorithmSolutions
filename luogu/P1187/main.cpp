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


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> dc = {-1,1,0,0},dr={0,0,-1,1};
    int n,m;
    cin>>n>>m;
    int ans = 0;
    vector<vector<int>> a(n+2,vector<int>(m+2,0));
    for(int i = 1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char c;
            cin>>c;
            a[i][j] = c-'0';
            if(c-'0'!=0){
                ans+=2;
            }
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            for(int k = 0;k<4;k++){
                if(a[i][j]>a[i+dr[k]][j+dc[k]]){
                    ans+=a[i][j]-a[i+dr[k]][j+dc[k]];
                }
            }
        }
    }

    cout<<ans<<endl;

    

    return 0;
}
