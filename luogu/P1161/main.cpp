#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
#define LOG(a) std::cout << "[" << #a << ":" << (a) << "]" << std::endl;
const int N = 2e6 + 10;
bool q[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        double a, t;
        cin >> a >> t;
        for (int i = 1; i <= t; i++) {
            int ai = (int)(a * i);
            if (!q[ai]) {
                q[ai] = true;
            } else {
                q[ai] = false;
            }
        }
    }
    for (int i = 0; i <= N; i++) {
        if (q[i]) {
            cout << i;
            break;
        }
    }

    return 0;
}
