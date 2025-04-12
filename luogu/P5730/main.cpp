#include <algorithm>
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
char c[10][5][3] = // W[i][j][k]表示第i个数字的第j行的第k列
    {
        {
            // 0
            'X',
            'X',
            'X',
            'X',
            '.',
            'X',
            'X',
            '.',
            'X',
            'X',
            '.',
            'X',
            'X',
            'X',
            'X',
        },
        {
            // 1
            '.',
            '.',
            'X',
            '.',
            '.',
            'X',
            '.',
            '.',
            'X',
            '.',
            '.',
            'X',
            '.',
            '.',
            'X',
        },
        {
            // 2
            'X',
            'X',
            'X',
            '.',
            '.',
            'X',
            'X',
            'X',
            'X',
            'X',
            '.',
            '.',
            'X',
            'X',
            'X',
        },
        {
            // 3
            'X',
            'X',
            'X',
            '.',
            '.',
            'X',
            'X',
            'X',
            'X',
            '.',
            '.',
            'X',
            'X',
            'X',
            'X',
        },
        {
            // 4
            'X',
            '.',
            'X',
            'X',
            '.',
            'X',
            'X',
            'X',
            'X',
            '.',
            '.',
            'X',
            '.',
            '.',
            'X',
        },
        {
            // 5
            'X',
            'X',
            'X',
            'X',
            '.',
            '.',
            'X',
            'X',
            'X',
            '.',
            '.',
            'X',
            'X',
            'X',
            'X',
        },
        {
            // 6
            'X',
            'X',
            'X',
            'X',
            '.',
            '.',
            'X',
            'X',
            'X',
            'X',
            '.',
            'X',
            'X',
            'X',
            'X',
        },
        {
            // 7
            'X',
            'X',
            'X',
            '.',
            '.',
            'X',
            '.',
            '.',
            'X',
            '.',
            '.',
            'X',
            '.',
            '.',
            'X',
        },
        {
            // 8
            'X',
            'X',
            'X',
            'X',
            '.',
            'X',
            'X',
            'X',
            'X',
            'X',
            '.',
            'X',
            'X',
            'X',
            'X',
        },
        {
            // 9
            'X',
            'X',
            'X',
            'X',
            '.',
            'X',
            'X',
            'X',
            'X',
            '.',
            '.',
            'X',
            'X',
            'X',
            'X',
        }
    };
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    string s;
    cin >> n >> s;

    for (int i = 0; i <= 4; i++) {
        for (int k = 0; k < n; k++) {
            for (int j = 0; j <= 2; j++) {
                cout << c[s[k] - '0'][i][j];
            }
            if (k != n - 1)
                cout << '.';
        }
        cout << endl;
    }

    return 0;
}
