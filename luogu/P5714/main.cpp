#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
#define LOG(a) std::cout << "[" << #a << ":" << (a) << "]" << std::endl;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    double m,h;
    cin>>m>>h;
    double ibm = m/h/h;
    if(ibm<18.5){
        cout<<"Underweight";
    }
    else if(ibm < 24){
        cout<<"Normal";
    }
    else{
        cout<<ibm<<endl;
        cout<<"Overweight";
    }
    return 0;
}
