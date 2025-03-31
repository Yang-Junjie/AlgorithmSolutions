#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
#define LOG(a) std::cout << "[" << #a << ":" << (a) << "]" << std::endl;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    double t;
    int n;
    cin>>t>>n;
    cout<<setprecision(3)<<fixed<<t/n<<endl;
    cout<<n*2;
    

    return 0;
}
