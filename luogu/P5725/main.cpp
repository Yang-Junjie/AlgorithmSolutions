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
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= n; j++) {
            cnt++;
            if (cnt < 10)
                cout << 0 << cnt;
            else
                cout << cnt;
        }
        cout << '\n';
    }
    cout<<endl;
    int cnt2 = 0;
    for (int i = n; i >= 1; i--) {
        for (int k = i-1; k >= 1; k--)
            cout << "  ";
        for (int j = i; j <= n; j++) {
            cnt2++;
            if (cnt2 < 10)
                cout << 0 << cnt2;
            else
                cout << cnt2;
        }
        cout << '\n';
    }
    return 0;
}
