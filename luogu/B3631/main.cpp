#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int e[N];
int index = 1;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    e[1] = 0;
    for (int i = 1; i <= n; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            int x, y;
            cin >> x >> y;
            e[y] = e[x];
            e[x] = y;
        } else if (op == 2) {
            int x;
            cin >> x;
            cout <<(e[x]?e[x]:0)<< endl;
        } else if (op == 3) {
            int x;
            cin >> x;
            if(e[x]!=0)
            e[x] = e[e[x]];
        }
    }

    return 0;
}
