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
    vector<int> a(n);
    for(auto&i:a){
        cin>>i;
    }
    sort(a.begin(),a.end());
    int cnt = 0,sum=0;
    for(int j = a.size()-1;j>=0;j--){
        if(sum<m){
            sum+=a[j];
            cnt++;
        }
        else{
            break;
        }
    }
    cout<<cnt<<endl;



    return 0;
}
