#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <string>
#include <utility>
#include <vector>
using namespace std;
#define LOG(a) std::cout << "[" << #a << ":" << (a) << "]" << std::endl;
using i64 = long long int;
using u64 = unsigned long long int;
using u32 = unsigned int;
using PII = pair<int, int>;
const int N = 210;
int ans[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    char a, b = '0';
    int cnt = 0, cnt0 = 0, cnt1 = 0;
    bool is_first = true;
    int zz = 0;
    while (cin >> a) {
        cnt++;
        if (a == b) {
            ans[zz]++;
        } else {
            ans[++zz]++;
            b = a;
        }
    }
    cout << sqrt(cnt) << ' ';
    for (int i = 0; i <= zz; i++) {
        cout << ans[i] << ' ';
    }
    return 0;
}
