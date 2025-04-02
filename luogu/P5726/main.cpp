#include <algorithm>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
#define LOG(a) std::cout << "[" << #a << ":" << (a) << "]" << std::endl;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin>>n;
    int the_max =-1,the_min=20;
    double ans = 0;
    for(int i = 1;i<=n;i++)
    {
        int a;
        cin>>a;
        if(a>the_max)the_max = a;
        if(a<the_min)the_min = a;
        ans+=a;
    }
    cout<<setprecision(2)<<fixed<<(ans-the_max-the_min)/(n-2);
    return 0;
}
