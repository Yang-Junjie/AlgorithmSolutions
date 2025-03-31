#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
#define LOG(a) std::cout << "[" << #a << ":" << (a) << "]" << std::endl;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int e = (c*60+d)-(a*60+b);
    cout<<e/60<<' '<<e%60;

    return 0;
}
