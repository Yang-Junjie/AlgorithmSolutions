#include <algorithm>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;
#define LOG(a) std::cout << "[" << #a << ":" << (a) << "]" << std::endl;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    double the_sroce_max = 0;
    while (n--) {
        vector<int> a(m);
        for (int i = 0; i < m; i++) {
            cin >> a[i];
        }
        auto the_max = max_element(a.begin(), a.end());
        auto the_min = min_element(a.begin(), a.end());
        a.erase(the_max);
        a.erase(the_min);
        double mean = (double)(accumulate(a.begin(), a.end(), 0)) / (m - 2);
        the_sroce_max = max(mean, the_sroce_max);
    }
    cout << setprecision(2) << fixed << the_sroce_max << endl;

    return 0;
}
