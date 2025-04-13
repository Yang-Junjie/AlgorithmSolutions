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
struct pe {
    string name;
    int y;
    int m;
    int d;
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pe> s(n);
    for (auto& i : s) {
        cin >> i.name >> i.y >> i.m >> i.d;
    }
    reverse(s.begin(), s.end());
    stable_sort(s.begin(), s.end(), [](const pe& s1, const pe& s2) {
        if (s1.y != s2.y) {
            return s1.y < s2.y;
        } else if (s1.m != s2.m) {
            return s1.m < s2.m;
        } else if (s1.d != s2.d) {
            return s1.d < s2.d;
        }
   
        return false; });
    for (auto& i : s) {
        cout << i.name << endl;
    }
    return 0;
}
