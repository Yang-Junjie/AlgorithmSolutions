#include <algorithm>
#include <initializer_list>
#include <iostream>
#include <string>
using namespace std;
string s1, s2;
int t, n;
void solve()
{
    int cnt_even_0 = 0, cnt_even_1 = 0, cnt_odd_0 = 0, cnt_odd_1 = 0;
    cin >> n;
    cin >> s1;
    cin >> s2;
    s1 = '1' + s1 + '1';
    s2 = '1' + s2 + '1';
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            if (s1[i] == '1')
                cnt_odd_1++;
            if (s2[i] == '0')
                cnt_even_0++;
        } else {
            if (s1[i] == '1')
                cnt_even_1++;
            if (s2[i] == '0')
                cnt_odd_0++;
        }
    }
    if (cnt_odd_1 <= cnt_odd_0 && cnt_even_1 <= cnt_even_0) {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
}
int main()
{
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
