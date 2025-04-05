#include <algorithm>
#include <iostream>
#include <limits>
#include <numeric>
#include <string>
using namespace std;
#define LOG(a) std::cout << "[" << #a << ":" << (a) << "]" << std::endl;
const int N = 3e3 + 10;
int a[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int the_min = numeric_limits<int>::max();
    for (int i = 1; i <= n - m+1; i++) {
        int sum = 0;
        for (int j = 0; j < m; j++) {
            sum += a[i + j];
        }
        the_min = min(the_min, sum);
    }
    cout << the_min;

    return 0;
}
