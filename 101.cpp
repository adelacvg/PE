#include<bits/stdc++.h>
using namespace std;
long long y(long long n)
{
    long long x=n*n*n;
    return 1+(n-1)*(n+x+x*n*n+x*x*n+x*x*x);
}
long long P(long long n)
{
    long long res=0;
    for(long long i=1;i<=n;i++)
    {
    
        long long tmp1=1,tmp2=1;
        for(long long j=1;j<=n;j++)
        {
            if(i==j)
            {
                continue;
            }
            else
            {
                tmp1*=n+1-j;
                tmp2*=i-j;
            }
        }
            res+=tmp1*y(i)/tmp2;
    }
    return res;
}
int main()
{
    long long ans=0;
    for(int i=1;i<=10;i++)
    {
        ans+=P(i);
    }
    cout<<ans<<endl;
}
