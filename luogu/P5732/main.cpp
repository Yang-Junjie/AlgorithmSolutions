#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
#define LOG(a) std::cout << "[" << #a << ":" << (a) << "]" << std::endl;
int dp[250][250];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    dp[1][1] = 1;
    cout<<dp[1][1]<<endl;;
    for(int i = 2;i<=n;i++){
        for(int j = 1;j<=i;j++){
            dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
            cout<<dp[i][j]<<' ';
        }
        cout<<endl;
    }
    

    return 0;
}
