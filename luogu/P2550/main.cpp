#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int a[10];
int b[10];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= 7; i++)
        cin >> a[i];
    while (n--) {
        int cnt = 0;
        for (int i = 1; i <= 7; i++) {
            int tmp;
            cin >> tmp;
            for (int j = 1; j <= 7; j++) {
                if (tmp == a[j])
                    cnt++;
            }
        }
        switch (cnt) {
        case 7:
            b[1]++;
            break;
        case 6:
            b[2]++;
            break;
        case 5:
            b[3]++;
            break;
        case 4:
            b[4]++;
            break;
        case 3:
            b[5]++;
            break;
        case 2:
            b[6]++;
            break;
        case 1:
            b[7]++;
            break;
        default:
            b[0]++;
        }
    }
    for (int i = 1; i <= 7; i++) {
        cout << b[i] << ' ';
    }
    return 0;
}
