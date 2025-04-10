#include <algorithm>
#include <cmath>
#include <iomanip>
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
double f(double n, double x)
{
    if (n == 1)
        return sqrt(x + 1);
    return sqrt(n + f(n - 1, x));
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    double n, x;
    cin >> n >> x;
    cout << setprecision(2) << fixed << f(n, x) << endl;
    return 0;
}
