#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define LOG(a) std::cout << "[" << #a << ":" << (a) << "]" << std::endl;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n, 0);
    cin >> a[0];
    for (int i = 1; i <= n - 2; i++) {
        int tmp;
        cin >> tmp;
        if (tmp == a[i-1]) {
            a[i-1] = a[i-2];
        } else {
            a[i] = tmp;
        }
    }
    cin >> a[n - 1];
    int ans = 0;
    for (int i = 2; i <= n - 2; i++) {
        if (a[i] < a[i - 1] && a[i] < a[i + 1]) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
