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
string f()
{
    string s1="",s2;
    char ch;
    while(cin>>ch)
    {
        if(ch=='\n')break;
        if(ch=='[')
        {
            int t;
            scanf("%d",&t);
            s2=f();
            while(t--)s1+=s2; 
        }
        else if(ch==']')return s1;
        else s1+=ch;
    }
}
int main()
{
    cout<<f();
    return 0;
}
