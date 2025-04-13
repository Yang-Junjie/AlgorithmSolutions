#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <utility>
#include <vector>
using namespace std;
#define LOG(a) std::cout << "[" << #a << ":" << (a) << "]" << std::endl;
using i64 = long long int;
using u64 = unsigned long long int;
using u32 = unsigned int;
using PII = pair<int, int>;

struct St {
    string name;
    int ch;
    int ma;
    int en;
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<St> sts(n);
    for (auto& i : sts) {
        cin >> i.name >> i.ch >> i.ma >> i.en;
    }
    sort(sts.begin(), sts.end(), [](const St& a, const St& b) {
        int sum1 = a.ch + a.en + a.ma;
        int sum2 = b.ch + b.en + b.ma;
        if (sum1 != sum2) {
            return sum1 > sum2;
        } 
            return false;
        
    });
        cout<<sts[0].name<<' '<<sts[0].ch<<' '<<sts[0].ma<<' '<<sts[0].en<<endl;
    return 0;
}
