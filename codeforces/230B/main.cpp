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
bool isPrime(ll x){
  if(x<2)return false;
  for(ll i = 2;i<=x/i;i++){
    if(x%i==0)return false;
  }
  return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    while(n--){
        ll x;
        cin>>x;
        ll sq = sqrt(x);
        if(sq*sq==x){
            if(isPrime(sq)){
              cout<<"YES"<<endl;
            }else{
              cout<<"NO"<<endl;
            } 
        }
        else{
           cout<<"NO"<<endl;
        }
    }

    return 0;
}
