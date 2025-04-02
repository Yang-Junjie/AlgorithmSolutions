#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
#define LOG(a) std::cout << "[" << #a << ":" << (a) << "]" << std::endl;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    double money = 0;
    cin >> n;
    if(n<=150){
    money = n*0.4463;
    }else if(n>=151&&n<=400){
        money += 150*0.4463;
        money += (n-150)*0.4663;
    }else{
        money += 150*0.4463;
        money += (400-150)*0.4663;
        money += (n-400)*0.5663;
    }
    cout << setprecision(1) << fixed << money;

    return 0;
}
