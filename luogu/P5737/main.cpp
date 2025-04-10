#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define LOG(a) std::cout << "[" << #a << ":" << (a) << "]" << std::endl;
bool isYear(int a)
{
    if (a % 4 == 0 && a % 100 != 0 || a % 400 == 0) {
        return true;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x, y;
    cin >> x >> y;
    int cnt = 0;
    vector<int> a;
    for (int i = x; i <= y; i++) {
        if (isYear(i)) {
            cnt++;
            a.push_back(i);
        }
    }
    cout << cnt << endl;
    for (auto i : a) {
        cout << i << ' ';
    }
    cout << endl;
    return 0;
}
