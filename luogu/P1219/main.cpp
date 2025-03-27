#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
const int N = 15;
int g[N], n;
bool col[N], ng[2*N], ung[2*N];
int cnt = 0;
void dfs(int u)
{
    if (u == n) {
        
        if(cnt<=2){
        for (int i = 0; i < n; i++)
            cout << g[i] << " ";
        cout<<'\n';
        }
        cnt++;
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!col[i] && !ng[i + u] && !ung[n - u + i]) {
            g[u] = i;
            col[i] = ng[i+u] = ung[n-u+i] = true;
            dfs(u + 1);
            col[i] = ng[i+u] = ung[n-u+i] = false;
        }
    }
}
int main()
{
    cin >> n;
    dfs(0);
    cout<<cnt;
    return 0;
}
