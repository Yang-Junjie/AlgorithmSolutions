#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
#define LOG(a) std::cout << "[" << #a << ":" << (a) << "]" << std::endl;
const int N = 100;
int cnt[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b, c;
    cin >> a >> b >> c;
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            for (int k = 1; k <= c; k++) {
                int sum =0;
                sum = i + j + k;
                cnt[sum]++;
            }
        }
    }
   // for (int i = 0; i <= a + b + c; i++) {
   //     cout << cnt[i] << ' ';
    //}
    cout << distance(cnt, max_element(cnt, cnt + a + b + c));

    return 0;
}
