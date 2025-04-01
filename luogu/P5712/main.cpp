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
    cout<<"Today, I ate ";
    if(n<=1)cout<<n<<" apple.";
    else
     cout<<n<<" apples.";
    return 0;
}
