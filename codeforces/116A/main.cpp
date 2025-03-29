#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int now = 0,n,the_max = -1;
int main(){
    cin>>n;
    while(n--){
        int a,b;
        cin>>a>>b;
        now-=a;
        now+=b;
        if(the_max<now){
            the_max = now;
        }
    }
    cout<<the_max;
    return 0;
}
