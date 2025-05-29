#include <bits/stdc++.h>
#include <limits>
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
int n, w[4], f[4010];

int main()
{
    cin >> n;
    for (int i = 1; i <= 3; i++)
        cin >> w[i];
    memset(f, -1, sizeof(f));
    f[0] = 0;
    for (int i = 1; i <= 3; i++)
        for (int j = w[i]; j <= n; j++) {
            if (f[j - w[i]] != -1)
                f[j] = max(f[j], f[j - w[i]] + 1);
        }
    cout << f[n] << endl;
    return 0;
}
