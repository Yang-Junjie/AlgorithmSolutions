#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
#define LOG(a) std::cout << "[" << #a << ":" << (a) << "]" << std::endl;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b;
    cin >> a >> b;
    int c = 1910 - (a + b - 1) / b;
    if (c >= 24 * 60)
        c -= 24 * 60;
    int h, m;
    h = c / 60;
    m = c % 60;
    if (m < 10) {
        if (h < 10) {
            cout << 0 << h << ":0" << m;
        } else {
            cout << h << ":0" << m;
        }
    } else {
        if (h < 10)
            cout << 0 << h << ":" << m;
        else
            cout << h << ":" << m;
    }
    return 0;
}
