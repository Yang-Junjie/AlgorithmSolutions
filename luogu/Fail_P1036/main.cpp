#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
const int N = 25;
int x[N], k, n, sum = 0, cnt = 0;
bool vis[N];
int q[N];
bool isPrime(int num)
{
    if (num <= 2)
        return false;
    for (int i = 3; i * i <= num; i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}
void dfs(int u)
{
    if (u == k) {
        for (int i = 0; i < k; i++)
            cout<<q[i];
        cout<<'\n';
       // cout << sum << '\n';
        // if (isPrime(sum))
        //    cnt++;
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            q[u] = x[i];
            if (u == 0)
                vis[i] = true;
            dfs(u + 1);
        }
    }
}
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> x[i];
    dfs(0);
    //  cout<<cnt;
    return 0;
}
