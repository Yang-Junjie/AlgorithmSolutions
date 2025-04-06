#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
#define LOG(a) std::cout << "[" << #a << ":" << (a) << "]" << std::endl;

int a[30];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    char s[110];
    for (int i = 1; i <= n; i++) {
        char tmp;
        cin >> tmp;
        int index = tmp - 'a';
        if (index < 0) {
            a[index + 32]++;
        } else {
            a[index]++;
        }
    }
    bool is_find = false;
    for (int i = 0; i <= 25; i++) {
        if (a[i] == 0) {
            is_find = true;
            break;
        }
    }
    if (!is_find) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
