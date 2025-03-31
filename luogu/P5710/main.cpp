#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
#define LOG(a) std::cout << "[" << #a << ":" << (a) << "]" << std::endl;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x;
    cin >> x;
    bool xin1 = x % 2 == 0;
    bool xin2 = (4 < x) && (x <= 12);
    cout << (xin1 && xin2) << ' ';
    cout << (xin1 || xin2) << ' ';
    cout << (xin1 ^ xin2) << ' ';
    cout << !(xin1 || xin2);

    return 0;
}
