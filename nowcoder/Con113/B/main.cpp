#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
const int N = 1e5;
int n;
bool isok = true;
int cnt = 0;
string a;
int main()
{
    cin >> n;
    cin>>a;
    for(int i =0;i<a.size()-1;i++){
        if(a[i]==a[i+1]){
            cnt++;
            if(cnt>=2)
                break;
        }
    }
    if (cnt>=2) {
        cout << "NO";
    } else
        cout << "YES";
    return 0;
}
