#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
#define LOG(a) std::cout << "[" << #a << ":" << (a) << "]" << std::endl;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q[] = { 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4 };
    string a;
    getline(cin, a);
    int ans = 0;
    for (auto ch : a) {
        if (ch == ' ')
            ans++;
        else
            ans += q[ch - 'a'];
    }
    cout << ans << endl;

    return 0;
}
