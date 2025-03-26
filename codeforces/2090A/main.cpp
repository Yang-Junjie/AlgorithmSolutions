#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long x, y, a;
        cin >> x >> y >> a;
        long long total_round = x + y;
        long long k = a / total_round;
        long long sum_k = k * total_round;
        
        // 检查B的回合是否能超过a.5
        if (2 * (sum_k + x) > 2 * a + 1) {
            cout << "NO\n";
        } 
        // 否则检查K的回合是否能超过
        else if (2 * (sum_k + x + y) > 2 * a + 1) {
            cout << "YES\n";
        } 
        // 理论上不会执行到这一步，但为了保险处理
        else {
            cout << "YES\n";
        }
    }
    return 0;
}

