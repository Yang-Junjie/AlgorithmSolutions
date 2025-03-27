#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int n;
int main(){
    cin>>n;
    bool isHard = false;
    while(n--){
        int a;
        cin>>a;
        if(a==1){
            cout<<"HARD";
            isHard = true;
            break;
        }
    }
    if(!isHard){
        cout<<"EASY";
    }
    return 0;
}
