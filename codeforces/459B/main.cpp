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
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(int i = 0;i<n;i++)cin>>a[i];
    ll mxnum = 1,mnnum = 1;
    sort(ALL(a));
    
    for(int i = 1;i<n;i++){
      if(a[i]!=a[0]){
        break;
      }else{
        mnnum++;
      }
    }
     for(int i = n-2;i>=0;i--){
      if(a[i]!=a[n-1]){
        break;
      }else{
        mxnum++;
      }
    }
     if(a[n-1]==a[0]){
       cout<<0<<' '<<n*(n-1)/2<<endl;
     }else{
   cout<<a[n-1]-a[0]<<' '<<mnnum*mxnum<<endl;
     }
    return 0;
}
