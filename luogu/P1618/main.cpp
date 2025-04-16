#include <iostream>
#include <vector>
using namespace std;

void used(vector<int> &vis, int num)
{
    vis[num / 100]++;
    vis[(num / 10) % 10]++;
    vis[num % 10]++;
}

int main()
{
    vector<int> vis(10);
    int r, t, l;
    cin >> r >> t >> l;
    int cnt = 0;
    for (int i = 1; i <= 1000; ++i)
    {
        int num = i*r;
        int a = i*t;
        int b =i*l;
        if(a>999||b>999){
            break;
        }
        used(vis, num);
        used(vis, a);
        used(vis, b);
        if (vis[1] == 1 && vis[2] == 1 && vis[3] == 1 && vis[4] == 1 && vis[5] == 1 && vis[6] == 1 && vis[7] == 1 && vis[8] == 1 && vis[9] == 1)
        {
            cnt++;
            cout << num << " " << a << " " << b << endl;
        }
        for (int q = 0; q <= 9; q++)
        {
            vis[q] = false;
        }
    }
    if(cnt==0){
        cout<<"No!!!"<<endl;
    }

    return 0;
}