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


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
	cin>>n;//卡牌个数
	int num1=0,num2=0;//两人得分
	int a[1002]; //存储卡牌上的数
	for(int i=1;i<=n;i++)  cin>>a[i];
	int l=1,r=n;
	int now=0;
	while(now<n)
	{
		now++;
		if(now%2==1)//应该第一个人得分
		{
			if(a[l]<a[r]) //右边大
			{
				num1+=a[r];
				r--;//移动下标
			}
			else//左边大
			{
				num1+=a[l];
				l++;
			}
		}
		else//应该第二个人得分
		{
			if(a[l]<a[r]) //右边大
			{
				num2+=a[r];
				r--;
			}
			else//左边大
			{
				num2+=a[l];
				l++;
			}	
		}
	}
	cout<<num1<<" "<<num2;
    

    return 0;
}
