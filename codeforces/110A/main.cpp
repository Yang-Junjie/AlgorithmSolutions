#include <iostream>
#include <string>
using namespace std;
string s;
int ans; 
int main()
{
    cin >>s;
    for (int i = 0; i < s.size(); i++) 
    { 
        if (s[i] == '4' || s[i] == '7')
            ans++;
    }
    if (ans == 4 || ans == 7)
        cout << "YES"; 
    else
        cout << "NO";

    return 0;
}
