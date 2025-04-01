#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
#define LOG(a) std::cout << "[" << #a << ":" << (a) << "]" << std::endl;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    if(n%4==0&&n%100!=0||n%400==0){
        cout<<1;
    }
    else {
        cout<<0;
    }
    return 0;
}
