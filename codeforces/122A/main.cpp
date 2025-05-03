#include <bits/stdc++.h>
using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define MAXV(a, l, r) *std::max_element((a).begin() + (l), (a).begin() + (r))
#define MINV(a, l, r) *std::min_element((a).begin() + (l), (a).begin() + (r))

using ll = long long int;
using ull = unsigned long long int;
using PII = pair<int, int>;

#define DEBUG
#ifdef DEBUG
template <typename Container>
void PrintCon(const Container& cont)
{
    std::cout << "{ ";
    if (!cont.empty()) {
        auto it = cont.begin();
        std::cout << "\033[33m" << *it++ << "\033[0m";
        for (; it != cont.end(); ++it)
            std::cout << " | " << "\033[33m" << *it << "\033[0m";
    }
    std::cout << " }" << std::endl;
}

template <typename... Args>
void LOG(Args&&... values)
{
    ((std::cout << "\033[33m" << std::forward<Args>(values) << "\033[0m" << " "), ...);
    std::cout << std::endl;
}

#else

template <typename... Args>
void LOG(Args&... args);
template <typename Container>
void PrintCon(const Container& cont);

#endif

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    bool is_ans = true;
    for (auto i : s) {
        if (!(i == '4' || i == '7')) {
            is_ans = false;
        }
    }
    if (is_ans) {
        cout << "YES" << endl;
    } else {
        int num = stoi(s);
        if (num % 4 == 0 || num % 7 == 0 || num % 44 == 0 || num % 47 == 0 || num % 74 == 0 || num % 77 == 0 || num % 444 == 0 || num % 447 == 0 || num % 474 == 0 || num % 477 == 0 || num % 744 == 0 || num % 747 == 0 || num % 774 == 0 || num % 777 == 0) {
            is_ans = true;
        } else {
            is_ans = false;
        }
        cout << (is_ans ? "YES" : "NO") << endl;
    }
    return 0;
}
