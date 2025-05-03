#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int N = 1e3;

vector<int> high_precision_addition(vector<int> a, vector<int> b)
{
    vector<int> c(N, 0);
    int g = 0; // 储存进位
    for (int i = 0; i < N; i++) {
        c[i] = a[i] + b[i] + g; // 不管三七二十一直接将这一位上的数相加，包括进位，后面再来处理进位。
        // 处理进位
        g = c[i] / 10; // 得到下一位的进位
        c[i] %= 10; // 只保留当前位上的个位
    }
    return c;
}

void output(vector<int> a)
{
    bool flag = false;
    for (int i = N - 1; i >= 0; i--) {
        if (a[i] != 0)
            flag = true;
        if (flag)
            cout << a[i];
    }
    if (!flag)
        cout << 0;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    vector<int> a(N, 0);
    vector<int> b(N, 0);
    vector<int> c;
    for (int i = s1.size() - 1; i >= 0; i--) {
        a[i] = s1[i] - '0';
    }

    for (int i = s2.size() - 1; i >= 0; i--) {
        b[i] = s2[i] - '0';
    }
    c = high_precision_addition(a, b);
    output(c);
    return 0;
}
