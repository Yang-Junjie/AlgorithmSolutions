#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
#define LOG(a) std::cout << "[" << #a << ":" << (a) << "]" << std::endl;
using i64 = long long int;
using u64 = unsigned long long int;
using u32 = unsigned int;

void solve(){


}
int a[105];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i =1;i<=n;i++){
        int b;
        cin>>b;
        a[b] = i; 
    }
    for(int i = 1;i<=n;i++){
        cout<<a[i]<<' ';
    }


    return 0;
}
