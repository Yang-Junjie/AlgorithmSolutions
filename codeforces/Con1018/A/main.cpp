#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <numeric>
using namespace std;
#define DEBUG
#ifdef DEBUG
#define LOG1(a) cerr << "[" << #a << ":" << (a) << "]" << endl
#define LOG2(a,b) cerr << "[" << #a << ":" << (a) <<","<< #b << ":" << (b) << "]" << endl
template<typename Container>
void PrintCon(const Container& cont) {
    std::cout << "{ ";
    if (!cont.empty()) {
        auto it = cont.begin();
        std::cout <<"\033[33m"<< *it++<< "\033[0m";
        for (; it != cont.end(); ++it)
            std::cout << " | " << *it;
    }
    std::cout << " }" << std::endl;
}

#else
#define LOG(a)
#endif

#define LEN(a) ((int)(a).size())
#define ALL(x) (x).begin(), (x).end()
using ll = long long int;
using ull = unsigned long long int;
using PII = pair<int,int>;
using VI = vector<int>;

void solve(){
    int n;
    string s;
    cin >> n >> s;
    vector<int> ans;
    int cnt = 1;
    int maxm = n;
    for (int i = n - 2; i >= 0; --i) {
        if (s[i] == '<') {
            ans.push_back(cnt);
            cnt++;
        } else {
            ans.push_back(maxm);
            maxm--;
        }
    }
    ans.push_back(maxm);

    reverse(ans.begin(), ans.end());
    for (int i = 0; i < n; ++i) {
        cout << ans[i]<<' ';
    }
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}