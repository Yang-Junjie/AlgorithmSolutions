#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int t[5], a[5][25], ans = 0;
int main()
{
    for (int i = 1; i <= 4; i++)
        cin >> t[i];
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= t[i]; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= t[i]; j++) {
            if (t[i] >= 2) {
                ans += *max_element(a[i] + 1, a[i] + t[i] + 1);
            } else {
                int the_first_max = -1, index_first_max;
                for (int k = 1; k <= t[i]; k++) {
                    if (a[i][k] > the_first_max) {
                        the_first_max = a[i][k];
                        index_first_max = k;
                    }
                }
                int the_sec_max = -1, index_sec_max;
                a[i][index_first_max] = 0;
                for (int k = 1; k <= t[i]; k++) {
                    if (a[i][k] > the_first_max) {
                        the_first_max = a[i][k];
                        index_first_max = k;
                    }
                }
                a[i][index_sec_max] = 0;
                a[i][index_first_max] = the_first_max - the_sec_max;
            }
        }
    }
    cout << ans;

    return 0;
}
