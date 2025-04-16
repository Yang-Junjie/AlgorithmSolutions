#include <iostream>
#include <vector>
using namespace std;

void used(vector<int>& vis, int num) {
    vis[num / 100]++;
    vis[(num / 10) % 10]++;
    vis[num % 10]++;
}

int main() {
    vector<int> vis(10);
    for (int i = 1; i <= 9; ++i) {
        for (int j = 1; j <= 9; ++j) {
            if (i == j) continue;
            for (int k = 1; k <= 9; ++k) {
                if (i == k || j == k) continue;
                int num = i * 100 + j * 10 + k;
                int a = num * 2;
                int b = num * 3;
                used(vis,num);
                used(vis,a);
                used(vis,b);
                if(vis[1]==1&&vis[2]==1&&vis[3]==1&&vis[4]==1&&vis[5]==1&&vis[6]==1&&vis[7]==1&&vis[8]==1&&vis[9]==1){//如果这3个创造出来的数满足每一位都被使用且只用1次，输出
                    cout<<num<<" "<<a<<" "<<b<<endl;
                }
                for(int q =  0;q<=9;q++){
                    vis[q] = false;
                }
            }
        }
    }
    return 0;
}