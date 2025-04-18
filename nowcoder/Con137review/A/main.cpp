#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <numeric>
using namespace std;


#ifdef DEBUG
#define LOG1(a) cerr << "[" << #a << ":" << (a) << "]" << endl
#define LOG2(a,b) cerr << "[" << #a << ":" << (a) <<","<< #b << ":" << (b) << "]" << endl
template<typename Container>
void PrintCon(const Container& cont) {
    std::cout << "{ ";
    if (!cont.empty()) {
        auto it = cont.begin();
        std::cout <<"\033[33m"<< *it++<< "\033[0m";
        for (; it != cont.end(); ++it)
            std::cout << " | " << *it;
    }
    std::cout << " }" << std::endl;
}

#else
#define LOG(a)
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
    
    int n;
    cin>>n;
    if(n==1){
        cout<<"A Problem"<<endl;
    }
    else if(n==2){
        cout<<"A+B Problem"<<endl;
        cout<<"B+A Problem"<<endl;
    }else if(n==3){
        cout<<"A+B+C Problem\nA+C+B Problem\nB+A+C Problem\nB+C+A Problem\nC+A+B Problem\nC+B+A Problem"<<endl;
    }else{
        cout<<"A+B+C+D Problem\nA+B+D+C Problem\nA+C+B+D Problem\nA+C+D+B Problem\nA+D+B+C Problem\nA+D+C+B Problem\nB+A+C+D Problem\nB+A+D+C Problem\nB+C+A+D Problem\nB+C+D+A Problem\nB+D+A+C Problem\nB+D+C+A Problem\nC+A+B+D Problem\nC+A+D+B Problem\nC+B+A+D Problem\nC+B+D+A Problem\nC+D+A+B Problem\nC+D+B+A Problem\nD+A+B+C Problem\nD+A+C+B Problem\nD+B+A+C Problem\nD+B+C+A Problem\nD+C+A+B Problem\nD+C+B+A Problem"<<endl;
    }

    return 0;
}