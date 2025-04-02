#include <algorithm>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
#define LOG(a) std::cout << "[" << #a << ":" << (a) << "]" << std::endl;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    cin>>n>>k;
    double a1=0,a2=0;
    int cnt1=0,cnt2=0;
    for(int i =1;i<=n;i++){
        if(i%k==0){
            a1+=i;
            cnt1++;
        }else{
            a2+=i;
            cnt2++;
        }
    }
    cout<<setprecision(1)<<fixed<<a1/cnt1<<' '<<a2/cnt2;
    return 0;
}
