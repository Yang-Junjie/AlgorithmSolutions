#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
#define LOG(a) std::cout << "[" << #a << ":" << (a) << "]" << std::endl;
int a[3];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i = 0;i<3;i++)cin>>a[i];
    sort(a,a+3);
    for(int i= 0;i<3;i++)cout<<a[i]<<" ";
    

    return 0;
}
