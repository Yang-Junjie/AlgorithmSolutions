#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>
#include <string>
#include <utility>
#include <vector>
using namespace std;
#define LOG(a) std::cout << "[" << #a << ":" << (a) << "]" << std::endl;
using i64 = long long int;
using u64 = unsigned long long int;
using u32 = unsigned int;
using PII = pair<int, int>;
const int N = 1e5 + 10;
int n, x;
vector<vector<int>> d(N);
vector<int> a(N);
bool is_ans = false;
vector<bool> vis(N, false);
queue<int> q;

void bfs()
{
    q.push(x);
    vis[x] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i : d[u]) {
            if (vis[i]) {
                is_ans = true;
                return;
            }
            vis[i] = true;
            q.push(i);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; ++i) {
        int u = a[i];
        d[u].push_back(i);
    }
    bfs();
    cout << (is_ans ? "Yes":"No") << endl;
    return 0;
}
