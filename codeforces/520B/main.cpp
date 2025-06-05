#include <bits/stdc++.h>
#include <vector>
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
queue<int> q;
int n, m;
int cnt = 0;

vector<int> d(1e6 + 10, 0);
void bfs(int x, int y)
{
    vector<bool> vis(1e6 + 10, false);
    q.push(x);
    while (!q.empty()) {
        int start = q.front();
        q.pop();

        if (start == y) {
            return;
        }
        int n_num1 = start * 2;
        int n_num2 = start - 1;
        if (n_num1 >= 0 && n_num1 < 10005 && !vis[n_num1]) {
            cnt++;
            vis[n_num1] = true;
            d[n_num1] = d[start] + 1;
            q.push(n_num1);
        }
        if (n_num2 >= 0 && n_num2 < 10005 && !vis[n_num2]) {
            cnt++;
            vis[n_num2] = true;
            d[n_num2] = d[start] + 1;
            q.push(n_num2);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    bfs(n, m);
    cout << d[m] << endl;
    return 0;
}