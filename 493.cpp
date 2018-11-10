#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;

ull c(int n,int m)
{
    ull ans=1;
    for(int i=1;i<=n-m;i++)
    {
        ans=ans*(m+i)/i;
    }
    return ans;
}

int main()
{
    double ans;
    ans=7*(1-1.0*c(60,20)/c(70,20));
    cout<<fixed<<setprecision(9)<<ans;
}
