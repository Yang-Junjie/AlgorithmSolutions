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
    cin >> n;
    int the_max = -1;
    if (n<= 1)
        cout<<1;
    for (int i = 2; i <= n / i; i++) {
        if (n % i == 0)
            cout<<n/i;
    }
    return 0;
}
