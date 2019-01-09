//A005230 & A005318 根据左面的两个数列可以得出答案，但是我摸了
//没有写正解，以下是一个接近的构造算法，不一定得到的是最优解。
#include<bits/stdc++.h>
using  namespace std;

int dp[10010][10010];
int main()
{
    dp[0][0]=1;
    for(int i=1;i<=100;i++)
    {
        dp[i][0]=dp[i-1][(i-1)/2];
        for(int j=1;j<i;j++)
            dp[i][j]=dp[i][0]+dp[i-1][j-1];
    }
    for(int i=1;i<=12;i++)
    {
        for(int j=0;j<i;j++)
        {
            cout<<dp[i][j]<<" ";

        }
        cout<<endl;
    }
}
