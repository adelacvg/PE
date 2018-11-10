#include<bits/stdc++.h>
using namespace std;
int dp[110][110];

int main()
{
    for(int i=1;i<=100;i++)
    {
        dp[i][0]=1;
        dp[1][i]=1;
    }
    for(int i=2;i<=99;i++)
    {
        for(int j=1;j<=100;j++)
        {
            for(int k=0;k<=j/i;k++)
            {
                dp[i][j] += dp[i-1][j-i*k];
            }
        }
    }
    /*
    for(int i=1;i<=10;i++)
    {
        for(int j=1;j<=100;j++)
        {
            cout<<dp[i][j]<<' ';
        }
        cout<<'\n';
    }
    */
    cout<<dp[99][100];
}
