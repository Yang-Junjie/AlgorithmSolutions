#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
#define LOG(a) std::cout << "[" << #a << ":" << (a) << "]" << std::endl;

long long int gcd(long long int a,long long int b){
    return b==0?a:gcd(b,a%b);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a,b,c;
    cin>>a>>b>>c;
    int the_max = max(max(a,b),c);
    int the_min = min(min(a,b),c);
    int the_gcd = gcd(the_min,the_max);
    cout<<the_min/the_gcd<<'/'<<the_max/the_gcd;
    

    return 0;
}
