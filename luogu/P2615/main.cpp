#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
#define LOG(a) std::cout << "[" << #a << ":" << (a) << "]" << std::endl;
int a[40][40];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int r = 1, c = n / 2 + 1;
    a[r][c] = 1;
    for (int i = 2; i <= n * n; i++) {
        if (r == 1 && c != n) {
            r = n;
            c = c + 1;
        }
        else if (c == n && r != 1) {
            r = r - 1;
            c = 1;
        }
        else if (r == 1 && c == n) {
            r = r + 1;
        }
        else {
            if (a[r - 1][c + 1] == 0) { // 右上方未被填
                r = r - 1;
                c = c + 1;
            } else { // 右上方已填，填正下方
                r = r + 1;
            }
        }
        a[r][c] = i;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}

