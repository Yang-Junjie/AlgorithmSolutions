#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
string a;
long long sum = 1;
int main()
{
    bool finded = false;
    cin >> a;
    for (int i = 0; i < a.size(); i++) {

        if (a[i] == '-') {
            sum -= 1;
        } else {
            sum *= 2;
        }
    }
    if (sum >= 2025) {
        finded = true;
    }
    if (!finded)
        cout << "NO";
    else
        cout<<"YES";
    return 0;
}
