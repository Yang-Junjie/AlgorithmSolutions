#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
#define LOG(a) std::cout << "[" << #a << ":" << (a) << "]" << std::endl;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    double n, k = 1;
    cin >> n;
    while (1) {
        for (int x = 100; x >= 1; x--) {
            if (52 * 7 * x + 1092 * k == n) {
                cout << x << '\n';
                cout << k;
                return 0;
            }
        }
        k++;
    }
    return 0;
}
