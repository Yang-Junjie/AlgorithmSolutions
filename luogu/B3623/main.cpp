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
const int N = 15;
bool vis[N];
int p[N];
int n,k;
void dfs(int x){
    if(x>k){
        for(int i = 1;i<=k;i++) {
            cout<<p[i]<<" ";
        }
        cout<<endl;
        return;
    }
    for(int i = 1;i<=n;i++){
        if(!vis[i]){
           p[x] = i;
            vis[i] = true; 
           dfs(x+1);
            vis[i] = false;
        } 
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    dfs(1); 
    

    return 0;
}
