#include <bits/stdc++.h>
using namespace std;


#define ALL(x) (x).begin(), (x).end()
#define MAXV(a, l, r) *std::max_element((a).begin() + (l), (a).begin() + (r))
#define MINV(a, l, r) *std::min_element((a).begin() + (l), (a).begin() + (r))


using ll = long long int;
using ull = unsigned long long int;
using PII = pair<int,int>;

#define DEBUG

#ifdef DEBUG
template<typename Container>
void PrintCon(const Container& cont) {
    std::cout << "{ ";
    if (!cont.empty()) {
        auto it = cont.begin();
        std::cout <<"\033[33m"<< *it++<< "\033[0m";
        for (; it != cont.end(); ++it)
            std::cout << " | " <<"\033[33m"<< *it<< "\033[0m";
    }
    std::cout << " }" << std::endl;
}

template<typename... Args>
void LOG(Args&&... values) {
    ((std::cout <<"\033[33m"<< std::forward<Args>(values) << "\033[0m"<< " "), ...);
    std::cout << std::endl;
}
#else
template<typename ...Args>
void LOG(Args& ...args);
    
template<typename Container>
void PrintCon(const Container& cont);
#endif

int split(ll n,ll x){
    for(int i = x+1;i<=sqrt(n);i++){
      if(n%i==0){
        return i;
      }
    }
    return -1;
}

void solve(){
int n = 0; cin >> n;
	int cnt1 = split (n, 1);
	if (cnt1 == -1) {
		cout << "NO" << endl;
		return;
	}
	n /= cnt1;
	int cnt2 = split (n, cnt1);
	if (cnt2 == -1) {
		cout << "NO" << endl;
		return;
	}
	n /= cnt2;
	if (cnt2 == n) {
		cout << "NO" << endl;
		return;
	}
	cout << "YES" << endl << cnt1 << " " << cnt2 << " " << n << endl;
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
