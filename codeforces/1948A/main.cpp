#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <numeric>
using namespace std;
#define LOG(a) std::cout << "[" << #a << ":" << (a) << "]" << std::endl;
using i64 = long long int;
using u64 = unsigned long long int;
using u32 = unsigned int;
using PII = pair<int,int>;

void solve(){
int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << "YES" << endl;
        for (int i = n / 2; i >= 1; i--) {
            cout << "AAB";
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
