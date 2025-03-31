#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
#define LOG(a) std::cout << "[" << #a << ":" << (a) << "]" << std::endl;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    unsigned long long int n;
    cin>>n;
    unsigned long long int ans = n*(n-1)/2*(n-2)/3*(n-3)/24;
    cout<<ans;
    

    return 0;
}
