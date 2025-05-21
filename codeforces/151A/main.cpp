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

  int n, k, l, c, d, p, nl, np;
  scanf("%d%d%d%d%d%d%d%d", &n, &k, &l, &c, &d, &p, &nl, &np);
  int x = k * l / nl;
  int y = c * d;
  int z = p / np;
  int ans = fmin(fmin(x, y), z);
  printf("%d\n", ans / n);

  return 0;
}
