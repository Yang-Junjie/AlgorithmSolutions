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

// 杞疆鐭╅樀
void zhuanT(vector<vector<char>>& v)
{
    vector<vector<char>> tmp = v;
    int n = v.size() - 1; // 鍘熺煩闃垫槸n x n鐨勶紝v鐨勫ぇ灏忔槸n+1
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            v[j][i] = tmp[i][j];
        }
    }
}

// 浜ゆ崲鍒梒1鍜宑2
void swapC(vector<vector<char>>& v, int c1, int c2)
{
    vector<vector<char>> tmp = v;
    int n = v.size() - 1; // 琛屾暟涓簄
    for (int i = 1; i <= n; i++) {
        v[i][c2] = tmp[i][c1];
        v[i][c1] = tmp[i][c2];
    }
}

// 浜ゆ崲琛宺1鍜宺2
void swapR(vector<vector<char>>& v, int r1, int r2)
{
    vector<vector<char>> tmp = v;
    int n = v[0].size() - 1; // 鍒楁暟涓簄
    for (int i = 1; i <= n; i++) {
        v[r2][i] = tmp[r1][i];
        v[r1][i] = tmp[r2][i];
    }
}

vector<vector<char>> zhuan90(const vector<vector<char>>& v)
{
    vector<vector<char>> tmp = v;
    int n = tmp.size() - 1; // 鍘熺煩闃电殑鍒楁暟n

    int i = 1, j = n;
    while (i < j) {
        swapR(tmp, i, j);
        i++;
        j--;
    }
    zhuanT(tmp);

    return tmp;
}
vector<vector<char>> reflect(const vector<vector<char>>& v)
{
    vector<vector<char>> tmp = v;
    int n = tmp.size() - 1; // 鍘熺煩闃电殑鍒楁暟n

    int i = 1, j = n;
    while (i < j) {
        swapC(tmp, i, j);
        i++;
        j--;
    }
    return tmp;
}
vector<vector<char>> zhuan180(const vector<vector<char>>& v)
{
    vector<vector<char>> tmp = v;
    tmp = zhuan90(zhuan90(tmp));

    return tmp;
}
vector<vector<char>> zhuan270(const vector<vector<char>>& v)
{
    vector<vector<char>> tmp = v;
    tmp = zhuan90(zhuan90(zhuan90(tmp)));

    return tmp;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<char>> s(n + 1, vector<char>(n + 1));
    vector<vector<char>> a(n + 1, vector<char>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> s[i][j];
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            //cout << a[i][j];
        }
        //cout << endl;
    }

    if (zhuan90(s) == a) {
        cout << 1 << endl;
    }
    else if (zhuan180(s) == a) {
        cout << 2 << endl;
    }
    else if (zhuan270(s) == a) {
        cout << 3 << endl;
    }
    else if (reflect(s) == a) {
        cout << 4 << endl;
    }
    else if (zhuan90(reflect(s)) == a || zhuan180(reflect(s)) == a || zhuan270(reflect(s)) == a) {
        cout << 5 << endl;
    }
    else if (s == a) {
        cout << 6 << endl;
    }
    else {
        cout << 7 << endl;
    }

    return 0;
}

