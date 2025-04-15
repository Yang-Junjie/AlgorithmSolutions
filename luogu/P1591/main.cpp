#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <numeric>
using namespace std;
#define LOG(a) std::cout << "[" << #a << ":" << (a) << "]" << std::endl;
using i64 = long long int;
using u64 = unsigned long long int;
using u32 = unsigned int;
using PII = pair<int, int>;

void mul(vector<int> &a, int k)
{
    int g = 0;
    for (int i = 0; i < a.size(); i++)
    {
        a[i] = a[i] * k + g;
        g = a[i] / 10;
        a[i] %= 10;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        int m;
        cin >> s >> m;
        reverse(s.begin(), s.end());
        vector<int> a(5000, 0); 
        for (int i = 0; i < s.size(); i++)
            a[i] = s[i] - '0';
        reverse(s.begin(), s.end());
        //求阶乘
        for(int i = stoi(s)-1;i>=1;i--){
            mul(a, i);
        }
        
        int cnt = 0;
        bool flag = false;
        for (int i = a.size() - 1; i >= 0; i--) 
        {
            if (a[i] != 0)
            {
                flag = true;
            }
            if (flag)
            {
                if(a[i]==m)cnt++;
            }
        }
        cout << cnt<<endl;
    }

    return 0;
}
