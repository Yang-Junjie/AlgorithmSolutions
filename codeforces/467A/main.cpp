#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int a, b, cnt = 0;
int main()
{
    int n;
    cin >> n;
    while (n--) {
        cin >> a >> b;
        if (b - a >= 2)
            cnt++;
    }
    cout << cnt;
    return 0;
}
