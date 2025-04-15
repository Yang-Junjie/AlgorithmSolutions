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
        string name;
        int age;
        int sroce;
        cin>>name>>age>>sroce;
        cout<<name<<' '<<age+1<<' '<<(sroce*1.2>600?600:sroce*1.2)<<endl;
    }
    

    return 0;
}
