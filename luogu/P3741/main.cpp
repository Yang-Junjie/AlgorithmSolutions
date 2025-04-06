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
    char ch[110];
    for (int i = 1; i <= n; i++) {
        cin >> ch[i];
    }
    int ans = 0;
    for (int i = 1; i <= n - 1; i++) {
        if (ch[i] == 'V' && ch[i + 1] == 'K') {
            ans++;
            ch[i] = 'p';
            ch[i + 1] = 'p';
        }
    }
    for (int i = 1; i <= n - 1; i++) {
        if ((ch[i] == 'V' && ch[i + 1] == 'V') || (ch[i] == 'K' && ch[i + 1] == 'K')) {
            ans++;
            ch[i] = 'p';
            ch[i + 1] = 'p';
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
