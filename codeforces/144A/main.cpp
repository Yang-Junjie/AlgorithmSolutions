#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <numeric>
using namespace std;

#ifdef DEBUG
#define LOG(a) cerr << "[" << #a << ":" << (a) << "]" << endl
#else
#define LOG(a)
#endif

#define Len(a) ((int)(a).size())
#define All(x) (x).begin(), (x).end()
using ll = long long int;
using ull = unsigned long long int;
using PII = pair<int,int>;
using VI = vector<int>;
int a[101]; 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    int n;   
	int maxn=1,minn=1;   
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>a[maxn]) 
		{
			maxn=i; 
		}
		if(a[i]<=a[minn]) 
		{
			minn=i;   
		}
	}
	if(maxn<minn)
	{
		cout<<maxn-1+n-minn;  
	}
	else
	{
		cout<<maxn-1+n-minn-1;  
	}

    return 0;
}
