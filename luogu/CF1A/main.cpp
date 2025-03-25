#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int n,m,a,ans;
    cin>>n>>m>>a;
    ans=(n/a)*(m/a);
    if(m%a!=0)
        ans+=n/a;
    if(n%a!=0)
        ans+=m/a;
    if(n%a!=0&&m%a!=0)
        ans++;
    cout<<ans;
    return 0;
}
