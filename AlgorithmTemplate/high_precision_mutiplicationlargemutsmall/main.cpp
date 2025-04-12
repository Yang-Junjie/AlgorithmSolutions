#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int N = 1e3;

vector<int> high_precision_multiplication(vector<int> a, int b)
{
    vector<int> c(N, 0);
    int g = 0;
    for (int i = 0; i < N; i++) {
        c[i] = a[i] * b + g;
        g = c[i] / 10;
        c[i] %= 10;
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
    string s1;
    int b;
    cin >> s1 >> b;
    reverse(s1.begin(), s1.end());
    vector<int> a(N, 0);
    vector<int> c;
    for (int i = s1.size() - 1; i >= 0; i--) {
        a[i] = s1[i] - '0';
    }

    c = high_precision_multiplication(a, b);
    output(c);
    return 0;
}

