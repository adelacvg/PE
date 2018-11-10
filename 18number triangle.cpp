#include<cstdio>
#include<iostream>
#include<fstream>
using namespace std;
int dp[100][100];
int main()
{
    fstream f;
    f.open("18.txt");
    for(int i=1;i<=15;i++)
    {
        for(int j=1;j<=i;j++)
        {
            f>>dp[i][j];
        }
    }
    for(int i=15;i>=1;i--)
    {
        for(int j=1;j<i;j++)
        {
            dp[i-1][j]+=max(dp[i][j],dp[i][j+1]);
        }
    }
    cout<<dp[1][1];
}
