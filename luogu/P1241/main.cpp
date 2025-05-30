#include <bits/stdc++.h>
using namespace std;



#define ALL(x) (x).begin(), (x).end()
#define MAXV(a, l, r) *std::max_element((a).begin() + (l), (a).begin() + (r))
#define MINV(a, l, r) *std::min_element((a).begin() + (l), (a).begin() + (r))



using ll = long long int;
using ull = unsigned long long int;
using PII = pair<int,int>;

#define DEBUG
#ifdef DEBUG
template<typename Container>
void PrintCon(const Container& cont) {
    std::cout << "{ ";
    if (!cont.empty()) {
        auto it = cont.begin();
        std::cout <<"\033[33m"<< *it++<< "\033[0m";
        for (; it != cont.end(); ++it)
            std::cout << " | " <<"\033[33m"<< *it<< "\033[0m";
    }
    std::cout << " }" << std::endl;
}

template<typename... Args>
void LOG(Args&&... values) {
    ((std::cout <<"\033[33m"<< std::forward<Args>(values) << "\033[0m"<< " "), ...);
    std::cout << std::endl;
}

#else

template<typename ...Args>
void LOG(Args& ...args);
template<typename Container>
void PrintCon(const Container& cont);

#endif


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
string s;
    cin >> s;
    stack<pair<char, int>> stk;
    vector<bool> matched(s.size(), false);
    
    for (int i = 0; i < s.size(); ++i) {
        char c = s[i];
        if (c == '(' || c == '[') {
            stk.push({c, i});
        } else {
            if (!stk.empty()) {
                auto top = stk.top();
                if ((c == ')' && top.first == '(') || (c == ']' && top.first == '[')) {
                    matched[i] = true;
                    matched[top.second] = true;
                    stk.pop();
                }
            }
        }
    }
    
    string res;
    for (int i = 0; i < s.size(); ++i) {
        if (!matched[i]) {
            if (s[i] == '(' || s[i] == '[') {
                res += s[i];
                res += (s[i] == '(' ? ')' : ']');
            } else {
                res += (s[i] == ')' ? '(' : '[');
                res += s[i];
            }
        } else {
            res += s[i];
        }
    }
    
    cout << res << endl;
    return 0;
}
