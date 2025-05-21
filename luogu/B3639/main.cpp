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
  int n, m;
  cin >> n >> m;
  vector<bool> a(n, false);
  while (m--) {
    int x;
    cin >> x;
    x--;
    if (x == 0) {
      a[0] = !a[0];
      a[1] = !a[1];
      a[n - 1] = !a[n - 1];
    } else if (x == n - 1) {
      a[n - 1] = !a[n - 1];
      a[n - 2] = !a[n - 2];
      a[0] = !a[0];
    } else {
      a[x] = !a[x];
      a[x + 1] = !a[x + 1];
      a[x - 1] = !a[x - 1];
    }
  }
  for (auto i : a) {
    cout << i << ' ';
  }
  cout << endl;

  return 0;
}
