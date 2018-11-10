#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
vector<int> flag(1000010,0),p;
int dp[10000];
int main()
{
    for(ull i=2;i<=1000000;i++)
    {
        if(!flag[i])
        {
            p.push_back(i);
            for(ull j=i*i;j<=1000000;j+=i)
            {
                flag[j]=1;
            }
        }
    }
    int n=1;
    while(1)
    {
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=0;i<p.size();i++)
        {
            for(int j=p[i];j<=n;j++)
            {
                dp[j]+=dp[j-p[i]];
            }
        }
        if(dp[n]>5000)
        {
            cout<<n;
            break;
        }
        n++;
    }
}
