#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;
#define LOG(a) std::cout << "[" << #a << ":" << (a) << "]" << std::endl;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    double a,b,c,p;
    cin>>a>>b>>c;
    p = 0.5*(a+b+c);
    cout<<setprecision(1)<<fixed<<sqrt(p*(p-a)*(p-b)*(p-c));
    

    return 0;
}
