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
  string s;
  cin >> s;
  int x;
  cin >> x;
  vector<int> f(1000000000, 0);
  for (int i = 0; i < s.size(); i++) {
    bool flag = (s[i] == s[i + 1]);
    f[i + 1] = f[i] + flag;
  }

  while (x--) {
    int l, r;
    cin >> l >> r;
    cout << f[r - 1] - f[l - 1] << endl;
  }

  return 0;
}
