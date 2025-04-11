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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int ans = 0;
    int tmp;
    while(cin>>tmp)ans+=tmp;
    cout<<ans<<endl;
    

    return 0;
}
