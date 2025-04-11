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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int a;
    cin >> a;
    cout << min(5, a - 1 + 2) << ' ';
    for (int i = 2; i <= n; i++) {
        int tmp;
        cin >> tmp;
        cout << min(5, tmp - 1) << ' ';
    }
    cout << endl;

    return 0;
}
