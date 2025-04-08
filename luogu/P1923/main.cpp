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
    int n, k;
    cin >> n >> k;
    vector<int> a(n, 0);
    for (auto& i : a) {
        cin >> i;
    }
    sort(a.begin(), a.end());
    cout << a[k]<< endl;
    return 0;
}
