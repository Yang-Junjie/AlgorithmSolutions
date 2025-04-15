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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int i = 0;
    int a = 0, b = 0, c = 0;
    while (i < s.size()) {
        if (s[i] == 'a') {
            if (s[i + 3] == 'a') {
                a = a;
            } else if (s[i + 3] == 'b') {
                a = b;
            } else if (s[i + 3] == 'c') {
                a = c;
            } else {
                a = s[i + 3] - '0';
            }
        } else if (s[i] == 'b') {
            if (s[i + 3] == 'a') {
                b = a;
            } else if (s[i + 3] == 'b') {
                b = b;
            } else if (s[i + 3] == 'c') {
                b = c;
            } else {
                b = s[i + 3] - '0';
            }
        } else if (s[i] == 'c') {
            if (s[i + 3] == 'a') {
                c = a;
            } else if (s[i + 3] == 'b') {
                c = b;
            } else if (s[i + 3] == 'c') {
                c = c;
            } else {
                c = s[i + 3] - '0';
            }
        }
        i+=5;
    }

    cout << a << ' ' << b << ' ' << c << endl;
    return 0;
}
