#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
#define LOG(a) std::cout << "[" << #a << ":" << (a) << "]" << std::endl;
using i64 = long long int;
using u64 = unsigned long long int;
using u32 = unsigned int;
bool isPrime(int x){
    if(x<=1)return false;
    for(int i = 2;i<=x/i;i++){
        if(x%i==0)return false;
    }
    return true;
}
void solve()
{
    int n;
    cin >> n;
    if (n == 3) {
        cout << "3 2 1\n";
    } else if (n == 5) {
        cout << "1 5 2 3 4\n";
    } else if (n>10&&isPrime(n)) {
        cout << 1 << ' ' << n<<' ';
        for (int i = 2; i <= n - 1; i++) {
            cout << i << ' ';
        }
        cout << endl;
    }
    else{
        cout<<-1<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
