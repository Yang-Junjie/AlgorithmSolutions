#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
#define LOG(a) std::cout << "[" << #a << ":" << (a) << "]" << std::endl;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    double h,r;
    cin>>h>>r;
    h*=0.1;
    r*=0.1;
    cout<<ceil(20/3.14/h/r/r);

    

    return 0;
}
