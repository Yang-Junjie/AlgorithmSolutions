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
    for(int i = 0;i<n;i++){
        cin>>a[i];
    }
    int cnt = 0,the_max = 0;
    for(int i = 0;i<n-1;i++){
        if(a[i]<a[i+1]){
            cnt++;
            the_max=max(cnt,the_max);
        }
        else{
            cnt = 0;
        }
    }
    cout<<the_max+1<<endl;
    

    return 0;
}
