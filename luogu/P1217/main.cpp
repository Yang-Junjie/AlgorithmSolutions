#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define LOG(a) std::cout << "[" << #a << ":" << (a) << "]" << std::endl;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<int> a(m);
    for(auto& i:a){
        cin>>i;
    }
    sort(a.begin(),a.end());
    for(auto i:a){
        cout<<i<<' ';
    }
    cout<<endl;

    return 0;
}
