#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <numeric>
#include <limits>
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
            std::cout << " | " <<"\033[33m"<< *it++<< "\033[0m";
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
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
	if(a*c<-2147483648||a*c>2147483647||b*d<-2147483648||b*d>2147483647||a*d<-2147483648||a*d>2147483647||b*c<-2147483648||b*c>2147483647){
		cout<<"long long int";
	}else{
		cout<<"int";
	}

    return 0;
}