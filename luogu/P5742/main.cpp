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
    while(n--){
        int a1,a2,id;
        cin>>id>>a1>>a2;
        if(a1+a2>140&&a1*7+a2*3>=800){
            cout<<"Excellent"<<endl;
        }
        else{
            cout<<"Not excellent"<<endl;
        }
    }
    

    return 0;
}
