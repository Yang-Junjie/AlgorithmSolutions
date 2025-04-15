#include <algorithm>
#include <ios>
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
struct Studen {
    string name;
    int ch;
    int math;
    int eng;
    int tat;
};

bool cmp(const Studen& s1, const Studen& s2)
{
    if (abs(s1.ch - s2.ch) <= 5 && abs(s1.math - s2.math) <= 5 && abs(s1.eng - s2.eng) <= 5 && abs(s1.tat - s2.tat) <= 10) {
        return true;
    } else {
        return false;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<Studen> st;
    while (n--) {
        Studen tmp;
        cin >> tmp.name >> tmp.ch >> tmp.math >> tmp.eng;
        tmp.tat = tmp.math + tmp.ch + tmp.eng;
        st.push_back(tmp);
    }
    for (int i = 0; i < st.size() - 1; i++) {
        for (int j = i + 1; j < st.size(); j++) {
            if (cmp(st[i], st[j])) {
                string s1,s2;
                s1 = min(st[i].name,st[j].name);
                s2 = max(st[i].name,st[j].name);
                cout <<  s1<< ' ' <<s2 << endl;
            }
        }
    }
    return 0;
}
