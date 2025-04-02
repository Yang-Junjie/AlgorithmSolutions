#include <algorithm>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
#define LOG(a) std::cout << "[" << #a << ":" << (a) << "]" << std::endl;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    double dp[50];    
    int n;
    cin>>n;
    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    cout<<setprecision(2)<<fixed<<dp[n];

    return 0;
}
