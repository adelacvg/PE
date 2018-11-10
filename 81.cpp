#include<bits/stdc++.h>
using namespace std;
unsigned long long m[100][100],dp[100][100];
int main()
{
    fstream f;
    f.open("81(1).txt");
    for(int i=1;i<=80;i++)
    {
        for(int j=1;j<=80;j++)
        {
            f>>m[i][j];
        }
    }
    for(int i=1;i<=80;i++)
    {
        dp[1][i]=dp[1][i-1]+m[1][i];
        dp[i][1]=dp[i-1][1]+m[i][1];
    }
    /*
    for(int i=1;i<=5;i++)
    {
        for(int j=1;j<=5;j++)
        {
            cout<<dp[i][j]<<' ';
        }
        cout<<'\n';
    }
    */
    for(int i=2;i<=80;i++)
    {
        for(int j=2;j<=80;j++)
        {
            dp[i][j]=min(dp[i-1][j],dp[i][j-1])+m[i][j];
        }
    }
    cout<<dp[80][80];
}
