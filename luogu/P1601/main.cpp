#include <algorithm>
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
const int N = 540;
int a[N], b[N];
inline void add(int a[], int b[])
{
    int t = 0;
    for (int i = 0; i <= N; i++) {
        a[i] += b[i] + t;
        t = a[i] / 10;
        a[i] %= 10;
    }
}
inline void output()
{
    int flag = 0;
    for (int i = N - 1; i >= 0; i--) {
        if (a[i] != 0)
            flag = 1;
        if (flag) {
            cout << a[i];
        }
    }
    if (!flag)
        cout << 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s1, s2;
    cin >> s1 >> s2;
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    for (int i = s1.size() - 1; i >= 0; i--)
        a[i] = s1[i] - '0';
    for (int i = s2.size() - 1; i >= 0; i--)
        b[i] = s2[i] - '0';
    add(a, b);
    output();
    return 0;
}
