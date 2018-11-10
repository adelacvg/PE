#include<bits/stdc++.h>
using namespace std;
int dp[10][220];
int v[8]={1,2,5,10,20,50,100,200};
int main()
{
    for(int i=0;i<=200;i++)
        dp[0][i]=1;
    for(int i=1;i<8;i++)
    {
        for(int j=0;j<=200;j++)
        {
            for(int k=0;k<=j/v[i];k++)
            {
                dp[i][j] += dp[i-1][j-v[i]*k];
            }
        }
    }
    for(int i=0;i<8;i++)
    {
        for(int j=1;j<=200;j++)
        {
            cout<<dp[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<dp[7][200];
}
