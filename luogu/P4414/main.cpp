#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
#define LOG(a) std::cout << "[" << #a << ":" << (a) << "]" << std::endl;
int a[4];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 0; i < 3; i++) {
        cin >> a[i];
    }
    string s;
    cin >> s;
    sort(a, a + 3);
    unordered_map<char,int> m;
    m.insert({'A',a[0]});
    m.insert({'B',a[1]});
    m.insert({'C',a[2]});
    for(auto ch:s){
            cout<<m[ch]<<' ';
    }
    return 0;
}
