#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
#define LOG(a) std::cout << "[" << #a << ":" << (a) << "]" << std::endl;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a[5];
    for (int i = 1; i <= 4; i++)
        cin >> a[i];
    int ans = 0;
    sort(a, a +5);
    for (int i = 1; i <= 4; i++) {
        if (a[i] == a[i - 1]) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}
