#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<string> rows(n);
    for (int i = 0; i < n; ++i) {
        cin >> rows[i];
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < 4; ++j) {
            if (rows[i][j] == '#') {
                cout << j + 1 << ' '; // 
                break;
            }
        }
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

