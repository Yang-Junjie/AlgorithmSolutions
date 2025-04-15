#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <numeric>
#include <cmath>
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
    i64 sum = 0;
    int cnt=  0;
    vector<int> a;
    while(cin>>n)
    {
        a.push_back(n);
        cnt++;
    }
    for(auto i:a){
        sum+=i* pow(2,cnt-1);
    }
    cout<<sum<<endl;

    return 0;
}
