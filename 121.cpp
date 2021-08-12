#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull dp[1010];
int main()
{
    int n=15;
    dp[n+1]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            dp[j]=dp[j+1];
        dp[n+1]=0;
        for(int j=n+1;j>=1;j--)
            dp[j] += dp[j-1]*i;
    }
    ull ans=0;
    for(int i=1;i<=(n+1)/2;i++)
    {
        ans+=dp[i];
    }
    cout<<ans<<endl;
    ull x=1;
    for(int i=1;i<=n+1;i++)
    {
        x*=i;
    }
    cout<<x/ans<<endl;
}
