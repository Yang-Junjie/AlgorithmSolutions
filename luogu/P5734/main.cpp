#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
#define LOG(a) std::cout << "[" << #a << ":" << (a) << "]" << std::endl;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    string s, s1;
    cin >> t;
    cin >> s;

    while (t--) {
        int q;
        cin >> q;
        if (q == 1) {
            cin >> s1;
            s.append(s1);
            cout << s << endl;
        } else if (q == 2) {
            int l, r;
            cin >> l >> r;
            s1 = s.substr(l, r);
            s = s1;
            cout << s << endl;
        } else if (q == 3) {
            int l;
            cin >> l;
            cin >> s1;
            s.insert(l, s1);
            cout << s << endl;
        } else {
            cin >> s1;
            if (s.find(s1) < s.size()) {
                cout << (int)s.find(s1) << endl;
            } else {
                cout << -1 << endl;
            }
        }
    }

    return 0;
}
