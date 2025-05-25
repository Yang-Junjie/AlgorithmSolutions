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
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>> a(n,vector<int>(m,0));
    vector<vector<int>> b(m,vector<int>(k,0));
     vector<vector<int>> c(n,vector<int>(k,0));
    
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++)
            cin>>a[i][j];
    }
    for(int i = 0;i<m;i++){
        for(int j = 0;j<k;j++){
          cin>>b[i][j];
        }
    }
    
    for(int i = 0;i<n;i++){
      for(int j = 0;j<m;j++){
        for(int o = 0;o<k;o++){
          c[i][o] += a[i][j]*b[j][o];
        }
      }
    }
    for(auto i:c){
      for(auto x:i){
        cout<<x<<" ";
      }
      cout<<endl;
    }
    return 0;
}