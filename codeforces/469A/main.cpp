#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <utility>
#include <vector>
using namespace std;
#define LOG(a) std::cout << "[" << #a << ":" << (a) << "]" << std::endl;
using i64 = long long int;
using u64 = unsigned long long int;
using u32 = unsigned int;
using PII = pair<int, int>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    vector<int> a(t);
    int x, y;
    cin >> x;
    for (int i = 0; i < x; i++) {
        int tmp;
        cin >> tmp;
        a[tmp - 1]++;
    }
    cin >> y;
    for (int i = 0; i < y; i++) {
        int tmp;
        cin >> tmp;
        a[tmp - 1]++;
    }
    bool find_zero = false;
    for(auto i:a){
        if(i==0){
            find_zero = true;
        }
    }
    if(!find_zero){
        cout<<"I become the guy."<<endl;
    }
    else{
        cout<<"Oh, my keyboard!"<<endl;
    }
    return 0;
}
