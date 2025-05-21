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
template <typename Container> void PrintCon(const Container &cont) {
  std::cout << "{ ";
  if (!cont.empty()) {
    auto it = cont.begin();
    std::cout << "\033[33m" << *it++ << "\033[0m";
    for (; it != cont.end(); ++it)
      std::cout << " | " << "\033[33m" << *it << "\033[0m";
  }
  std::cout << " }" << std::endl;
}

template <typename... Args> void LOG(Args &&...values) {
  ((std::cout << "\033[33m" << std::forward<Args>(values) << "\033[0m" << " "),
   ...);
  std::cout << std::endl;
}

#else

template <typename... Args> void LOG(Args &...args);
template <typename Container> void PrintCon(const Container &cont);

#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, a[1000000];
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  int l = 0, r = 0;
  int ans = 0, sum = 0;
  while (l < n) {
    while (r < n && sum + a[r] <= m)
      sum += a[r++];
    if (r == n) {
      ans = max(ans, r - l);
      break;
    }

    if (r == l) {
      l++, r++, sum = 0;
      continue;
    }
    ans = max(ans, r - l);
    sum -= a[l], l++;
  }
  cout << ans;

  return 0;
}
