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
    int n;
    cin>>n;
    unordered_map<string,int> m;
    while(n--){
        int op;
        cin>>op;
         string name;
        if(op == 1){
            int num;
            cin>>name>>num;
            m[name] = num;
            cout<<"OK"<<endl;
        }else if (op == 2){
            cin>>name;
            if(m.find(name)!=m.end()){
                cout<<m[name]<<endl;
            }else{
                cout<<"Not found"<<endl;
            }
        }else if(op == 3){
            cin>>name;
            auto it = m.find(name);
            if(it!=m.end()){
                m.erase(it);
                cout<<"Deleted successfully"<<endl;
            }else{
                cout<<"Not found"<<endl;
            }
        }
        else{
            cout<<m.size()<<endl;
        }
    }
    

    return 0;
}
