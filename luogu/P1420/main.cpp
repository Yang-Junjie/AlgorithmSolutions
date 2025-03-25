#include<iostream>
using namespace std;
int main()
{
    int n,ans=0,temp,b,max=1;  
    cin>>n;
    cin>>b;                
    for(int i=1;i<=n-1;i++)
    {
        cin>>temp;
        if(temp==b+1) max++;    
        else max=1;             
        if(ans<max) ans=max;    
        b=temp;                 
    }
    cout<<ans;
return 0;
}
