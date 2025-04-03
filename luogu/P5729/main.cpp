#include <algorithm>
#include <cstring>
#include <iostream>
#include <istream>
#include <string>
using namespace std;
#define LOG(a) std::cout << "[" << #a << ":" << (a) << "]" << std::endl;
bool a[105][105][105];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int w, l, h;
    cin >> w >> l >> h;
    int q;
    cin >> q;
    int x1, y1, z1, x2, y2, z2, cnt1 = 0, cnt2 = 0;
    memset(a, true, sizeof(a));
    for (int i = 1; i <= q; i++) {
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        for (int x = min(x1, x2); x <= max(x1, x2); x++) {
            for (int y = min(y1, y2); y <= max(y1, y2); y++) {
                for (int z = min(z1, z2); z <= max(z1, z2); z++) {
                    if (a[x][y][z]) {
                        a[x][y][z] = false;
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int x = 1; x <= w; x++) {
        for (int y = 1; y <= l; y++) {
            for (int z = 1; z <= h; z++) {
                if (a[x][y][z]) {
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
