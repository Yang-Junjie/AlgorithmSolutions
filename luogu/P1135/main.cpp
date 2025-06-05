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
void PrintCon(const Container &cont)
{
    std::cout << "{ ";
    if (!cont.empty())
    {
        auto it = cont.begin();
        std::cout << "\033[33m" << *it++ << "\033[0m";
        for (; it != cont.end(); ++it)
            std::cout << " | " << "\033[33m" << *it << "\033[0m";
    }
    std::cout << " }" << std::endl;
}

template <typename... Args>
void LOG(Args &&...values)
{
    ((std::cout << "\033[33m" << std::forward<Args>(values) << "\033[0m" << " "), ...);
    std::cout << std::endl;
}

#else

template <typename... Args>
void LOG(Args &...args);
template <typename Container>
void PrintCon(const Container &cont);

#endif

void bfs(int a, int b, int n, vector<int>& k) {
    queue<int> q;
    vector<bool> vis(n + 1, false);
    vector<int> d(n + 1, 0);
    
    q.push(a);
    vis[a] = true;
    d[a] = 0;
    
    while (!q.empty()) {
        int start = q.front();
        q.pop();
        
        if (start == b) {
            cout << d[b] << endl;
            return;
        }
        
        int new_point1 = start + k[start];
        int new_point2 = start - k[start];
        
        if (new_point1 > 0 && new_point1 <= n && !vis[new_point1]) {
            vis[new_point1] = true;
            d[new_point1] = d[start] + 1;
            q.push(new_point1);
        }
        if (new_point2 > 0 && new_point2 <= n && !vis[new_point2]) {
            vis[new_point2] = true;
            d[new_point2] = d[start] + 1;
            q.push(new_point2);
        }
    }
    cout << -1 << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a, b;
    cin >> n >> a >> b;

    vector<int> k(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
    }
    
    bfs(a, b, n, k);
    return 0;
}