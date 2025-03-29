#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
string a;
int main()
{
    cin >> a;
    reverse(a.begin(),a.end());
    cout << a;
    return 0;
}
