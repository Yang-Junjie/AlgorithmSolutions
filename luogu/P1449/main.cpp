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
    stack<ll> q;
    string s;
    cin>>s;
    ll a=0,b=0,i,j;
    for(int k = 0;k<s.size();k++){
        if(s[k]=='@')break;
        else if (s[k]=='.'){
            q.push(a);
            b = a = 0;
        }
        else if('0'<=s[k]&&s[k]<='9'){
            a = b*10+s[k]-'0';
            b =a;
        }
        else{
            if(s[k]=='-')i = q.top(),q.pop(),j = q.top(),q.pop(),q.push(j-i);
            if(s[k]=='+')i = q.top(),q.pop(),j = q.top(),q.pop(),q.push(j+i);
            if(s[k]=='*')i = q.top(),q.pop(),j = q.top(),q.pop(),q.push(i*j);
            if(s[k]=='/')i = q.top(),q.pop(),j = q.top(),q.pop(),q.push(j/i);
        }
    }
   cout<<q.top()<<endl; 

    return 0;
}
