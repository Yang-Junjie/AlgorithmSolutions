#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
#define LOG(a) std::cout << "[" << #a << ":" << (a) << "]" << std::endl;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    if((5*n)<(3*n+10)){
        cout<<"Local";
    }
    else{
        cout<<"Luogu";
    }
    

    return 0;
}
