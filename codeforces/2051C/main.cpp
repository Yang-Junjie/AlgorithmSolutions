#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a_list(m);
    for (int i = 0; i < m; ++i) {
        int tmp;
        cin >> tmp;
        a_list[i] = tmp - 1; // 转换为0-based索引
    }
    vector<bool> q(n, false);
    for (int i = 0; i < k; ++i) {
        int tmp;
        cin >> tmp;
        q[tmp - 1] = true;
    }
    // 收集所有不在quandui中的位置
    vector<int> S;
    for (int i = 0; i < n; ++i) {
        if (!q[i]) {
            S.push_back(i);
        }
    }
    if (S.empty()) {
        cout << string(m, '1') << '\n';
    } else {
        bool allSame = true;
        int first = S[0];
        for (size_t i = 1; i < S.size(); ++i) {
            if (S[i] != first) {
                allSame = false;
                break;
            }
        }
        if (!allSame) {
            cout << string(m, '0') << '\n';
        } else {
            for (int pos : a_list) {
                cout << (pos == first ? '1' : '0');
            }
            cout << '\n';
        }
    }
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

