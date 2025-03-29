#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string s;
int n,x;
int main(){
    cin>>n>>x;
    cin>>s;
    while(x--){
        for(int i = 0;i<s.size()-1;i++){
            if(s[i]=='B'&&s[i+1]=='G'){
                swap(s[i],s[i+1]);
                i++;
            }
        }
    }
    cout<<s;
    return 0;
}
