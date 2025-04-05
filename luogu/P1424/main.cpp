#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
#define LOG(a) std::cout << "[" << #a << ":" << (a) << "]" << std::endl;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    unsigned long long n,ans=0; 
    int x;
    cin >> x >> n; 
    for(int i=0;i<n;i++)
    {
        if((x!=6)&&(x!=7)) 
            ans += 250;
        if(x==7)
        x=1; 
        else
            x++; 
    }
    cout << ans; 

    return 0;
}
