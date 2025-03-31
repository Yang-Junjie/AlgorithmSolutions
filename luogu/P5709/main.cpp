#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
#define LOG(a) std::cout << "[" << #a << ":" << (a) << "]" << std::endl;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,t,s;
    cin>>n>>t>>s;
    if(t ==0){
        cout<<0;
        return 0;
    }
    int ans = n-(t+s-1)/t;
    if(ans<0 ){
        cout<<0;
    }
    else {
    cout<<ans;
    }
    return 0;
}
