#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
#define LOG(a) std::cout << "[" << #a << ":" << (a) << "]" << std::endl;
int a[105];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    cout<<*max_element(a+1,a+n+1)-*min_element(a+1,a+n+1);
    return 0;
}
