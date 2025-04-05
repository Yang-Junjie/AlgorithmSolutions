#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
#define LOG(a) std::cout << "[" << #a << ":" << (a) << "]" << std::endl;
int a[10];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin>>n>>m;
    for (int i = n; i <= m; i++) {
        string tmp = to_string(i);
        for (auto num : tmp) {
            a[num - '0']++;
        }
    }
    for (int i = 0; i < 10; i++) {
        cout << a[i] << ' ';
    }

    return 0;
}
