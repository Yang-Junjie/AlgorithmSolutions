#include <bits/stdc++.h>
using namespace std;



#define all(x) (x).begin(), (x).end()
#define maxv(a, l, r) *std::max_element((a).begin() + (l), (a).begin() + (r))
#define minv(a, l, r) *std::min_element((a).begin() + (l), (a).begin() + (r))



using ll = long long int;
using ull = unsigned long long int;
using pii = pair<int,int>;

#define debug
#ifdef debug
template<typename container>
void printcon(const container& cont) {
    std::cout << "{ ";
    if (!cont.empty()) {
        auto it = cont.begin();
        std::cout <<"\033[33m"<< *it++<< "\033[0m";
        for (; it != cont.end(); ++it)
            std::cout << " | " <<"\033[33m"<< *it<< "\033[0m";
    }
    std::cout << " }" << std::endl;
}

template<typename... args>
void log(args&&... values) {
    ((std::cout <<"\033[33m"<< std::forward<args>(values) << "\033[0m"<< " "), ...);
    std::cout << std::endl;
}

#else

template<typename ...args>
void log(args& ...args);
template<typename container>
void printcon(const container& cont);

#endif


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    if(n>m){
      n-=m;
      cout<<m<<' '<<n/2<<endl;
    }else{
      m-=n;
      cout<<n<<' '<<m/2<<endl;
    }
    

    return 0;
}
