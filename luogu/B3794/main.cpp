#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <numeric>
#include <limits>
#include <iomanip>
#include <cmath>
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
    double ans = 0;
    double a,b,c;
    cin>>a>>b>>c;
    ans+=((a+c)*(b+c)-(c*c)+0.25*(c*c*3.1415926535))*0.0001;
    cout<<setprecision(3)<<fixed<<ans<<endl;

    return 0;
}