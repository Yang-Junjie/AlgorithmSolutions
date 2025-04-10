#include <algorithm>
#include <cstring>
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>
using namespace std;
#define LOG(a) std::cout << "[" << #a << ":" << (a) << "]" << std::endl;
using i64 = long long int;
using u64 = unsigned long long int;
using u32 = unsigned int;
using PII = pair<int, int>;
int a[1024][1024];
void solve(int n, int r, int c)
{
    if (n == 0) {
        a[r][c] = 1;
    } else {
        solve(n - 1, r, c + (1 << (n - 1)));
        solve(n - 1, r + (1 << (n - 1)), c + (1 << (n - 1)));
        solve(n - 1, r + (1 << (n - 1)), c);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    memset(a, 0, sizeof(a));
    solve(n, 0, 0);
    for (int i = 0; i < (1 << (n)); i++) {
        for (int j = 0; j < (1 << n); j++) {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
