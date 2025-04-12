#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int N = 1e3;
vector<int> a(N, 0); // 存储当前阶乘
vector<int> b(N, 0); // 存储总和
int r; // 乘法系数

void mul()
{
    int g = 0;
    for (int i = 0; i < N; i++) {
        int tmp = a[i] * r + g;
        a[i] = tmp % 10;
        g = tmp / 10;
    }
}

void add()
{
    int g = 0;
    for (int i = 0; i < N; i++) {
        int tmp = b[i] + a[i] + g;
        b[i] = tmp % 10;
        g = tmp / 10;
    }
}

void output()
{
    bool flag = true;
    for (int i = N - 1; i >= 0; i--) {
        if (b[i] != 0)
            flag = false;
        if (!flag)
            cout << b[i];
    }
    if (flag)
        cout << 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    a[0] = 1;
    b[0] = 1;

    for (int k = 2; k <= n; k++) {
        r = k;
        mul();
        add();
    }

    output();
    return 0;
}
