#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
#define LOG(a) std::cout << "[" << #a << ":" << (a) << "]" << std::endl;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    double s = 2.0;
    double n ,dis=0.0;
    cin>>n;
    int cnt = 0;
    while(dis<n){
        cnt++;
        dis+=s;
        s*=0.98;
    }
    cout<<cnt;
    return 0;
}
