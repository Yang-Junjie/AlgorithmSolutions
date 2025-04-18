#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <numeric>
using namespace std;


#ifdef DEBUG
#define LOG1(a) cerr << "[" << #a << ":" << (a) << "]" << endl
#define LOG2(a,b) cerr << "[" << #a << ":" << (a) <<","<< #b << ":" << (b) << "]" << endl
template<typename Container>
void PrintCon(const Container& cont) {
    std::cout << "{ ";
    if (!cont.empty()) {
        auto it = cont.begin();
        std::cout <<"\033[33m"<< *it++<< "\033[0m";
        for (; it != cont.end(); ++it)
            std::cout << " | " << *it;
    }
    std::cout << " }" << std::endl;
}

#else
#define LOG(a)
#endif

#define LEN(a) ((int)(a).size())
#define ALL(x) (x).begin(), (x).end()
using ll = long long int;
using ull = unsigned long long int;
using PII = pair<int,int>;
using VI = vector<int>;
const int N = 1000;

int n,m,len=1;
int f[1005][1005];
void add(int x)
{
	for(int i=1;i<=len;i++)
	  f[x][i]=f[x-1][i]+f[x-2][i];
	for(int i=1;i<=len;i++)
	  if(f[x][i]>9)
	  {
	  	f[x][i+1]+=f[x][i]/10;
	  	f[x][i]%=10;
	  }
	if(f[x][len+1]) len++;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>m>>n;
    f[1][1]=1,f[2][1]=2;
    for(int i=3;i<=n-m;i++) add(i);
    for(int i=len;i;i--) printf("%d",f[n-m][i]);

    return 0;
}
