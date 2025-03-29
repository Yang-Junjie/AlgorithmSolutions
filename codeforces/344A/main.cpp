#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int n;
string a;
int cnt = 0;
int main()
{
    cin >> n;
    while (n--) {
        string tmp;
        cin >> tmp;
        if (cnt == 0) {
            cnt++;
            a = tmp;
            continue;
        } else {
            if (a != tmp) {
                cnt++;
                a = tmp;
            }
        }
    }
    cout<<cnt;
    return 0;
}
