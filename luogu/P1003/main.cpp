#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
#define LOG(a) std::cout << "[" << #a << ":" << (a) << "]" << std::endl;
const int N = 1e4 + 10;
int a[N], b[N], x2[N], y2[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i] >> x2[i] >> y2[i];
    int x, y;
    cin >> x >> y;
    int ans = -1;
    for (int i = 1; i <= n; i++) {
        if (x >= a[i] && y >= b[i] && x <= x2[i]+a[i] && y <= y2[i]+b[i]) {
            ans = i;
        }
    }
    cout << ans;

    return 0;
}
