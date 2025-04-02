#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
#define LOG(a) std::cout << "[" << #a << ":" << (a) << "]" << std::endl;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int cnt = 1;
    int n;
    cin >> n;
    while (n > 1)
    {
        n/=2;
    
        cnt++;
    }
    cout<<cnt;
        return 0;
}
