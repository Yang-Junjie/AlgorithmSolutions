#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
#define LOG(a) std::cout << "[" << #a << ":" << (a) << "]" << std::endl;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,ans = 1;
    cin>>n;
    for(int i = 1;i<n;i++){
        ans +=1;
        ans*=2;
    }
    
    cout<<ans;

    return 0;
}
