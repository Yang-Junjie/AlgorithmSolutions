#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <numeric>
using namespace std;
#define LOG(a) std::cout << "[" << #a << ":" << (a) << "]" << std::endl;
using i64 = long long int;
using u64 = unsigned long long int;
using u32 = unsigned int;
using PII = pair<int, int>;

void zhuan90(vector<vector<int>>& v, int x, int y, int l) {
    int r_start = x - l / 2 - 1;  
    int c_start = y - l / 2 - 1; 
    vector<vector<int>> tmp = v;
 
    int i = r_start, j = r_start + l - 1;
    while (i < j) {
        for (int k = c_start; k < c_start + l; ++k) {
            swap(tmp[i][k], tmp[j][k]);
        }
        ++i;
        --j;
    }
    
    for (int n = r_start; n < r_start + l; ++n) {
        for (int m = c_start; m < c_start + l; ++m) {
            v[n][m] = tmp[m - c_start + r_start][n - r_start + c_start];
        }
    }
}

void zhuan90s(vector<vector<int>>& v, int x, int y, int l) {
    int r_start = x - l / 2 - 1;  
    int c_start = y - l / 2 - 1;  
    vector<vector<int>> tmp = v;
    for (int n = r_start; n < r_start + l; ++n) {
        for (int m = c_start; m < c_start + l; ++m) {
            tmp[n][m] = v[m - c_start + r_start][n - r_start + c_start];
        }
    }
   
    int i = r_start, j = r_start + l - 1;
    while (i < j) {
        for (int k = c_start; k < c_start + l; ++k) {
            swap(tmp[i][k], tmp[j][k]);
        }
        ++i;
        --j;
    }
    v = tmp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, t;
    cin >> n >> t;
    vector<vector<int>> a(n, vector<int>(n));
    int cnt = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = cnt;
            cnt++;
        }
    }

    while (t--) {
        int x, y, r, op;
        cin >> x >> y >> r >> op;
        int l = 2 * r + 1;
        if (op == 0) {
            zhuan90(a, x, y, l);
        } else {
            zhuan90s(a, x, y, l);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}