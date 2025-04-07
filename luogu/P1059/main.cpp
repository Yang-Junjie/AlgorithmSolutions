#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define LOG(a) std::cout << "[" << #a << ":" << (a) << "]" << std::endl;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto& i :a){
        cin>>i;
    }
    sort(a.begin(),a.end());
    auto last = unique(a.begin(),a.end());
    a.erase(last,a.end());
    cout<<a.size()<<endl;
    for(auto i :a){
        cout<<i<<' ';
    }
    cout<<endl;
    

    return 0;
}
