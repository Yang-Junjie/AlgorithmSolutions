#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
#define LOG(a) std::cout << "[" << #a << ":" << (a) << "]" << std::endl;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string a, b;
    cin >> a >> b;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i])
            cout << 1;
        else
            cout << 0;
    }

    return 0;
}
