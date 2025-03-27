#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int q[10];
bool vis[10];
void dfs(int u ){
    if(u == 8){
        for(int i = 0;i<8;i++){
            cout<<q[i]<<' ';
        }
        cout<<endl;
        return;
    }
    for(int i = 1;i<=8;i++){
        if(!vis[i]){
            q[u]= i;
            vis[i] = true;
            dfs(u+1);
            vis[i] = false;
        }

    }
}
int main()
{
    dfs(0);
    return 0;
}
