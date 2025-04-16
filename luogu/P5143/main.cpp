#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <numeric>
#include <cmath>
#include <iomanip>
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
struct Vec3{
    double x,y,z;
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<Vec3> a(n);
    for(int i =0;i<n;i++){
        cin>>a[i].x>>a[i].y>>a[i].z;
    }
    sort(All(a),[](Vec3 a,Vec3 b){
        return a.z<b.z;
    });
    double nx=a[0].x,ny=a[0].y,nz=a[0].z;
    double ans = 0;
    for(int i = 1;i<n;i++){
        ans+=sqrt((nx-a[i].x)*(nx-a[i].x)+(ny-a[i].y)*(ny-a[i].y)+(nz-a[i].z)*(nz-a[i].z));
         nx=a[i].x,ny=a[i].y,nz=a[i].z;
    }
    
    cout<<setprecision(3)<<fixed<<ans<<endl;
    return 0;
}
