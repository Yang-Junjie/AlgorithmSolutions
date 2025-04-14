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
    int n;
    cin>>n;
    vector<int> a(n);
    int sum = 0;
    for(int i = 0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    sort(a.begin(),a.end(),[](int a,int b){
        return a>b;
    }); 
    
    int mysum = 0;
    int cnt = 0;
    while(mysum<=sum-mysum){
        mysum+=a[cnt];
        cnt++;
    }
    cout<<cnt<<endl;

    

    return 0;
}
