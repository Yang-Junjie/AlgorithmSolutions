#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <iomanip>
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
    int n,t;
    cin>>n>>t;
    vector<double> a(n);
    vector<double> w(n);
    vector<double> v(n);
    for(int i = 0;i<n;i++){ 
        cin>>w[i]>>v[i];
        a[i] = v[i]/w[i];
    }
    sort(ALL(a));
    double nowv = 0;
    double ans = 0;
    for(int i = 0;i<n;i++){
        if(t-w[i]>-0.000001)
		{
			t-=w[i];
			ans+=v[i];
		}
		else
		{
			ans+=t*a[i];
			break;
		}
    }
    cout<<setprecision(2)<<fixed<<ans<<endl;

    

    return 0;
}