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
double a, b, c, d;
double f(double x)
{
    return a * x * x * x + b * x * x + c * x + d;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> a >> b >> c >> d;
    vector<double> roots;
    
    for (int i = -100; i < 100; i++) {
        double x1 = i, x2 = i + 1;
        if (f(x1) == 0) { 
            roots.push_back(x1);
            continue;
        }
        if (f(x1) * f(x2) >= 0) continue; 
        
       
        while (x2 - x1 > 1e-9) {
            double mid = (x1 + x2) / 2;
            if (f(mid) * f(x1) > 0) {
                x1 = mid;
            } else {
                x2 = mid;
            }
        }
        double root = (x1 + x2) / 2;
        roots.push_back(root);
    }
    
    
    sort(roots.begin(), roots.end());
    for (double r : roots) {
        cout << fixed << setprecision(2) << r << " ";
    }
    return 0;
}