
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
struct Data {
    double v;
    double w;
    double m;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    double n, v;
    cin >> n >> v;
    vector<Data> a(n);
    for (int i = 0; i < n; i++) {
        double s, c;
        cin >> s >> c;
        Data tmp;
        tmp.w = s;
        tmp.m = c;
        tmp.v = c / s;
        a[i]=tmp;
    }
    sort(ALL(a), [](Data a, Data b) {
        return a.v > b.v;
    });
    double ans = 0;
    for(auto i :a){
        if(v>=i.w){
            v-=i.w;
            ans+=i.m;
        }else{
            double value = v*i.v;
            ans+=value;
            v-=v;
        }
    }
    cout<<setprecision(2)<<fixed<<ans<<endl;
    return 0;
}
